"""
Модуль реализующий, класс блинной сортировки
"""

from typing import Generic, TypeVar, List

T = TypeVar("T")


class PancakeSort(Generic[T]):
    """
    Класс, реализующий алгоритм блинной сортировки
    """

    @staticmethod
    def _flip(arr: List[T], i: int) -> None:
        """Статический метод, реализующий переворот массива до заданного индекса

        Args:
            arr (List[T]): Массив для сортировки, поддерживающий любые сравнимые типы данных
            i (int): Индекс, до которого производится переворот массива
        """
        start = 0
        while start < i:
            arr[start], arr[i] = arr[i], arr[start]
            start += 1
            i -= 1

    @staticmethod
    def sort(arr: List[T]) -> None:
        """Статический метод, реализующий сам алгоритм блинной сортировки

        Args:
            arr (List[T]): Массив для сортировки, поддерживающий любые сравнимые типы данных
        """
        size = len(arr)
        for i in range(size, 1, -1):
            maxElem = max(arr[:i])
            maxIndex = arr.index(maxElem)

            if maxIndex != i - 1:
                PancakeSort._flip(arr, maxIndex)
                PancakeSort._flip(arr, i - 1)
