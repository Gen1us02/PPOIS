from typing import Dict, Tuple


class Tic_Tac_Toe:
    __DEFAULT_TURN: str = 'X'
    
    def __init__(self, size: int) -> None:
        self.__size = size   
        self.__coords: Dict[Tuple, str] = {(row, col) : '*' for row in  range(self.__size) for col in range(self.__size)}
        self.__current_turn: str = self.__DEFAULT_TURN
    
    def change_turn(self) -> None:
        self.__current_turn = "O" if self.__current_turn == "X" else "X"
    
    def win_check(self) -> bool:
        player = self.__current_turn
        
        for row in range(self.__size):
            if all(self.__coords[(row, col)] == player for col in range(self.__size)):
                return True
            
            if all(self.__coords[(col, row)] == player for col in range(self.__size)):
                return True
            
        if all(self.__coords[(row, row)] == player for row in range(self.__size)):
            return True
        
        if all(self.__coords[(row, self.__size - row - 1)] for row in range(self.__size)):
            return True
                
        return False
    
    def draw_check(self):
        for value in self.__coords.values():
            if value == '*':
                return False
            
        return True
    
    @property
    def player(self) -> str:
        return self.__current_turn
    
    @property
    def size(self) -> int:
        return self.__size
    
    def __getitem__(self, cell: Tuple[int, int]) -> str:
        return self.__coords[cell]
    
    def __setitem__(self, cell, player) -> None:
        if self.__coords[cell] == "*":
            self.__coords[cell] = player
    
    def __str__(self) -> str:
        lines = []
        sep = ''.join('---' for _ in range(self.__size))

        for row in range(self.__size):
            row_cells = ' | '.join(self.__coords[(row, col)] for col in range(self.__size))
            lines.append(f'{row_cells}')
            if row < self.__size - 1:
                lines.append(sep)

        return '\n'.join(lines)