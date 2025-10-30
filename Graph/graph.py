from typing import Optional, TypeVar
from Graph.vertex import Vertex
from Graph.edge import Edge

T = TypeVar("T")

class Graph:
    def __init__(self):
        self.head: Optional[Vertex[T]] = None
        self.tail: Optional[Vertex[T]] = None
        
    def _find_vertex(self, value: T) -> Optional[Vertex[T]]:
        current = self.head
        while current:
            if current.value == value:
                return current
            current = current.next
            
        return None
    
    def _has_directed_edge(self, vertex_a: Vertex[T], vertex_b: Vertex[T]) -> bool:
        current = vertex_a.trail
        while current:
            if current.vertex == vertex_b:
                return True
            current = current.next
            
        return False
    
    def _add_directed_edge(self, vertex_a: Vertex[T], vertex_b: Vertex[T]) -> None:
        trail_edge = Edge(vertex_b)
        trail_edge.next = vertex_a.trail
        vertex_a.trail = trail_edge
        vertex_a.count_next += 1
        
        pred_edge = Edge(vertex_a)
        pred_edge.next = vertex_b.pred
        vertex_b.pred = pred_edge
        vertex_b.count_prev += 1
        
    def _remove_directed_edge(self, vertex_a: Vertex[T], vertex_b: Vertex[T]) -> None:
        prev = None
        current = vertex_a.trail
        while current:
            if current.target_vertex == vertex_b:
                if prev:
                    prev.next = current.next
                else:
                    vertex_a.trail = current.next
                    
                vertex_a.count_next -= 1
                break
            prev = current
            current = current.next
            
        prev = None
        current = vertex_b.pred
        while current:
            if current.target_vertex == vertex_a:
                if prev:
                    prev.next = current.next
                else:
                    vertex_b.pred = current.next
                    
                vertex_b.count_prev -= 1
                break
            prev = current
            current = current.next
    
    def _create_vertex(self, value: T) -> None:
        new_vertex = Vertex(value)
        if self.head is None and self.tail is None:
            self.head = new_vertex
            self.tail = new_vertex
        else:
            if self.tail:
                self.tail.next = new_vertex
                self.tail = new_vertex
                
    def _remove_vertex(self, value: T) -> None:
        vertex = self._find_vertex(value)
        if not vertex:
            return
        
        current = self.head
        while current:
            if current != vertex:
                self._remove_directed_edge(current, vertex)
                self._remove_directed_edge(vertex, current)
            current = current.next
            
        if vertex == self.head:
            self.head = vertex.next
            if vertex == self.tail:
                self.head = self.tail
        else:
            current = self.head
            while current:
                if current and current.next == vertex:
                    current.next = vertex.next
                    if vertex == self.tail:
                        self.tail = current
                        
                    break 
                current = current.next
            

    def has_vertex(self, value: T) -> bool:
        return self._find_vertex(value) is not None
    
    def has_edge(self, value_a: T, value_b: T) -> bool:
        vertex_a = self._find_vertex(value_a)
        vertex_b = self._find_vertex(value_b)
        
        if vertex_a is None or vertex_b is None:
            return False
        
        return self._has_directed_edge(vertex_a, vertex_b) or \
                    self._has_directed_edge(vertex_b, vertex_a)
                    
    def vertex_count(self) -> int:
        current = self.head
        vertexies = 0
        while current:
            vertexies += 1
            current = current.next
            
        return vertexies
        
    def edges_count(self) -> int:
        current = self.head
        edges = 0
        while current:
            edges += current.count_next
            current = current.next
            
        return edges // 2
        
    def vertex_degree(self, value: T) -> int:
        vertex = self._find_vertex(value)
        if vertex is None:
            raise ValueError("Vertex is not found")
        
        return vertex.degree
    
    def add_vertex(self, value: T) -> None:
        if self.has_vertex(value):
            raise ValueError("Vertex is already in graph")
        
        self._create_vertex(value)
        
    def delete_vertex(self, value: T) -> None:
        if not self.has_vertex(value):
            raise ValueError("Vertex is not in graph")
        
        self._remove_vertex(value)
        
    def add_edge(self, value_a: T, value_b: T) -> None:
        vertex_a = self._find_vertex(value_a)
        vertex_b = self._find_vertex(value_b)
        
        if vertex_a == vertex_b:
            raise ValueError("Same vertex")
        
        if not self._has_directed_edge(vertex_a, vertex_b):
            self._add_directed_edge(vertex_a, vertex_b)
            
        if not self._has_directed_edge(vertex_b, vertex_a):
            self._add_directed_edge(vertex_b, vertex_a)
            
    def delete_edge(self, value_a: T, value_b: T) -> None:
        vertex_a = self._find_vertex(value_a)
        vertex_b = self._find_vertex(value_b)
        
        if vertex_a == vertex_b:
            raise ValueError("Same vertex")
        
        if not vertex_a or not vertex_b:
            raise ValueError("One of the vertieces is not in graph")
        
        if self._has_directed_edge(vertex_a, vertex_b):
            self._remove_directed_edge(vertex_a, vertex_b)
            
        if self._has_directed_edge(vertex_b, vertex_a):
            self._remove_directed_edge(vertex_b, vertex_a)