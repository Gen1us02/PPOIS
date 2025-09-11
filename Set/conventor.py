from typing import List


class Conventor:
    @staticmethod
    def convert_to_string(collection: list) -> str:
        return '{' + ",".join(collection) + '}'
    
    @staticmethod   
    def convert_to_list(string: str) -> List[str]:
        return string[1:-1].replace(" ", "").split(",")