from typing import List


def remove_duplicates(collection: List[str]) -> List[str]:
    seen = []
    for elem in collection:
        if elem not in seen:
            seen.append(elem)
            
    return seen

def convert_to_string(collection: list) -> str:
    return '{' + ",".join(collection) + '}'

def convert_to_list(string: str) -> List[str]:
    string = string.strip(" \n")[1:-1].replace(" ", "")
    stack = []
    curr = ""
    breckets_count = 0
    
    for char in string:
        if char == "{":
            breckets_count += 1
        elif char == "}":
            breckets_count -= 1
            
        if char == "," and breckets_count == 0:
            if curr:
                stack.append(curr)
                
            curr = ""
        else:
            curr += char
            
    if curr:
        stack.append(curr)
        
    return remove_duplicates(stack)

def breckets_check(set_elem: str) -> bool:
    stack = []
    
    for char in set_elem:
        if char == '{':
            stack.append(char)
        elif char == '}':
            if not stack or stack[-1] != '{':
                return False
            
            stack.pop()
            
    return not stack
        
def is_valid_elem(elem: str) -> bool:
    if not elem:
        return False
    
    if elem.isdigit() or (elem[0] == '-' and elem[1:].isdigit()):
        return True
    
    if elem.isalpha():
        return True
    
    if elem[0] == '{' and elem[-1] == '}':
        return breckets_check(elem)
    
    return False

def is_correct_set(string: str) -> bool:
    some_set = convert_to_list(string)
    for elem in some_set:
        if not is_valid_elem(elem):
            return False
        
    return True