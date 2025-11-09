"""
    Модуль, реализующий вершину графа
"""
from typing import Generic, TypeVar, Optional, TYPE_CHECKING
if TYPE_CHECKING:
    from Graph.edge import Edge

T = TypeVar("T")


class Vertex(Generic[T]):
    """
    Универсальный класс, представляющий вершину графа.
    
    Вершина может хранить данные произвольного типа и поддерживает связи с другими вершинами
    через рёбра. Используется для построения ориентированных графов.
    
    Attributes:
        value: Значение, хранящееся в вершине.
        count_prev: Счетчик входящих рёбер (степень захода).
        count_next: Счетчик исходящих рёбер (степень исхода).
        pred: Ссылка на входящее ребро в графе.
        trail: Ссылка на исходящее ребро в графе.
        next: Ссылка на следующую вершину в связанном списке.
    """
    
    def __init__(self, value: T) -> None:
        """
        Инициализирует вершину с заданным значением.
        
        Args:
            value: Значение для хранения в вершине.
        """
        self.value: T = value
        self.count_prev: int = 0
        self.count_next: int = 0
        self.pred: Optional[Edge[T]] = None
        self.trail: Optional[Edge[T]] = None
        self.next: Optional[Vertex[T]] = None
    
    @property
    def degree(self) -> int:
        """
        Возвращает степень захода вершины.
        
        Returns:
            Количество входящих рёбер (эквивалентно count_prev).
        """
        return self.count_prev
    
    def __eq__(self, other) -> bool:
        """
        Проверяет равенство вершин по значению.
        
        Args:
            other: Другая вершина для сравнения.
            
        Returns:
            True если значения вершин равны, иначе False.
        """
        return self.value == other.value
    
    def __gt__(self, other) -> bool:
        """
        Проверяет, больше ли значение текущей вершины.
        
        Args:
            other: Другая вершина для сравнения.
            
        Returns:
            True если значение текущей вершины больше, иначе False.
        """
        return self.value > other.value
    
    def __lt__(self, other) -> bool:
        """
        Проверяет, меньше ли значение текущей вершины.
        
        Args:
            other: Другая вершина для сравнения.
            
        Returns:
            True если значение текущей вершины меньше, иначе False.
        """
        return self.value < other.value
    
    def __repr__(self) -> str:
        """
        Возвращает строковое представление вершины.
        
        Returns:
            Строка в формате 'Vertex(value=...)'.
        """
        return f"Vertex(value={self.value})"