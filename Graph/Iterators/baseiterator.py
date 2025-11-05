from typing import Generic, TypeVar
from abc import ABC, abstractmethod

T = TypeVar("T")

class BaseIterator(Generic[T], ABC):
    @abstractmethod
    def __iter__(self):
        pass
    
    @abstractmethod
    def __next__(self):
        pass
    
    @abstractmethod
    def previous(self):
        pass