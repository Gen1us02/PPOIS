"""
    Модуль, реализующий итераторы по ребрам
"""
from Graph.Iterators.baseiterator import BaseIterator
from typing import List, TypeVar, Tuple, Self, Any
from Graph.vertex import Vertex

T = TypeVar("T")


class BiDirectionalEdgeIterator(BaseIterator[Tuple[Vertex[T], Vertex[T]]]):
    """
    Двунаправленный итератор для обхода списка рёбер графа.
    
    Итератор поддерживает движение как в прямом, так и в обратном направлении
    по коллекции рёбер, представленных в виде кортежей (вершина, вершина).
    
    Generic Parameters:
        T: Тип значений, хранящихся в вершинах графа.
    
    Attributes:
        _collection: Коллекция рёбер для итерации.
        _reverse: Флаг направления итерации.
        _curr_index: Текущий индекс в коллекции.
        _max_index: Максимальный допустимый индекс в коллекции.
    """
    
    def __init__(self, collection: List[Tuple[Vertex[T], Vertex[T]]], reverse: bool = False) -> None:
        """
        Инициализирует двунаправленный итератор рёбер.
        
        Args:
            collection: Список рёбер в виде кортежей (вершина, вершина).
            reverse: Если True, итерация начинается с конца коллекции. По умолчанию False.
        """
        self._collection: List[Tuple[Vertex[T], Vertex[T]]] = collection
        self._reverse = reverse
        self._curr_index = 0 if not reverse else len(collection) - 1
        self._max_index = len(collection) - 1
        
    @property
    def index(self) -> int:
        """
        Возвращает текущий индекс итератора.
        
        Returns:
            Текущий индекс в коллекции.
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
        
    def __iter__(self) -> Self:
        """
        Возвращает сам итератор.
        
        Returns:
            Текущий экземпляр итератора.
        """
        return self
    
    def __set_curr_index(self, index) -> None:
        """Изменяет _curr_index

        Args:
            index (int): Новый индекс
        """
        object.__setattr__(self, "_curr_index", index)
    
    def __next__(self) -> Tuple[Vertex[T], Vertex[T]]:
        """
        Возвращает следующий элемент и перемещает итератор вперёд.
        
        Returns:
            Следующее ребро в виде кортежа (вершина, вершина).
            
        Raises:
            StopIteration: Когда достигнут конец коллекции.
        """
        if not (0 <= self._curr_index <= self._max_index):
            raise StopIteration("Index is out of range")
        
        value = self.current()
        new_index = self._curr_index + (1 if not self._reverse else -1)
        self.__set_curr_index(new_index)
        return value
    
    def previous(self) -> Tuple[Vertex[T], Vertex[T]]:
        """
        Возвращает текущий элемент и перемещает итератор назад.
        
        Returns:
            Текущее ребро в виде кортежа (вершина, вершина).
            
        Raises:
            StopIteration: Когда достигнуто начало коллекции.
        """
        if not (0 <= self._curr_index <= self._max_index):
            raise StopIteration("Index is out of range")
        
        value = self.current()
        new_index = self._curr_index + (-1 if not self._reverse else 1)
        self.__set_curr_index(new_index)
        return value
    
    def current(self) -> Tuple[Vertex[T], Vertex[T]]:
        """
        Возвращает текущий элемент без перемещения итератора.
        
        Returns:
            Текущее ребро в виде кортежа (вершина, вершина).
        """
        return self._collection[self._curr_index]
    

class ConstBiDirectionalEdgeIterator(BiDirectionalEdgeIterator[T]):
    """
    Неизменяемая версия двунаправленного итератора рёбер.
    
    Предоставляет тот же функционал, что и BiDirectionalEdgeIterator, но запрещает
    модификацию атрибутов после инициализации. Используется для безопасного доступа
    к данным в многопоточных средах или когда требуется гарантия неизменности.
    """
    
    __slots__ = ()
    
    def __init__(self, collection: List[Tuple[Vertex[T], Vertex[T]]], reverse: bool = False) -> None:
        """
        Инициализирует неизменяемый итератор с использованием object.__setattr__.
        
        Args:
            collection: Список рёбер в виде кортежей (вершина, вершина).
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
            Новый ConstBiDirectionalEdgeIterator с теми же параметрами.
        """
        return ConstBiDirectionalEdgeIterator[T](self._collection, self._reverse)
    
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