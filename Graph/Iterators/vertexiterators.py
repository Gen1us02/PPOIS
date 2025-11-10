"""
    Модуль, реализующий итнраторы по вершинам графа
"""
from Graph.Iterators.baseiterator import BaseIterator
from typing import TypeVar, List, Self, Any
from Graph.vertex import Vertex

T = TypeVar("T")


class BiDirectionalVertexIterator(BaseIterator[Vertex[T]]):
    """
    Двунаправленный итератор для обхода списка вершин графа.
    
    Итератор поддерживает движение как в прямом, так и в обратном направлении
    по коллекции вершин графа.
    
    Generic Parameters:
        T: Тип значений, хранящихся в вершинах графа.
    
    Attributes:
        _collection: Коллекция вершин для итерации.
        _reverse: Флаг направления итерации (True - обратное, False - прямое).
        _curr_index: Текущий индекс в коллекции.
        _max_index: Максимальный допустимый индекс в коллекции.
    """
    
    def __init__(self, collection: List[Vertex[T]], reverse: bool = False) -> None:
        """
        Инициализирует двунаправленный итератор вершин.
        
        Args:
            collection: Список вершин для итерации.
            reverse: Если True, итерация начинается с конца коллекции. По умолчанию False.
        """
        self._collection: List[Vertex[T]] = collection
        self._reverse: bool = reverse
        self._curr_index: int = 0 if not reverse else len(collection) - 1
        self._max_index: int = len(collection) - 1
        
    @property
    def index(self) -> int:
        """
        Возвращает текущий индекс итератора.
        
        Returns:
            Текущий индекс в коллекции вершин.
        """
        return self._curr_index
    
    @index.setter
    def index(self, new_index: int) -> None:
        """
        Устанавливает новый текущий индекс итератора.
        
        Args:
            new_index: Новый индекс для установки.
        """
        self._curr_index = new_index
        
    def __set_curr_index(self, index) -> None:
        """Изменяет _curr_index

        Args:
            index (int): Новый индекс
        """
        object.__setattr__(self, "_curr_index", index)
        
    def __iter__(self) -> Self:
        """
        Возвращает сам итератор.
        
        Returns:
            Текущий экземпляр итератора.
        """
        return self
    
    def __next__(self) -> Vertex[T]:
        """
        Возвращает следующую вершину и перемещает итератор вперёд.
        
        Returns:
            Следующая вершина в коллекции.
            
        Raises:
            StopIteration: Когда достигнут конец коллекции.
        """
        if not (0 <= self._curr_index <= self._max_index):
            raise StopIteration("Index out of range")
        
        current = self.current()
        new_index = self._curr_index + (1 if not self._reverse else -1)
        self.__set_curr_index(new_index)
        return current
    
    def previous(self) -> Vertex[T]:
        """
        Возвращает текущую вершину и перемещает итератор назад.
        
        Returns:
            Текущая вершина в коллекции.
            
        Raises:
            StopIteration: Когда достигнуто начало коллекции.
        """
        if not (0 <= self._curr_index <= self._max_index):
            raise StopIteration("Index out of range")
        
        current = self._collection[self._curr_index]
        new_index = self._curr_index + (-1 if not self._reverse else 1)
        self.__set_curr_index(new_index)
        return current
    
    def current(self) -> Vertex[T]:
        """
        Возвращает текущую вершину без перемещения итератора.
        
        Returns:
            Текущая вершина в коллекции.
        """
        return self._collection[self._curr_index]
    
    
class ConstBiDirectionalVertexIterator(BiDirectionalVertexIterator[T]):
    """
    Неизменяемая версия двунаправленного итератора вершин.
    
    Предоставляет тот же функционал, что и BiDirectionalVertexIterator, но запрещает
    модификацию атрибутов после инициализации.
    """
    
    __slots__ = ()
    
    def __init__(self, collection: List[Vertex[T]], reverse: bool = False) -> None:
        """
        Инициализирует неизменяемый итератор с использованием object.__setattr__.
        
        Args:
            collection: Список вершин для итерации.
            reverse: Если True, итерация начинается с конца коллекции. По умолчанию False.
        """
        object.__setattr__(self, "_collection", collection)
        object.__setattr__(self, "_reverse", reverse)
        object.__setattr__(self, "_curr_index", 0 if not reverse else len(collection) - 1)
        object.__setattr__(self, "_max_index", len(collection) - 1)
        
    def __iter__(self):
        """
        Возвращает новый экземпляр неизменяемого итератора.
        
        Returns:
            Новый ConstBiDirectionalVertexIterator с теми же параметрами.
        """
        return ConstBiDirectionalVertexIterator[T](self._collection, self._reverse)
    
    def __setattr__(self, name: str, value: Any) -> None:
        """
        Запрещает модификацию атрибутов итератора.
        
        Args:
            name: Имя атрибута.
            value: Значение для установки.
            
        Raises:
            AttributeError: Всегда, при попытке установить атрибут.
        """
        raise AttributeError("Can't modify const iterator")