"""
    Модуль, реализующий граф, представленный в виде модифицированной структуры Вирта
"""
from typing import Optional, TypeVar, List, Tuple, Generic
from Graph.vertex import Vertex
from Graph.edge import Edge
from Graph.Exceptions.exceptions import *
from Graph.Iterators.edgeiterators import *
from Graph.Iterators.vertexiterators import *
import logging
import copy


T = TypeVar("T")

class Graph(Generic[T]):
    """
    Реализация неориентированного графа на основе модифицированной структуры Вирта.
    
    Граф представлен в виде списка вершин и списка ребер, где каждая вершина
    содержит ссылки на списки предшественников и последователей.
    
    Тип T представляет тип данных, хранимых в вершинах графа.
    
    Attributes:
        _head: Указатель на начальную вершину графа.
        _tail: Указатель на последнюю вершину графа.
        _verticies: Список вершин графа.
        _edges: Список ребер графа.
    """
    
    __log = logging.getLogger(__name__)
    logging.basicConfig(filename="graph_log.log", level=logging.INFO)
    
    def __init__(self) -> None:
        """
        Инициализирует пустой граф.
        
        Создает граф с пустыми списками вершин и ребер, 
        а также с неопределенными начальной и конечной вершинами.
        """
        self._head: Optional[Vertex[T]] = None
        self._tail: Optional[Vertex[T]] = None
        self._vertices: List[Vertex[T]] = []
        self._edges: List[Tuple[Vertex[T], Vertex[T]]] = []
        
    def __del__(self) -> None:
        """Деструктор графа, логирующий удаление графа."""
        Graph.__log.debug("Graph is delete")
        
    def __deepcopy__(self, memo: dict) -> 'Graph[T]':
        """
        Создает глубокую копию графа.
        
        Копирует все вершины и ребра графа, создавая
        новый независимый объект графа с идентичной структурой.
        
        Args:
            memo: Словарь для отслеживания уже скопированных объектов
            
        Returns:
            Новая копия графа
        """
        new_graph: Graph[T] = Graph()
        memo[id(self)] = new_graph
        
        for vertex in self._vertices:
            new_graph.add_vertex(copy.deepcopy(vertex.value, memo))
        
        for v1, v2 in self._edges:
            new_graph.add_edge(
                copy.deepcopy(v1.value, memo), 
                copy.deepcopy(v2.value, memo)
            )
        
        return new_graph
        
    def _find_vertex(self, value: T) -> Optional[Vertex[T]]:
        """
        Находит вершину по значению в связном списке вершин.
        
        Args:
            value: Значение для поиска
            
        Returns:
            Найденная вершина или None если вершина не найдена
        """
        current = self._head
        while current:
            if current.value == value:
                return current
            current = current.next
            
        return None
    
    def _get_incident_edges(self, vertex: Vertex[T]) -> List[Tuple[Vertex[T], Vertex[T]]]:
        """
        Возвращает список всех инцидентных ребер для заданной вершины.
        
        Инцидентные ребра включают как входящие, так и исходящие связи.
        
        Args:
            vertex: Вершина, для которой ищутся инцидентные ребра
            
        Returns:
            Список кортежей, представляющих инцидентные ребра
        """
        incident_edges = []
        current = vertex.trail
        while current:
            trail_edge = tuple(sorted([current.target_vertex, vertex]))
            if trail_edge not in incident_edges:
                incident_edges.append(trail_edge)
                
            current = current.next
                
        current = vertex.pred
        while current:
            pred_edge = tuple(sorted([current.target_vertex, vertex]))
            if pred_edge not in incident_edges:
                incident_edges.append(pred_edge)
                
            current = current.next
                
        return incident_edges
    
    def _get_adjacency_vertecies(self, vertex: Vertex[T]) -> List[Vertex[T]]:
        """
        Возвращает список смежных вершин для заданной вершины.
        
        Смежные вершины - это все вершины, соединенные с данной ребрами.
        
        Args:
            vertex: Вершина, для которой ищутся смежные вершины
            
        Returns:
            Список смежных вершин
        """
        adjancy_vertecies = []
        current = vertex.trail
        while current:
            adjency_vertex = current.target_vertex
            if adjency_vertex not in adjancy_vertecies:
                adjancy_vertecies.append(adjency_vertex)
                
            current = current.next
                
        current = vertex.pred
        while current:
            adjency_vertex = current.target_vertex
            if adjency_vertex not in adjancy_vertecies:
                adjancy_vertecies.append(adjency_vertex)
                
            current = current.next
                
        return adjancy_vertecies
            
    def _add_directed_edge(self, vertex_a: Vertex[T], vertex_b: Vertex[T]) -> None:
        """
        Добавляет направленное ребро от vertex_a к vertex_b.
        
        Обновляет списки смежности обеих вершин и увеличивает счетчики связей.
        
        Args:
            vertex_a: Начальная вершина ребра
            vertex_b: Конечная вершина ребра
        """
        trail_edge = Edge(vertex_b)
        trail_edge.next = vertex_a.trail
        vertex_a.trail = trail_edge
        vertex_a.count_next += 1
        
        pred_edge = Edge(vertex_a)
        pred_edge.next = vertex_b.pred
        vertex_b.pred = pred_edge
        vertex_b.count_prev += 1
        
    def _remove_directed_edge(self, vertex_a: Vertex[T], vertex_b: Vertex[T]) -> None:
        """
        Удаляет направленное ребро от vertex_a к vertex_b.
        
        Обновляет списки смежности обеих вершин и уменьшает счетчики связей.
        
        Args:
            vertex_a: Начальная вершина ребра
            vertex_b: Конечная вершина ребра
        """
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
        """
        Создает новую вершину и добавляет ее в граф.
        
        Обновляет связный список вершин и список всех вершин графа.
        
        Args:
            value: Значение новой вершины
        """
        new_vertex = Vertex(value)
        if self._head is None and self._tail is None:
            self._head = new_vertex
            self._tail = new_vertex
        else:
            if self._tail:
                self._tail.next = new_vertex
                self._tail = new_vertex
                
        self._vertices.append(new_vertex)
                
    def _remove_vertex(self, value: T) -> None:
        """
        Удаляет вершину из графа вместе со всеми инцидентными ребрами.
        
        Args:
            value: Значение вершины для удаления
        """
        vertex = self._find_vertex(value)
        if not vertex:
            return
        
        edges_to_remove = []
        for edge in self._edges:
            if edge[0] == vertex or edge[1] == vertex:
                edges_to_remove.append(edge)
                
        for edge in edges_to_remove:
            self._edges.remove(edge)
        
        current = self._head
        while current:
            if current != vertex:
                self._remove_directed_edge(current, vertex)
                self._remove_directed_edge(vertex, current)
            current = current.next
            
        if vertex == self._head:
            self._head = vertex.next
            if vertex == self._tail:
                self._head = self._tail
        else:
            current = self._head
            while current:
                if current and current.next == vertex:
                    current.next = vertex.next
                    if vertex == self._tail:
                        self._tail = current
                        
                    break 
                current = current.next
                
        self._vertices.remove(vertex)
        
    def empty(self) -> bool:
        """
        Проверяет, является ли граф пустым.
        
        Returns:
            True если граф не содержит вершин, иначе False
        """
        return self._head is None
    
    def clear(self) -> None:
        """
        Полностью очищает граф, удаляя все вершины и ребра.
        """
        current = self._head
        while current:
            vertex_to_del = current
            current = current.next
            self.delete_vertex(vertex_to_del.value)
            
        self._head = self._tail = None
        self._vertices = []
        self._edges = []

    def has_vertex(self, value: T) -> bool:
        """
        Проверяет наличие вершины с заданным значением в графе.
        
        Args:
            value: Значение для поиска
            
        Returns:
            True если вершина найдена, иначе False
        """
        return self._find_vertex(value) is not None
    
    def has_edge(self, value_a: T, value_b: T) -> bool:
        """
        Проверяет наличие ребра между вершинами с заданными значениями.
        
        Args:
            value_a: Значение первой вершины
            value_b: Значение второй вершины
            
        Returns:
            True если ребро существует, иначе False
        """
        vertex_a = self._find_vertex(value_a)
        vertex_b = self._find_vertex(value_b)
        
        if vertex_a is None or vertex_b is None:
            return False
        
        edge = tuple(sorted([vertex_a, vertex_b]))
        
        return edge in self._edges
                    
    def vertex_count(self) -> int:
        """
        Возвращает количество вершин в графе.
        
        Returns:
            Количество вершин
        """
        return len(self._vertices)
        
    def edges_count(self) -> int:
        """
        Возвращает количество ребер в графе.
        
        Returns:
            Количество ребер
        """
        return len(self._edges)
        
    def vertex_degree(self, value: T) -> int:
        """
        Вычисляет степень вершины с заданным значением.
        
        Args:
            value: Значение вершины
            
        Returns:
            Степень вершины
            
        Raises:
            VertexError: Если вершина с заданным значением не найдена
        """
        vertex = self._find_vertex(value)
        if vertex is None:
            raise VertexError("Vertex is not found")
        
        return vertex.degree
    
    def add_vertex(self, value: T) -> None:
        """
        Добавляет новую вершину в граф.
        
        Args:
            value: Значение новой вершины
            
        Raises:
            VertexError: Если вершина с таким значением уже существует
        """
        if self.has_vertex(value):
            raise VertexError("Vertex is already in graph")
        
        self._create_vertex(value)
        
    def delete_vertex(self, value: T) -> None:
        """
        Удаляет вершину с заданным значением из графа.
        
        Args:
            value: Значение вершины для удаления
            
        Raises:
            VertexError: Если вершина с заданным значением не найдена
        """
        if not self.has_vertex(value):
            raise VertexError("Vertex is not in graph")
        
        self._remove_vertex(value)
        
    def add_edge(self, value_a: T, value_b: T) -> None:
        """
        Добавляет ребро между вершинами с заданными значениями.
        
        Args:
            value_a: Значение первой вершины
            value_b: Значение второй вершины
            
        Raises:
            VertexError: Если одна или обе вершины не найдены, 
                        или если вершины совпадают
            EdgeError: Если ребро уже существует в графе
        """
        vertex_a = self._find_vertex(value_a)
        vertex_b = self._find_vertex(value_b)
        
        if vertex_a is None or vertex_b is None:
            raise VertexError("One or both vertecies not found")
        
        if vertex_a == vertex_b:
            raise VertexError("Same vertex")
        
        edge = tuple(sorted([vertex_a, vertex_b]))
        
        if edge in self._edges:
            raise EdgeError("Edge is already in graph")
        
        self._add_directed_edge(vertex_a, vertex_b)
        self._add_directed_edge(vertex_b, vertex_a)
        self._edges.append(edge)
            
    def delete_edge(self, value_a: T, value_b: T) -> None:
        """
        Удаляет ребро между вершинами с заданными значениями.
        
        Args:
            value_a: Значение первой вершины
            value_b: Значение второй вершины
            
        Raises:
            VertexError: Если одна или обе вершины не найдены, 
                        или если вершины совпадают
            EdgeError: Если ребро не существует в графе
        """
        vertex_a = self._find_vertex(value_a)
        vertex_b = self._find_vertex(value_b)
        
        if vertex_a == vertex_b:
            raise VertexError("Same vertex")
        
        if not vertex_a or not vertex_b:
            raise VertexError("One of the vertieces is not in graph")
        
        edge = tuple(sorted([vertex_a, vertex_b]))
        
        if edge not in self._edges:
            raise EdgeError("Edge is not in graph")
        
        self._remove_directed_edge(vertex_a, vertex_b)
        self._remove_directed_edge(vertex_b, vertex_a)
        self._edges.remove(edge)
        
    
    def vertex_iterator(self) -> BiDirectionalVertexIterator[T]:
        """Возвращает итератор по всем вершинам графа."""
        return BiDirectionalVertexIterator(self._vertices)
    
    def adjacency_vertex_iterator(self, vertex_value: T) -> BiDirectionalVertexIterator[T]:
        """
        Возвращает итератор по смежным вершинам для заданной вершины.
        
        Args:
            vertex_value: Значение вершины
            
        Returns:
            Итератор по смежным вершинам
            
        Raises:
            VertexError: Если вершина не найдена
        """
        vertex = self._find_vertex(vertex_value)
        if not vertex:
            raise VertexError("Vetrex is not in graph")
        
        adjacency_vertecies = self._get_adjacency_vertecies(vertex)
        return BiDirectionalVertexIterator(adjacency_vertecies)
    
    def reverse_vertex_iterator(self) -> BiDirectionalVertexIterator[T]:
        """Возвращает обратный итератор по всем вершинам графа."""
        return BiDirectionalVertexIterator(self._vertices, reverse=True)
    
    def reverse_adjacency_vertex_iterator(self, vertex_value: T) -> BiDirectionalVertexIterator[T]:
        """
        Возвращает обратный итератор по смежным вершинам.
        
        Args:
            vertex_value: Значение вершины
            
        Returns:
            Обратный итератор по смежным вершинам
            
        Raises:
            VertexError: Если вершина не найдена
        """
        vertex = self._find_vertex(vertex_value)
        if not vertex:
            raise VertexError("Vetrex is not in graph")
        
        adjacency_vertecies = self._get_adjacency_vertecies(vertex)
        return BiDirectionalVertexIterator(adjacency_vertecies, reverse=True)
    
    def const_vertex_iterator(self) -> ConstBiDirectionalVertexIterator[T]:
        """Возвращает константный итератор по всем вершинам графа."""
        return ConstBiDirectionalVertexIterator(self._vertices)
    
    def const_adjacency_vertex_iterator(self, vertex_value: T) -> ConstBiDirectionalVertexIterator[T]:
        """
        Возвращает константный итератор по смежным вершинам.
        
        Args:
            vertex_value: Значение вершины
            
        Returns:
            Константный итератор по смежным вершинам
            
        Raises:
            VertexError: Если вершина не найдена
        """
        vertex = self._find_vertex(vertex_value)
        if not vertex:
            raise VertexError("Vetrex is not in graph")
        
        adjacency_vertecies = self._get_adjacency_vertecies(vertex)
        return ConstBiDirectionalVertexIterator(adjacency_vertecies)
    
    def const_reverse_vertex_iterator(self) -> ConstBiDirectionalVertexIterator[T]:
        """Возвращает константный обратный итератор по всем вершинам графа."""
        return ConstBiDirectionalVertexIterator(self._vertices, reverse=True)
    
    def const_reverse_adjacency_vertex_iterator(self, vertex_value: T) -> ConstBiDirectionalVertexIterator[T]:
        """
        Возвращает константный обратный итератор по смежным вершинам.
        
        Args:
            vertex_value: Значение вершины
            
        Returns:
            Константный обратный итератор по смежным вершинам
            
        Raises:
            VertexError: Если вершина не найдена
        """
        vertex = self._find_vertex(vertex_value)
        if not vertex:
            raise VertexError("Vetrex is not in graph")
        
        adjacency_vertecies = self._get_adjacency_vertecies(vertex)
        return ConstBiDirectionalVertexIterator(adjacency_vertecies, reverse=True)
    
    
    def edge_iterator(self) -> BiDirectionalEdgeIterator[T]:
        """Возвращает итератор по всем ребрам графа."""
        return BiDirectionalEdgeIterator(self._edges)
    
    def incident_edge_iterator(self, vertex_value: T) -> BiDirectionalEdgeIterator[T]:
        """
        Возвращает итератор по инцидентным ребрам для заданной вершины.
        
        Args:
            vertex_value: Значение вершины
            
        Returns:
            Итератор по инцидентным ребрам
            
        Raises:
            VertexError: Если вершина не найдена
        """
        vertex = self._find_vertex(vertex_value)
        if not vertex:
            raise VertexError("Vetrex is not in graph")
        
        incident_edges = self._get_incident_edges(vertex)
        return BiDirectionalEdgeIterator(incident_edges)
    
    def reverse_edge_iterator(self) -> BiDirectionalEdgeIterator[T]:
        """Возвращает обратный итератор по всем ребрам графа."""
        return BiDirectionalEdgeIterator(self._edges, reverse=True)
    
    def reverse_incident_edge_iterator(self, vertex_value: T) -> BiDirectionalEdgeIterator[T]:
        """
        Возвращает обратный итератор по инцидентным ребрам.
        
        Args:
            vertex_value: Значение вершины
            
        Returns:
            Обратный итератор по инцидентным ребрам
            
        Raises:
            VertexError: Если вершина не найдена
        """
        vertex = self._find_vertex(vertex_value)
        if not vertex:
            raise VertexError("Vetrex is not in graph")
        
        incident_edges = self._get_incident_edges(vertex)
        return BiDirectionalEdgeIterator(incident_edges, reverse=True)
    
    def const_edge_iterator(self) -> ConstBiDirectionalEdgeIterator[T]:
        """Возвращает константный итератор по всем ребрам графа."""
        return ConstBiDirectionalEdgeIterator(self._edges)
    
    def const_incident_edge_iterator(self, vertex_value: T) -> ConstBiDirectionalEdgeIterator[T]:
        """
        Возвращает константный итератор по инцидентным ребрам.
        
        Args:
            vertex_value: Значение вершины
            
        Returns:
            Константный итератор по инцидентным ребрам
            
        Raises:
            VertexError: Если вершина не найдена
        """
        vertex = self._find_vertex(vertex_value)
        if not vertex:
            raise VertexError("Vetrex is not in graph")
        
        incident_edges = self._get_incident_edges(vertex)
        return ConstBiDirectionalEdgeIterator(incident_edges)
    
    def const_reverse_edge_iterator(self) -> ConstBiDirectionalEdgeIterator[T]:
        """Возвращает константный обратный итератор по всем ребрам графа."""
        return ConstBiDirectionalEdgeIterator(self._edges, reverse=True)
    
    def const_reverse_incident_edge_iterator(self, vertex_value: T) -> ConstBiDirectionalEdgeIterator[T]:
        """
        Возвращает константный обратный итератор по инцидентным ребрам.
        
        Args:
            vertex_value: Значение вершины
            
        Returns:
            Константный обратный итератор по инцидентным ребрам
            
        Raises:
            VertexError: Если вершина не найдена
        """
        vertex = self._find_vertex(vertex_value)
        if not vertex:
            raise VertexError("Vetrex is not in graph")
        
        incident_edges = self._get_incident_edges(vertex)
        return ConstBiDirectionalEdgeIterator(incident_edges, reverse=True)
    
    def remove_vertex_by_iterator(self, iterator: BiDirectionalVertexIterator[T]) -> None:
        """
        Удаляет вершину, на которую указывает итератор.
        
        Args:
            iterator: Итератор, указывающий на удаляемую вершину
        """
        vertex_value = iterator.current().value
        self.delete_vertex(vertex_value)
        
    def remove_edge_by_iterator(self, iterator: BiDirectionalEdgeIterator[T]) -> None:
        """
        Удаляет ребро, на которое указывает итератор.
        
        Args:
            iterator: Итератор, указывающий на удаляемое ребро
        """
        value_a, value_b = [vertex.value for vertex in iterator.current()]
        self.delete_edge(value_a, value_b)
        
    def __eq__(self, other) -> bool:
        """
        Проверяет равенство графов.
        
        Два графа считаются равными, если они содержат одинаковые
        множества вершин и ребер.
        
        Args:
            other: Другой граф для сравнения
            
        Returns:
            True если графы равны, иначе False
        """
        self_vertices = {vertex.value for vertex in self._vertices}
        other_vertices = {vertex.value for vertex in other._vertices}
        
        self_edges = {tuple(sorted([edge[0].value, edge[1].value])) for edge in self._edges}
        other_edges = {tuple(sorted([edge[0].value, edge[1].value])) for edge in other._edges}
        
        return self_vertices == other_vertices and self_edges == other_edges
    
    def __ne__(self, other) -> bool:
        """
        Проверяет неравенство графов.
        
        Args:
            other: Другой граф для сравнения
            
        Returns:
            True если графы не равны, иначе False
        """
        return not self.__eq__(other)
    
    def __lt__(self, other) -> bool:
        """
        Проверяет, является ли данный граф меньшим чем другой.
        
        Сравнение производится сначала по количеству вершин,
        затем по количеству ребер.
        
        Args:
            other: Другой граф для сравнения
            
        Returns:
            True если данный граф меньше other, иначе False
        """
        if self.vertex_count() != other.vertex_count():
            return self.vertex_count() < other.vertex_count()
        return self.edges_count() < other.edges_count()
    
    def __gt__(self, other) -> bool:
        """
        Проверяет, является ли данный граф большим чем другой.
        
        Args:
            other: Другой граф для сравнения
            
        Returns:
            True если данный граф больше other, иначе False
        """
        return other < self
    
    def __le__(self, other) -> bool:
        """
        Проверяет, является ли данный граф меньшим или равным другому.
        
        Args:
            other: Другой граф для сравнения
            
        Returns:
            True если данный граф меньше или равен other, иначе False
        """
        return self < other or self == other 
    
    def __ge__(self, other) -> bool:
        """
        Проверяет, является ли данный граф большим или равным другому.
        
        Args:
            other: Другой граф для сравнения
            
        Returns:
            True если данный граф больше или равен other, иначе False
        """
        return self > other or self == other
    
    def __str__(self) -> str:
        """
        Возвращает строковое представление графа.
        
        Returns:
            Строка, содержащая информацию о вершинах и ребрах графа
        """
        graph_vertecies = ", ".join([str(vertex.value) for vertex in self._vertices])
        graph_edges = ", ".join([f"{edge[0].value}->{edge[1].value}" for edge in self._edges])
        return f"Graph(vertices = {graph_vertecies}; edges = {graph_edges})"