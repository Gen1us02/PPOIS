"""
    Модуль реализующий вспомогательные функции
"""
import os
from tic_tae_toe import Tic_Tac_Toe


def clear_console() -> None:
    """
        Функция очищающая консоль
    """
    os.system("cls" if os.name == "nt" else "clear")
    
def draw_board(game: Tic_Tac_Toe) -> None:
    """Функция отрисовки игрового поля и названия игры

    Args:
        game (Tic_Tac_Toe): Объект класса крестики нолики, печать которого выводит поле на экран
    """
    print("Игра крестики нолики")
    print(game)