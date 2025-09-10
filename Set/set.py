from typing import List
from conventor import Conventor
from validator import Validator

class Set:
    def __init__(self, set_string: str) -> None:
        self.__set: List[str] = self._convert_to_list(set_string)
    
    def add(self, elem: str) -> None:
        self.__set.append(elem)
    
    def del_elem(self, elem: str) -> None:
        self.__set.remove(elem)
    
    def is_empty(self) -> bool:
        return len(self.__set) == 0
    
    def power(self) -> int:
        return len(self.__set)
    
    def boolean(self) -> str:
        result = [[]]
        for elem in self.__set:
            result = [subset + [elem] for subset in result]
        
        return self._convert_to_string(result)
    
    @property
    def set_string(self) -> str:
        return self._convert_to_string(self.__set)
    
    @set.setter
    def set_string(self, value: str) -> None:
        self.__set = self._convert_to_list(value)
        
    def __add__(self, other):
        return 
    
    def __iadd__(self, other):
        pass
    
    def __sub__(self, other):
        pass
    
    def __isub__(self, other):
        pass
    
    def __mul__(self, other):
        pass
    
    def __imul__(self, other):
        pass
    
    def __contains__(self, elem) -> bool:
        return elem in self.__set
    
    def __str__(self):
        return f"{self.__set}"