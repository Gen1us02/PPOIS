"""
    Модуль, реализующий ребро графа
"""
from typing import Generic, Optional, TypeVar
from Graph.vertex import Vertex

T = TypeVar("T")


class Edge(Generic[T]):
    """
    Универсальный класс, представляющий ребро графа.
    
    Ребро соединяет вершины в графе и используется для построения списков смежности.
    Каждое ребро направлено к целевой вершине и может ссылаться на следующее ребро
    в списке рёбер исходной вершины.
    
    Attributes:
        target_vertex: Целевая вершина, к которой направлено ребро.
        next: Ссылка на следующее ребро в списке рёбер исходной вершины.
    """
    
    def __init__(self, target_vertex: Vertex[T]) -> None:
        """
        Инициализирует ребро с указанной целевой вершиной.
        
        Args:
            target_vertex: Вершина, к которой направлено ребро.
        """
        self.target_vertex: Vertex[T] = target_vertex
        self.next: Optional["Edge[T]"] = None
        
    def __repr__(self) -> str:
        """
        Возвращает строковое представление ребра.
        
        Returns:
            Строка в формате 'Edge(to=target_vertex)', где target_vertex - значение целевой вершины.
        """
        return f"Edge(to={self.target_vertex.value})"