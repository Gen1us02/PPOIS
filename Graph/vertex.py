from typing import Generic, TypeVar, Optional, TYPE_CHECKING
if TYPE_CHECKING:
    from Graph.edge import Edge

T = TypeVar("T")

class Vertex(Generic[T]):
    def __init__(self, value: T):
        self.value: T = value
        self.count_prev: int = 0
        self.count_next: int = 0
        self.pred: Optional[Edge[T]] = None
        self.trail: Optional[Edge[T]] = None
        self.next: Optional[Vertex[T]] = None
    
    @property
    def degree(self) -> int:
        return self.count_prev
    
    def __eq__(self, other) -> bool:
        return self.value == other.value
    
    def __gt__(self, other) -> bool:
        return self.value > other.value
    
    def __lt__(self, other) -> bool:
        return self.value < other.value
    
    def __repr__(self) -> str:
        return f"Vertex(value={self.value})"