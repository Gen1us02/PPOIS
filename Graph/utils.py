def next_step(index: int, reverse: bool) -> int:
    if not reverse:
        index += 1
    else:
        index -= 1
        
    return index

def has_previous_index(index: int):
    return 
        
def is_valid_index(index: int, max_index: int) -> bool:
    return 0 <= index < max_index