from sets import Set
from utils import is_correct_set

def main():
    input_choice = 0
    while input_choice != 1 and input_choice != 2:
        print("Выберите способ задания множеств:")
        print("1 - Ввод множеств в ручную")
        print("2 - Считывание множеств из файла")
        try:
            input_choice = int(input("Ваш выбор: "))
            
            match input_choice:
                case 1:
                    first_set_string = input("Введите первое множество: ")
                    second_set_string = input("Введите второе множество: ")
                    while is_correct_set(first_set_string):
                        first_set_string = input("1 - е множество введено неверно, повторите попытку")
                        
                    while is_correct_set(second_set_string):
                        second_set_string = input("2 - е множество введено неверно, повторите попытку")
                case 2:
                    with open("input/sets.txt", 'r') as f:
                        first_set_string, second_set_string = f.readlines()
                        
                case _:
                    print("Неверный выбор операции. Повторите попытку")
                    
        except ValueError:
            print("Неверный ввод повторите попытку")
                
    first_set = Set(first_set_string)
    second_set = Set(second_set_string)    
      
    choice = 0
    while choice != 10:
        print("-----Меню-----")
        print("1 - Проверить множество на пустоту")
        print("2 - Добавить элемент в множество")
        print("3 - Удалить элемент из множества")
        print("4 - Мощность множества")
        print("5 - Пренадлежит ли элемент множество")
        print("6 - Объединение двух множеств")
        print("7 - Пересечение двух множеств")
        print("8 - Разность двух множеств")
        print("9 - Построение булеана множества")
        print("10 - Завершение программы")
        
        try:
            choice = int(input("Ваш выбор: "))
            
            match choice:
                case 1:
                    print("Множество пустое" if first_set.is_empty() else "В множестве есть элементы")
                    
                case 2:
                    elem = input("Введите элемент, который хотите добавить: ")
                    operation_result = first_set.add(elem)
                    if operation_result:
                        print("Элемент успешно добавлен")
                    else:
                        print("Не удалось добавить элемент, возможно он введен неправильно")
                        
                case 3: 
                    elem = input("Введите элемент, который хотите удалить: ")
                    operation_result = first_set.del_elem(elem)
                    if operation_result:
                        print("Элемент успешно удален")
                    else:
                        print("Не удалось удалить элемент, возможно его нет в множестве")
                        
                case 4:
                    print(f"Мощность множества: {first_set.power()}")
                    
                case 5:
                    elem = input("Введите элемент: ")
                    print("Элемент принадлежит множеству" if elem in first_set else "Элемент не содержится в множестве")
                    
                case 6:
                    union_set = first_set + second_set
                    print(f"Объединение множеств {union_set}")
                    
                case 7:
                    intersection_set = first_set * second_set
                    print(f"Пересечение множеств: {intersection_set}")
                    
                case 8:
                    difference_set = first_set - second_set
                    print(f"Пересечение множеств: {difference_set}")
                    
                case 9:
                    print(f"Булеан множества: {first_set.boolean()}")
                    
                case 10:
                    print("Завершение программы")
                    
                case _:
                    print("Неверный выбор операции. Повторите попытку")
                    
        except ValueError:
            print("Неверный ввод. Повторите попытку")
            
            
if __name__ == "__main__":
    main()