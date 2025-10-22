class Book:
    def __init__(self, title: str, price: float, pages: int) -> None:
        self.title = title
        self.price = price
        self.pages = pages
        
    def __eq__(self, other) -> bool:
        return self.price == other.price
    
    def __ne__(self, other) -> bool:
        return not self.__eq__(other)
    
    def __lt__(self, other) -> bool:
        return self.price < other.price
    
    def  __le__(self, other) -> bool:
        return self.price <= other.price
    
    def __gt__(self, other) -> bool:
        return self.price > other.price
    
    def __ge__(self, other) -> bool:
        return self.price >= other.price
    
    def __repr__(self) -> str:
        return f"Book({self.title}, {self.price}, {self.pages})"
        
    