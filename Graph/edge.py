from typing import Generic, Optional, TypeVar
from Graph.vertex import Vertex

T = TypeVar("T")

class Edge(Generic[T]):
    def __init__(self, target_vertex: Vertex[T]):
        self.target_vertex: Vertex[T] = target_vertex
        self.next: Optional[Edge] = None
        
    def __repr__(self) -> str:
        return f"Edge(to={self.target_vertex.value})"