import pytest
from Sorts.book import Book
from Sorts.pancakesort import PancakeSort
from Sorts.smoothsort import SmoothSort


@pytest.mark.parametrize("array, sorted_array",
        [([35, 687, 2139, 34, 405, 123], [34, 35, 123, 405, 687, 2139]),
        ([-10, 5, 34, 234, 0, 20, 13, -56, -78], [-78, -56, -10, 0, 5, 13, 20, 34, 234]),
        ([8.56, 4.32, 5.87, 23.56, 10.34], [4.32, 5.87, 8.56, 10.34, 23.56]),
        ([-45.54, -100.549, 45.324, 5.34, 78.31, 2.12, 0.0], [-100.549, -45.54, 0.0, 2.12, 5.34, 45.324, 78.31]),
        (["kirill", "dima", "artem", "zhenya", "wolf", "cat"], ["artem", "cat", "dima", "kirill", "wolf", "zhenya"]),
        (["fshjhjfs", "adaaj", "qd", "asjd", "ajiokda", "jdasd"], ["adaaj", "ajiokda", "asjd", "fshjhjfs", "jdasd", "qd"]),
        ([Book("Garry Potter", 140, 345), Book("Wolf", 78, 122), Book("Void", 23, 324), Book("ArtemDjDj", 345, 346)], 
            [Book("Void", 23, 324), Book("Wolf", 78, 122), Book("Garry Potter", 140, 345), Book("ArtemDjDj", 345, 346)]),
        ([Book("Prince", 240, 345), Book("Dima", 83, 122), Book("Fox", 13, 324), Book("Orange", 138, 346), Book("Guilty", 45, 231)], 
            [Book("Fox", 13, 30), Book("Guilty", 45, 231), Book("Dima", 83, 122), Book("Orange", 138, 345), Book("Prince", 240, 346)])])
def test_pancake_sort(array, sorted_array):
    PancakeSort.sort(array)
    assert array == sorted_array

@pytest.mark.parametrize(
    "array, sorted_array",
    [
        ([5, -3, 0, -1, 2], [-3, -1, 0, 2, 5]),
        ([100, -50, 25, -75, 0], [-75, -50, 0, 25, 100]),
        ([1.5, -2.3, 0.7, -4.1], [-4.1, -2.3, 0.7, 1.5]),
        ([3.33, -0.89, 2.71, -1.41], [-1.41, -0.89, 2.71, 3.33]),
        (["zebra", "apple", "moon", "dog"], ["apple", "dog", "moon", "zebra"]),
        (["python", "java", "c", "ruby"], ["c", "java", "python", "ruby"]),
        (
            [
                Book("Alchemy", 300, 150),
                Book("Basics", 150, 80),
                Book("Coding", 500, 200)
            ],
            [
                Book("Basics", 150, 80),
                Book("Alchemy", 300, 150),
                Book("Coding", 500, 200)
            ],
        ),
        (
            [
                Book("Xenon", 50, 10),
                Book("Yak", 200, 75),
                Book("Zeus", 100, 30),
                Book("God", 12, 34),
                Book("Health", 78, 43)
            ],
            [
                Book("God", 12, 34),
                Book("Xenon", 50, 10),
                Book("Health", 78, 43),
                Book("Zeus", 100, 30),
                Book("Yak", 200, 75)
            ],
        ),
    ]
)
def test_smooth_sort(array, sorted_array):
    SmoothSort.sort(array)
    assert array == sorted_array