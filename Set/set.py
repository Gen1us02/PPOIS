from typing import List

class Set:
    def __init__(self, set_string: str):
        self.__set: List[str] = self._convert_to_list(set_string)
    
    def add(self, elem: str) -> None:
        self.__set.append(elem)
    
    @staticmethod
    def _convert_to_string(collection: list) -> str:
        return '{' + ",".join(collection) + '}'
    
    @staticmethod   
    def _convert_to_list(string: str) -> List[str]:
        return string[1:-1].replace(" ", "").split(",")
    
    @staticmethod
    def _breckets_check(set_elem: str) -> bool:
        stack = []
        
        for char in set_elem:
            if char == '{':
                stack.append(char)
            elif char == '}':
                if not stack or stack[-1] != '{':
                    return False
                
                stack.pop()
                
        return not stack
            
    def _is_valid_elem(self, elem: str) -> bool:
        if not elem:
            return False
        
        if elem.isdigit() or (elem[0] == '-' and elem[1:].isdigit()):
            return True
        
        if elem.isalpha():
            return True
        
        if elem[0] == '{' and elem[-1] == '}':
            return self._breckets_check(elem)
        
        return False

    def is_correct_set(self, string: str) -> bool:
        some_set = self._convert_to_set(string)
        for elem in some_set:
            if not self._is_valid_elem(elem):
                return False
            
        return True
    
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
    def set_string(self):
        return self.__set
    
    @set.setter
    def set_string(self, value: str):
        self.__set = self._convert_to_list(value)
        
    def __add__(self, other):
        pass
    
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