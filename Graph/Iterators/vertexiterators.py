from baseiterator import BaseIterator
from typing import TypeVar, List, Self, Any
from Graph.vertex import Vertex

T = TypeVar("T")

class BiDirectionalVertexIterator(BaseIterator):
    def __init__(self, collection: List[Vertex[T]], reverse: bool = False):
        self._collection = collection
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
    
    def __next__(self) -> Vertex[T]:
        if not (0 <= self._curr_index <= self._max_index):
            raise StopIteration("Index out of range")
        
        current = self.current()
        self._curr_index = self._curr_index + (1 if not self._reverse else -1)
        return current
    
    def previous(self) -> Vertex[T]:
        if not (0 <= self._curr_index <= self._max_index):
            raise StopIteration("Index out of range")
        
        current = self._collection[self._curr_index]
        self._curr_index = self._curr_index + (-1 if not self._reverse else 1)
        return current
    
    def current(self) -> Vertex[T]:
        return self._collection[self._curr_index]
    
    
class ConstBiDirectionalVertexIterator(BiDirectionalVertexIterator[T]):
    __slots__ = ()
    
    def __init__(self, collection: List[Vertex[T]], reverse = False):
        object.__setattr__(self, "_collection", collection)
        object.__setattr__(self, "_reverse", reverse)
        object.__setattr__(self, "_curr_index", 0 if not reverse else len(collection) - 1)
        object.__setattr__(self, "_max_index", len(collection) - 1)
        
    def __iter__(self):
        return ConstBiDirectionalVertexIterator(self._collection, self._reverse)
    
    def __setattr__(self, name: str, value: Any) -> None:
        raise AttributeError("Can't modify const iterator")