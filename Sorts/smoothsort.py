"""Модуль, реализующий класс плавной сортировки
"""
from typing import Generic, TypeVar, List, Tuple


T = TypeVar("T")

class SmoothSort(Generic[T]):
    """
    Класс SmoothSort, реализующий алгоритм плавной сортировки
    """
    @staticmethod
    def sort(lst: List[T]) -> None:
        """Статический метод, реализующий сам алгоритм плавной сортировки "на месте"

        Args:
            lst (List[T]): Массив любых типов данных для сортировки
        """
        leo_nums = SmoothSort._leonardo_numbers(len(lst))
        heap = []

        for i in range(len(lst)):
            if len(heap) >= 2 and heap[-2] == heap[-1] + 1:
                heap.pop()
                heap[-1] += 1
            else:
                if len(heap) >= 1 and heap[-1] == 1:
                    heap.append(0)
                else:
                    heap.append(1)
            SmoothSort._restore_heap(lst, i, heap, leo_nums)

        for i in reversed(range(len(lst))):
            if heap[-1] < 2:
                heap.pop()
            else:
                k = heap.pop()
                t_r, k_r, t_l, k_l = SmoothSort._get_child_trees(i, k, leo_nums)
                heap.append(k_l)
                SmoothSort._restore_heap(lst, t_l, heap, leo_nums)
                heap.append(k_r)
                SmoothSort._restore_heap(lst, t_r, heap, leo_nums)

    @staticmethod
    def _leonardo_numbers(hi: int) -> List[int]:
        """Статический метод для вычисления Леонардовой последовательности до заданного члена

        Args:
            hi (int): Количество элементов Леонардовой последовательности

        Returns:
            List[int]: Массив элементов Леонардовой последовательности
        """
        a, b = 1, 1
        numbers = []
        while a <= hi:
            numbers.append(a)
            a, b = b, a + b + 1
        return numbers

    @staticmethod
    def _restore_heap(lst: List[T], i: int, heap: List[T], leo_nums: List[int]) -> None:
        """
        Статический метод, восстанавливающий свойство кучи для дерева Леонардо.

        Метод выполняет две операции:
        1. Поднимает элемент вверх по куче, если он больше родителя
        2. Опускает элемент вниз по куче, если он меньше детей

        Args:
            lst (List[T]): Сортируемый массив
            i (int): Индекс текущего элемента
            heap (List[T]): Массив размеров деревьев Леонардо
            leo_nums (List[int]): Массив чисел Леонардо
        """
        current = len(heap) - 1
        k = heap[current]

        while current > 0:
            j = i - leo_nums[k]
            if (lst[j] > lst[i] and
                (k < 2 or lst[j] > lst[i-1] and lst[j] > lst[i-2])):
                lst[i], lst[j] = lst[j], lst[i]
                i = j
                current -= 1
                k = heap[current]
            else:
                break
        
        while k >= 2:
            t_r, k_r, t_l, k_l = SmoothSort._get_child_trees(i, k, leo_nums)
            if lst[i] < lst[t_r] or lst[i] < lst[t_l]:
                if lst[t_r] > lst[t_l]:
                    lst[i], lst[t_r] = lst[t_r], lst[i]
                    i, k = t_r, k_r
                else:
                    lst[i], lst[t_l] = lst[t_l], lst[i]
                    i, k = t_l, k_l
            else:
                break

    @staticmethod
    def _get_child_trees(i: int, k: int, leo_nums: List[int]) -> Tuple[int, int, int ,int]:
        """
        Статический метод, находящий индексы и размеры дочерних деревьев Леонардо.

        Args:
            i (int): Индекс корня текущего дерева
            k (int): Размер текущего дерева
            leo_nums (List[int]): Массив чисел Леонардо

        Returns:
            Tuple[int, int, int, int]: Кортеж (t_r, k_r, t_l, k_l), где:
                t_r: индекс правого дочернего дерева
                k_r: размер правого дочернего дерева
                t_l: индекс левого дочернего дерева
                k_l: размер левого дочернего дерева
        """
        t_r, k_r = i - 1, k - 2
        t_l, k_l = t_r - leo_nums[k_r], k - 1
        
        return t_r, k_r, t_l, k_l