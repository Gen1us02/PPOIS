from tic_tae_toe import Tic_Tac_Toe


def main() -> None:
    while True:
        try:
            size = int(input("Введите размер поля (размер должен быть >= 3): "))
            while size < 3:
                size = int(input("Размер должен быть больше или равен 3. Повторите попытку "))
            break
        except ValueError:
            print("Размер введен неверно. Повторите попытку ")
    game = Tic_Tac_Toe(size)
    print("Игра крестики нолики")
    while True:
        print(game)
        print(f"Сейчас ходит {game.player}")
        while True:
            try:
                pos = tuple(map(int,input("Введите позицию, для хода через пробел: ").split()))
                while (pos[0] < 0  or pos[0] > game.size) or (pos[1] < 0 or pos[1] > game.size):
                    pos = tuple(map(int,input("Вы вышли за пределы поля. Повторите попытку: ").split()))
                while game[pos] != '*':
                    pos = tuple(map(int,input(f"Позиция занята игроком {game[pos]}. Повторите попытку: ").split()))
                break
            except ValueError:
                print("Неверный ввод повторите попытку")
                
        game[pos] = game.player
        if game.win_check():
            print(game)
            print(f"Победил игрок {game.player}")
            break
        elif game.draw_check():
            print(game)
            print("Ничья")
            break
        game.change_turn()
        
        
if __name__ == "__main__":
    main()