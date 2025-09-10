class Validator:
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