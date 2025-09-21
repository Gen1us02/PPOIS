"""
    Модуль реализующий игру крестики нолики
"""
from typing import Dict, Tuple


class Tic_Tac_Toe:
    """
        Класс реализующий полный функционал игры крестики нолики
    """
    __DEFAULT_TURN: str = 'X'
    
    def __init__(self, size: int) -> None:
        """Конструктор класса крестики нолики

        Аргументы:
            size (int): размер поля крестиков ноликов
        """
        self.__size: int = size   
        self.__coords: Dict[Tuple, str] = {(row, col) : '*' for row in  range(self.__size) for col in range(self.__size)}
        self.__current_turn: str = self.__DEFAULT_TURN
    
    def change_turn(self) -> None:
        """
            Метод смены хода игрока
        """
        self.__current_turn = "O" if self.__current_turn == "X" else "X"
    
    def win_check(self) -> bool:
        """Метод, проверяющий победу  текущего игрока

        Возвращаемое значение:
            bool: True если текущий игрок выиграл, иначе False
        """
        player = self.__current_turn
        
        for row in range(self.__size):
            if all(self.__coords[(row, col)] == player for col in range(self.__size)):
                return True
            
            if all(self.__coords[(col, row)] == player for col in range(self.__size)):
                return True
            
        if all(self.__coords[(row, row)] == player for row in range(self.__size)):
            return True
        
        if all(self.__coords[(row, self.__size - row - 1)] == player for row in range(self.__size)):
            return True
                
        return False
    
    def draw_check(self) -> bool:
        """Метод, проверяющий поле игры на ничью

        Возвращаемое значение:
            bool: True если все клетки заняты и никто не выиграл, иначе False
        """
        for value in self.__coords.values():
            if value == '*':
                return False
            
        return True
    
    @property
    def player(self) -> str:
        """Геттер поля current_turn

        Возвращаемое значение:
            str: Возвращает текущего игрока
        """
        return self.__current_turn
    
    @property
    def size(self) -> int:
        """Геттер поля size

        Возвращаемое значение:
            int: Возвращает размер игрового поля
        """
        return self.__size
    
    def __getitem__(self, cell: Tuple[int, int]) -> str:
        """Магический метод getitem срабатывает при обращении к элементу по ключу ([])

        Аргументы:
            cell (Tuple[int, int]): Ключ, представляющий кортеж координат

        Возвращаемое значение
            str: Значение из переданной клетки поля
        """
        return self.__coords[cell]
    
    def __setitem__(self, cell: Tuple[int, int], player: str) -> None:
        """Магический метод setitem срабатывает при установке значения по ключу

        Аргументы:
            cell (Tuple[int, int]): Ключ, для которого будет устанавливаться значение
            player (str): Игрок, который ходит в указанную позицию
        """
        if self.__coords[cell] == "*":
            self.__coords[cell] = player
    
    def __str__(self) -> str:
        """Магический метод str 

        Возвращаемое значение:
            str: Возвращает отрисовку поля
        """
        lines = []

        for row in range(self.__size):
            row_cells = ' | '.join(self.__coords[(row, col)] for col in range(self.__size))
            lines.append(f'{row_cells}')
            if row < self.__size - 1:
                sep = "-" * len(row_cells)
                lines.append(sep)

        return '\n'.join(lines)