from baseiterator import BaseIterator
from typing import List, TypeVar, Tuple, Self, Any
from Graph.vertex import Vertex

T = TypeVar("T")

class BiDirectionalEdgeIterator(BaseIterator):
    def __init__(self, collection: List[Tuple[Vertex[T], Vertex[T]]], reverse: bool = False):
        self._collection: List[T] = collection
        self._reverse = reverse
        self._curr_index = 0 if not reverse else len(collection) - 1
        self._max_index = len(collection) - 1
        
    @property
    def index(self) -> int:
        return self._curr_index
    
    @index.setter
    def index(self, new_index: int) -> None:
        self._curr_index = new_index
        
    def __iter__(self) -> Self:
        return self
    
    def __next__(self) -> Tuple[Vertex[T], Vertex[T]]:
        if not (0 <= self._curr_index <= self._max_index):
            raise StopIteration("Index is out of range")
        
        value = self.current()
        self._curr_index = self._curr_index + (1 if not self._reverse else -1)
        return value
    
    def previous(self) -> Tuple[Vertex[T], Vertex[T]]:
        if not (0 <= self._curr_index <= self._max_index):
            raise StopIteration("Index is out of range")
        
        value = self.current()
        self._curr_index = self._curr_index + (-1 if not self._reverse else 1)
        return value
    
    def current(self) -> Tuple[Vertex[T], Vertex[T]]:
        return self._collection[self._curr_index]
    
class ConstBiDirectionalEdgeIterator(BiDirectionalEdgeIterator[T]):
    __slots__ = ()
    
    def __init__(self, collection: List[Tuple[Vertex[T], Vertex[T]]], reverse = False):
        object.__setattr__(self, "_collection", collection)
        object.__setattr__(self, "_reverse", reverse)
        object.__setattr__(self, "_curr_index", 0 if not reverse else len(collection) - 1)
        object.__setattr__(self, "_max_index", len(collection) - 1)
        
    def __iter__(self):
        return ConstBiDirectionalEdgeIterator(self._collection, self._reverse)
    
    def __setattr__(self, name: str, value: Any) -> None:
        raise AttributeError("Can't modify const iterator")