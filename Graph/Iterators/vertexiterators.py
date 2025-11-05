from baseiterator import BaseIterator
from typing import TypeVar, List, Self
from Graph.vertex import Vertex

T = TypeVar("T")

class BiDirectionalVertexIterator(BaseIterator):
    def __init__(self, collection: List[Vertex[T]], reverse: bool = False):
        self._collection = collection
        self._reverse = reverse
        self._curr_index = 0 if not reverse else len(collection) - 1
        self._max_index = len(collection) - 1
        
    def __iter__(self) -> Self:
        return self
    
    def __next__(self) -> Vertex[T]:
        if not (0 <= self._curr_index < self._max_index):
            raise StopIteration("Index out of range")
        
        current = self._collection[self._curr_index]
        self._curr_index = self._curr_index + (1 if not self._reverse else -1)
        return current
    
    def previous(self) -> Vertex[T]:
        if not (0 <= self._curr_index < self._max_index):
            raise StopIteration("Index out of range")
        
        current = self._collection[self._curr_index]
        self._curr_index = self._curr_index + (-1 if not self._reverse else 1)
        return current