from baseiterator import BaseIterator
from typing import List, TypeVar, Tuple, Self
from Graph.vertex import Vertex

T = TypeVar("T")

class BiDirectionalEdgeIterator(BaseIterator):
    def __init__(self, collection: List[Tuple[Vertex[T], Vertex[T]]], reverse: bool = False):
        self._collection: List[T] = collection
        self._reverse = reverse
        self._curr_index = 0 if not reverse else len(collection) - 1
        self._max_index = len(collection) - 1
        
    def __iter__(self) -> Self:
        return self
    
    def __next__(self) -> Tuple[Vertex[T], Vertex[T]]:
        if not (0 <= self._curr_index < self._max_index):
            raise StopIteration("Index is out of range")
        
        value = self._collection[self._curr_index]
        self._curr_index = self._curr_index + (1 if not self._reverse else -1)
        return value
    
    def previous(self) -> Tuple[Vertex[T], Vertex[T]]:
        if not (0 <= self._curr_index < self._max_index):
            raise StopIteration("Index is out of range")
        
        value = self._collection[self._curr_index]
        self._curr_index = self._curr_index + (-1 if not self._reverse else 1)
        return value