def flip(arr, i) -> None:
    start = 0
    while (start < i):
        arr[start], arr[i] = arr[i], arr[start]
        start += 1
        i -= 1
    
def pancakeSort(arr) -> None:
    size = len(arr)
    for i in range(size, 1, -1):
        maxElem = max(arr[:i])
        maxIndex = arr.index(maxElem)
        
        if maxIndex != i - 1:
            flip(arr, maxIndex)
            flip(arr, i - 1)