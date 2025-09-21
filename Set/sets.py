"""
    Модуль представляет собой реализацию класса множество и всех присущих ему свойств
"""
from typing import List
from Set import utils


class Set:
    """
        Класс, реализующий множество и его свойства и операции
    """
    def __init__(self, set_string: str) -> None:
        """Конструктор класса Set, инициализирующий объект класса

        Аргументы:
            set_string (str): Строка, которую конструктор переводит в список элементов
            conventor (Conventor): Объект класса Conventor, реализующий перевод строки в список и обратно
            validator (Validator): Объект класса Validator, проверяющий валидность элементов и самого множества
        """
        sorted_set = utils.sort_set(set_string)
        self.__set: List[str] = utils.convert_to_list(sorted_set)
    
    def add(self, elem: str) -> bool:
        """Метод служит для добавления элемента в множество

        Аргументы:
            elem (str): Входящий элемент, который пользователь хочет добавить
            
        Возвращаемое значение:
            bool: Возвращаемое значение зависит от того добавился ли элемент в множества
        """
        elem = utils.sort_set(elem)
        if elem not in self.__set and utils.is_valid_elem(elem):
            self.__set.append(elem)
            return True
        
        return False
    
    def del_elem(self, elem: str) -> bool:
        """Метод для удаления элемента из множества

        Аргументы:
            elem (str): Элемент, который пользователь хочет удалить из множества

        Возвращаемое значение:
            bool: Возвращаемое значение зависит от того удалился ли элемент из множества
        """
        elem = utils.sort_set(elem)
        if elem in self.__set:
            self.__set.remove(elem)
            return True
        
        return False
            
    def is_empty(self) -> bool:
        """Метод проверяет множество на пустоту

        Возвращаемое значение:
            bool: Когда длинна множества равна 0, функция возвращает True
        """
        return len(self.__set) == 0
    
    def power(self) -> int:
        """Метод нужен для получения мощности множества

        Возвращаемое значение:
            int: Возвращается длинна множества
        """
        return len(self.__set)
    
    def boolean(self) -> str:
        """Метод для составления булеана множества

        Возвращаемое значение:
            str: Возвращается строковое представление булеана множества
        """
        result = [[]]
        for elem in self.__set:
            result += [subset + [elem] for subset in result]

        return "{" + ",".join("{" + ",".join(subset) + "}" for subset in result) + "}"
        
    def _union(self, second_set: List[str]) -> str:
        """Метод служит для создания объединения множеств

        Аргументы:
            second_set (List[str]): Второе множество, с которым производится операция объединения

        Возвращаемое значение:
            str: Возвращается строка объединения множеств
        """
        result = []
        result.extend(self.__set)
        result.extend(second_set)
        set_result = utils.remove_duplicates(result)
        return utils.convert_to_string(set_result)
    
    def _intesection(self, second_set: List[str]) -> str:
        """Метод служит для создания пересечения множеств

        Аргументы:
            second_set (List[str]): Второе множество, с которым производится операция пересечения

        Возвращаемое значение:
            str: Возвращается строковое представление пересечения множеств
        """
        result = []
        for elem in self.__set:
            found = False
            for second_elem in second_set:
                if elem == second_elem:
                    found = True
                    break
                
            if found:
                result.append(elem)
                
        return utils.convert_to_string(result)
    
    def _difference(self, second_set: List[str]) -> str:
        """Метод служит для создания разности множеств

        Аргументы:
            second_set (List[str]): Второе множество, с которым производится операция разности
            
        Возвращаемое значение:
            str: Возвращается строковое представление разности множеств
        """
        result = []
        for elem in self.__set:
            found = False
            for second_elem in second_set:
                if elem == second_elem:
                    found = True
                    break
                
            if not found:
                result.append(elem)
                
        return utils.convert_to_string(result)
        
    @property
    def set(self) -> str:
        """Геттер поля set

        Возвращаемое значение:
            str: Возвращает строковое представление множества
        """
        return self.__set
    
    @set.setter
    def set(self, value: str) -> None:
        """Сеттер поля set

        Аргументы:
            value (str): Передает строку, из которой формируется множество
        """
        self.__set = utils.convert_to_list(value)
        
    def __add__(self, other):
        """Магический метод add срабатывает при использовании операции + и 
        создает новый объект из объединения множеств

        Аргументы:
            other (Set): Объект класса Set, множество которого используется для объединения

        Возвращаемое значение:
            Set: Объект класса Set, у которого в поле set хранится объединение множеств
        """
        union_set_string = self._union(other.set)
        return Set(union_set_string)
    
    def __iadd__(self, other):
        """Магический метод iadd срабатывает при использовании оператора +=, не создает новый объект,
        а изменяет существующий

        Аргументы:
            other (Set): Объект класса Set, множество которого используется для объединения
        """
        union_set = self._union(other.set)
        self.__set = utils.convert_to_list(union_set)
        return self
    
    def __sub__(self, other):
        """Магический метод sub срабатывает при использовании оператора - и
        создает новый объект из разности множеств

        Аргументы:
            other (Set): Объект класса Set, множество которого используется для разности

        Возвращаемое значение:
            Set: Объект класса Set, у которого в поле set хранится разности множеств
        """
        differense_set_string = self._difference(other.set)
        return Set(differense_set_string)
    
    def __isub__(self, other):
        """Магический метод isub срабатывает при использовании оператора -=, не создает новый объект,
        а изменяет существующий

        Аргументы:
            other (Set): Объект класса Set, множество которого используется для разности
        """
        diff_set = self._difference(other.set)
        self.__set = utils.convert_to_list(diff_set)
        return self
    
    def __mul__(self, other):
        """Магический метод mul срабатывает при использовании оператора * и
        создает новый объект из пересечения множеств

        Аргументы:
            other (Set): Объект класса Set, множество которого используется для пересечения

        Возвращаемое значение:
            Set: Объект класса Set, у которого в поле set хранится пересечение множеств
        """
        intersection_set_string = self._intesection(other.set)
        return Set(intersection_set_string)
    
    def __imul__(self, other):
        """Магический метод isub срабатывает при использовании оператора *=, не создает новый объект,
        а изменяет существующий

        Аргументы:
            other (Set): Объект класса Set, множество которого используется для пересечения
        """
        inter_set = self._intesection(other.set)
        self.__set = utils.convert_to_list(inter_set)
        return self
    
    def __contains__(self, elem: str) -> bool:
        """Магический метод contains срабатывает при использовании оператора in 
        и проверяет пренадлежность элемента множеству

        Аргументы:
            elem (str): Элемент, который может содержаться в множестве

        Возвращаемое значение:
            bool: True если элемент находится в множестве, False иначе
        """
        elem = utils.sort_set(elem)
        return elem in self.__set
    
    def __str__(self) -> str:
        """Магический метод str срабатывает при выводе объекта класса на экран

        Возвращаемое значение:
            str: Возвращает строковое представление класса
        """
        return f"{utils.convert_to_string(self.__set)}"