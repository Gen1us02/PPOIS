"""
    Модуль хранит вспомогательные функции для проверки правильности множеств 
    и перевода из одного состояния в другое
"""
from typing import List


def remove_duplicates(collection: List[str]) -> List[str]:
    """Функция используется для удаления повторяющихся элементов

    Аргументы:
        collection (List[str]): Список элементов множества

    Возвращаемое значение:
        List[str]: Множество входящих элементов
    """
    seen = []
    for elem in collection:
        if elem not in seen:
            seen.append(elem)
            
    return seen

def convert_to_string(collection: list) -> str:
    """Функция переводит множество в строку

    Аргументы:
        collection (list): Множество, которое надо перевести в строку

    Возвращаемое значение:
        str: Строковое представление множества
    """
    return '{' + ",".join(collection) + '}'

def convert_to_list(string: str) -> List[str]:
    """Функция переводит строковое представление множества в список элементов этого множества

    Аргументы:
        string (str): Строковое представление множества

    Возвращаемое значение:
        List[str]: Список, содержащий элементы множества
    """
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

def sort_set(string: str) -> str:
    """Функция рекурсивно сортирует вложенные множества и сами элементы множества

    Аргументы:
        string (str): Строковое представление множества

    Возвращаемое значение:
        str: Отсортированая строка, готовая к дальнейшим операциям
    """
    string = string.strip().replace(" ", "").replace("\n", "")
    
    if not string.startswith('{') or not string.endswith('}'):
        return string
    
    s = string[1:-1]
    if not s:
        return "{}"
    
    elements = []
    current = ""
    brackets_count = 0
    
    for char in s:
        if char == '{':
            brackets_count += 1
        elif char == '}':
            brackets_count -= 1
        
        if char == ',' and brackets_count == 0:
            if current:
                elements.append(current)
                current = ""
        else:
            current += char
    
    if current:
        elements.append(current)
    
    sorted_elements = [sort_set(elem) for elem in elements]
    sorted_elements = [elem for elem in sorted_elements if elem]
    sorted_elements.sort()
    
    return '{' + ','.join(sorted_elements) + '}'

def breckets_check(set_elem: str) -> bool:
    """Функция проверки скобочной последовательности элемента

    Аргументы:
        set_elem (str): Вложенное множество

    Возвращаемое значение:
        bool: True если скобочная последовательность верна, иначе False
    """
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
    """Функция проверки валидности элемента

    Аргументы:
        elem (str): Элемент, который надо проверить

    Возвращаемое значение:
        bool: True если элемент подходит, иначе False
    """
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
    """Функция для проверки правильности множества

    Аргументы:
        string (str): Строковое представление множества, которое нужно проверить

    Возвращаемое значение:
        bool: True если множество правильное, иначе False
    """
    if not string.startswith('{') or not string.endswith('}'):
        return False
    
    check_set = convert_to_list(string)
    for elem in check_set:
        if not is_valid_elem(elem):
            return False
        
    return True