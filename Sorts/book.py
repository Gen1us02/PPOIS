"""
Модуль, реализующий класс Book, который поддерживает сортировку
"""


class Book:
    """
    Пользовательский класс Book, используемый для демонстрации
    сортировки пользовательских классов
    """

    def __init__(self, title: str, price: float, pages: int) -> None:
        """Конструктор класса, который инициализирует поля класса переданными значениями

        Args:
            title (str): Название книги
            price (float): Цена книги
            pages (int): Количество страниц в книге
        """
        self.title: str = title
        self.price: float = price
        self.pages: int = pages

    def __eq__(self, other) -> bool:
        """Магический метод, который вызывается при сравнении
        объектов класса через оператор ==

        Args:
            other (Book): Объект класса Book, с которым сравнивается текущий объект
        Returns:
            bool: True, если поля цен у объектов класса равны, иначе - False
        """
        return self.price == other.price

    def __ne__(self, other) -> bool:
        """Магический метод, который вызывается при сравнении
        объектов класса через оператор !=

        Args:
            other (Book): Объект класса Book, с которым сравнивается текущий объект
        Returns:
            bool: True, если поля цен у объектов класса не равны, иначе - False
        """
        return not self.__eq__(other)

    def __lt__(self, other) -> bool:
        """Магический метод, который вызывается при сравнении
        объектов класса через оператор <

        Args:
            other (Book): Объект класса Book, с которым сравнивается текущий объект
        Returns:
            bool: True, если поле цены у self < other, иначе - False
        """
        return self.price < other.price

    def __le__(self, other) -> bool:
        """Магический метод, который вызывается при сравнении
        объектов класса через оператор <=

        Args:
            other (Book): Объект класса Book, с которым сравнивается текущий объект
        Returns:
            bool: True, если поле цены у self <= other, иначе - False
        """
        return self.price <= other.price

    def __gt__(self, other) -> bool:
        """Магический метод, который вызывается при сравнении
        объектов класса через оператор >

        Args:
            other (Book): Объект класса Book, с которым сравнивается текущий объект
        Returns:
            bool: True, если поле цены у self > other, иначе - False
        """
        return self.price > other.price

    def __ge__(self, other) -> bool:
        """Магический метод, который вызывается при сравнении
        объектов класса через оператор >=

        Args:
            other (Book): Объект класса Book, с которым сравнивается текущий объект
        Returns:
            bool: True, если поле цены у self >= other, иначе - False
        """
        return self.price >= other.price

    def __repr__(self) -> str:
        """Магический метод, репрезентационное представление объекта класса.
        В текущей реализации вызывается при выводе коллекции, содержащей объекты класса Book

        Returns:
            str: Строковое представление объекта класса в виде конструктора
        """
        return f"Book(title={self.title}, price={self.price}, pages={self.pages})"
