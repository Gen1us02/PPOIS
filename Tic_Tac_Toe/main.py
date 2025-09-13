"""
    Модуль с реализацией интерфейса пользователя
"""
from Tic_Tac_Toe.tic_tae_toe import Tic_Tac_Toe
from Tic_Tac_Toe.utils import clear_console, draw_board


def main() -> None:
    """
        Основная функция для интерфейса пользователя, позволяющая взаимодействовать
        с программой 
    """
    while True:
        try:
            size = int(input("Введите размер поля (размер должен быть >= 3): "))
            while size < 3:
                size = int(input("Размер должен быть больше или равен 3. Повторите попытку "))
            break
        except ValueError:
            print("Размер введен неверно. Повторите попытку ")
    
    game = Tic_Tac_Toe(size)
    while True:
        clear_console()
        draw_board(game)
        print(f"Сейчас ходит {game.player}")
        while True:
            try:
                pos = tuple(map(int,input("Введите позицию, для хода через пробел: ").strip().split()))
                while not (0 <= pos[0] < game.size and 0 <= pos[1] < game.size):
                    pos = tuple(map(int,input("Вы вышли за пределы поля. Повторите попытку: ").strip().split()))
                while game[pos] != '*':
                    pos = tuple(map(int,input(f"Позиция занята игроком {game[pos]}. Повторите попытку: ").strip().split()))
                break
            except (ValueError, IndexError, KeyError):
                print("Неверный ввод повторите попытку")
                
        game[pos] = game.player
        if game.win_check():
            clear_console()
            draw_board(game)
            print(f"Победил игрок {game.player}")
            break
        elif game.draw_check():
            clear_console()
            draw_board(game)
            print("Ничья")
            break
        game.change_turn()
        
        
if __name__ == "__main__":
    main()