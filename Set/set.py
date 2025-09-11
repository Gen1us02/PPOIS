from typing import List
from conventor import Conventor
from validator import Validator


class Set:
    def __init__(self, set_string: str, conventor: Conventor, validator: Validator) -> None:
        """Конструктор класса Set, инициализирующий объект класса

        Аргументы:
            set_string (str): Строка, которую конструктор переводит в список элементов
            conventor (Conventor): Объект класса Conventor, реализующий перевод строки в список и обратно
            validator (Validator): Объект класса Validator, проверяющий валидность элементов и самого множества
        """
        self.__set: List[str] = self._convert_to_list(set_string)
        self.__conventor = conventor
        self.__validator = validator
    
    def add(self, elem: str) -> None:
        """Метод служит для добавления элемента в множество

        Аргументы:
            elem (str): Входящий элемент, который пользователь хочет добавить
        """
        self.__set.append(elem)
    
    def del_elem(self, elem: str) -> bool:
        """Метод для удаления элемента из множества

        Аргументы:
            elem (str): Элемент, который пользователь хочет удалить из множества

        Возвращаемое значение:
            bool: Возвращаемое значение зависит от того удалился ли элемент из множества
        """
        if elem in self.__set and self.__validator.is_valid_elem(elem):
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

        Returns:
            int: Возвращается длинна множества
        """
        return len(self.__set)
    
    def boolean(self) -> str:
        """Метод для составления булеана множества

        Returns:
            str: _description_
        """
        result = [[]]
        for elem in self.__set:
            result = [subset + [elem] for subset in result]
        
        return self.__conventor.convert_to_string(result)
    
    @staticmethod
    def _remove_duplicates(collection: List[str]) -> List[str]:
        seen = set()
        for elem in collection:
            if elem not in seen:
                seen.add(elem)
                
        return list(seen)
        
    def _union(self, second_set: List[str]) -> str:
        result = []
        result.extend(self.__set)
        result.extand(second_set)
        set_result = self._remove_duplicates()
        return self.__conventor(set_result)
    
    def _intesection(self, second_set: List[str]) -> str:
        result = []
        for elem in self.__set:
            found = False
            for second_elem in second_set:
                if elem == second_elem:
                    found = True
                    break
                
            if found:
                result.append(elem)
                
        return self.__conventor.convert_to_string(result)
    
    def _difference(self, second_set: List[str]) -> str:
        result = []
        for elem in self.__set:
            found = False
            for second_elem in second_set:
                if elem == second_elem:
                    found = True
                    break
                
            if not found:
                result.append(elem)
                
        return self.__conventor.convert_to_string(result)
        
    @property
    def set(self) -> str:
        return self.__conventor.convert_to_string(self.__set)
    
    @set.setter
    def set(self, value: str) -> None:
        self.__set = self.__conventor.convert_to_list(value)
        
    def __add__(self, other):
        union_set_string = self._union(other.set)
        return Set(union_set_string)
    
    def __iadd__(self, other):
        self.__set = self._union(other.set)
    
    def __sub__(self, other):
        differense_set_string = self._difference(other.set)
        return Set(differense_set_string)
    
    def __isub__(self, other):
        self.__set = self._difference(other.set)
    
    def __mul__(self, other):
        intersection_set_string = self._intesection(other.set)
        return Set(intersection_set_string)
    
    def __imul__(self, other):
        self.__set = self._intesection(other.set)
    
    def __contains__(self, elem) -> bool:
        return elem in self.__set
    
    def __str__(self):
        return f"{self.__conventor.convert_to_string(self.__set)}"