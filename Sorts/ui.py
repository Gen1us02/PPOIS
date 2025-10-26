from typing import List
from Sorts.book import Book
from Sorts.pancakesort import pancakeSort
from Sorts.smoothsort import smoothSort


def get_user_input() -> List[int | str | Book]:
    print("Выберите тип данных для сортировки: ")
    print("===================================")
    print("1 - Целые числа")
    print("2 - Вещественные числа")
    print("3 - Строки")
    print("4 - Объекты класса \"Книга\" по цене")
    
    choice = input("Ваш выбор: ").strip()
    
    while True:
        match choice:
            case "1":
                print("Вводите целые числа через пробел:")
                data = input().strip().split()
                
                try:
                    return [int(x) for x in data]
                except ValueError:
                    print("Неверный ввод повторите попытку")
                    
            case "2":
                print("Вводите вещественные числа через пробел:")
                data = input().strip().split()
                
                try:
                    return [float(x) for x in data]
                except ValueError:
                    print("Неверный ввод повторите попытку")

            case "3":
                print("Вводите строки через пробел:")
                data = input().strip().split()
                
                return data
            case "4":
                books = []
                print("Вводите данные о книге через пробел: Название Цена Количество страниц(введите stop, чтобы завершить ввод)")
                
                while True:
                    book_data = input().strip()
                    
                    if book_data.lower() == "stop":
                        break
                    
                    book_data = book_data.split()
                    
                    if not book_data:
                        print("Введены пустые данные. Повторите попытку")
                        continue
                    
                    if len(book_data) != 3:
                        print("Ввод данных осуществляется через пробел!")
                        continue
                    
                    try:
                        title = book_data[0]
                        price = book_data[1]
                        pages = book_data[2]
                        books.append(Book(title, price, pages))
                    except ValueError:
                        print("Цена и количество страниц должны быть числами!")
                
                return books
            
            case _:
                print("Неверный выбор пункта. Пвторите попытку")
        
def menu() -> None:
    data = get_user_input()
    
    while True:
        print("Меню программы")
        print("=====================")
        print("1 - Pancake Sort")
        print("2 - Smooth Sort")
        print("3 - Выход из программы")
        print("=====================")
        
        choice = input("Ваш выбор:").strip()
        
        match choice:
            case "1":
                print(f"Массив до сортировки: {data}")
                data_copy = data[:]
                pancakeSort(data_copy)
                print(f"Массив после сортировки: {data_copy}")
            case "2":
                print(f"Массив до сортировки: {data}")
                data_copy = data[:]
                smoothSort(data_copy)
                print(f"Массив после сортировки: {data_copy}")
            case "3":
                print("Программа завершена")
                return
            case _:
                print("Неверный ввод, повторите попытку")        