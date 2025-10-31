from typing import Generic, TypeVar, List

T = TypeVar("T")

class PancakeSort(Generic[T]):
    @staticmethod
    def _flip(arr: List[T], i: int) -> None:
        start = 0
        while (start < i):
            arr[start], arr[i] = arr[i], arr[start]
            start += 1
            i -= 1
    
    @staticmethod
    def sort(arr: List[T]) -> None:
        size = len(arr)
        for i in range(size, 1, -1):
            maxElem = max(arr[:i])
            maxIndex = arr.index(maxElem)
            
            if maxIndex != i - 1:
                PancakeSort._flip(arr, maxIndex)
                PancakeSort._flip(arr, i - 1)