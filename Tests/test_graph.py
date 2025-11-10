from Graph.graph import Graph
from Graph.Exceptions.exceptions import VertexError, EdgeError
import copy
import pytest

def create_graph() -> Graph[int]:
    graph = Graph[int]()
    graph.add_vertex(1)
    graph.add_vertex(2)
    graph.add_edge(1, 2)
    return graph

def test_copy_graph():
    first_graph = create_graph()
    second_graph = copy.deepcopy(first_graph)
    assert first_graph == second_graph
    assert first_graph is not second_graph
    
def test_empty():
    assert Graph[int]().empty()
    graph = create_graph()
    assert not graph.empty()
    
def test_clear():
    graph = create_graph()
    graph.clear()
    assert graph.empty()
    
def test_has_vertex():
    graph = create_graph()
    assert graph.has_vertex(1)
    assert not graph.has_vertex(4)
    
def test_has_edge():
    graph = create_graph()
    assert graph.has_edge(1,2)
    assert not graph.has_edge(3,4)
    
def test_vertex_count():
    graph = create_graph()
    assert graph.vertex_count() == 2
    
def test_edge_count():
    graph = create_graph()
    assert graph.edges_count() == 1
    
def test_vertex_degree():
    graph = create_graph()
    assert graph.vertex_degree(1) == 1
    with pytest.raises(VertexError):
        graph.vertex_degree(4)
        
def test_add_vertex():
    graph = create_graph()
    graph.add_vertex(4)
    assert graph.has_vertex(4)
    assert graph.vertex_count() == 3
    assert graph.vertex_degree(4) == 0
    with pytest.raises(VertexError):
        graph.add_vertex(1)
        
def test_delete_vertex():
    graph = create_graph()
    graph.delete_vertex(1)
    assert graph.vertex_count() == 1
    assert graph.vertex_degree(2) == 0
    assert not graph.has_vertex(1)
    with pytest.raises(VertexError):
        graph.delete_vertex(4)
        
def test_add_edge():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    assert graph.vertex_count() == 3
    assert graph.edges_count() == 2
    assert graph.vertex_degree(1) == 2
    with pytest.raises((EdgeError, VertexError)):
        graph.add_edge(1,1)
        graph.add_edge(5,6)
        graph.add_edge(1,2)
        
def test_delete_edge():
    graph = create_graph()
    graph.delete_edge(1,2)
    assert graph.edges_count() == 0
    assert graph.vertex_degree(1) == 0
    assert graph.vertex_degree(2) == 0
    with pytest.raises((VertexError, EdgeError)):
        graph.delete_edge(1, 1)
        graph.delete_edge(4,7)
        graph.delete_edge(1,2)
        
def test_graph_equality():
    first_graph = create_graph()
    second_graph = create_graph()
    assert first_graph == second_graph
    
def test_graph_inequality():
    first_graph = create_graph()
    second_graph = create_graph()
    second_graph.add_vertex(3)
    second_graph.add_edge(2,3)
    assert first_graph != second_graph
    
def test_graph_less():
    first_graph = create_graph()
    second_graph = create_graph()
    first_graph.delete_vertex(1)
    assert first_graph < second_graph
    
def test_graph_less_or_equal():
    first_graph = create_graph()
    second_graph = create_graph()
    assert first_graph <= second_graph
    first_graph.delete_vertex(1)
    assert first_graph <= second_graph
    
def test_graph_greater():
    first_graph = create_graph()
    second_graph = create_graph()
    first_graph.add_vertex(3)
    first_graph.add_edge(1,3)
    assert first_graph > second_graph
    
def test_graph_greater_or_equal():
    first_graph = create_graph()
    second_graph = create_graph()
    assert first_graph >= second_graph
    first_graph.add_vertex(3)
    first_graph.add_edge(1,3)
    assert first_graph >= second_graph
    
def test_str_method():
    graph = create_graph()
    str_graph = graph.__str__()
    assert str_graph == "Graph(vertices = 1, 2; edges = 1->2)"
    
def test_vertex_iterator():
    graph = create_graph()
    iterator = iter(graph.vertex_iterator())
    assert next(iterator).value == 1
    assert iterator.previous().value == 2
    assert iterator.index == 0
    assert next(iterator).value == 1
    assert next(iterator).value == 2
    with pytest.raises(StopIteration):
        next(iterator)
        
def test_adjacency_vertex_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.adjacency_vertex_iterator(1))
    assert next(iterator).value == 3
    assert next(iterator).value == 2
    with pytest.raises(StopIteration):
        next(iterator)
        
def test_reverse_vertex_iterator():
    graph = create_graph()
    iterator = iter(graph.reverse_vertex_iterator())
    assert next(iterator).value == 2
    assert iterator.previous().value == 1
    assert iterator.index == 1
    assert next(iterator).value == 2
    assert next(iterator).value == 1
    with pytest.raises(StopIteration):
        next(iterator)
    
def test_reverse_adjacency_vertex_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.reverse_adjacency_vertex_iterator(1))
    assert next(iterator).value == 2
    assert next(iterator).value == 3
    with pytest.raises(StopIteration):
        next(iterator)
        
def test_const_vertex_iterator():
    graph = create_graph()
    iterator = iter(graph.const_vertex_iterator())
    assert next(iterator).value == 1
    assert next(iterator).value == 2
    with pytest.raises((AttributeError, StopIteration)):
        iterator.index = 0
        next(iterator)
        
def test_const_adjacency_vertex_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.const_adjacency_vertex_iterator(1))
    assert next(iterator).value == 3
    assert next(iterator).value == 2
    with pytest.raises((AttributeError, StopIteration)):
        iterator.index = 0
        next(iterator)
        
def test_edge_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.edge_iterator())
    next_edge = next(iterator)
    assert (next_edge[0].value, next_edge[1].value) == (1,2)
    previous_edge = iterator.previous()
    assert (previous_edge[0].value, previous_edge[1].value) == (1,3)
    assert iterator.index == 0
    next(iterator)
    next(iterator)
    with pytest.raises(StopIteration):
        next(iterator)
        
def test_incident_edge_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.incident_edge_iterator(2))
    next_edge = next(iterator)
    assert (next_edge[0].value, next_edge[1].value) == (1,2)
    with pytest.raises(StopIteration):
        next(iterator)
        
def test_reverse_edge_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.reverse_edge_iterator())
    next_edge = next(iterator)
    assert (next_edge[0].value, next_edge[1].value) == (1,3)
    previous_edge = iterator.previous()
    assert (previous_edge[0].value, previous_edge[1].value) == (1,2)
    assert iterator.index == 1
    next(iterator)
    next(iterator)
    with pytest.raises(StopIteration):
        next(iterator)
        
def test_reverse_incident_edge_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.reverse_incident_edge_iterator(1))
    next_edge = next(iterator)
    assert (next_edge[0].value, next_edge[1].value) == (1,2)
    assert iterator.index == 0
    next(iterator)
    with pytest.raises(StopIteration):
        next(iterator)
        
def test_const_edge_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.const_edge_iterator())
    next_edge = next(iterator)
    assert (next_edge[0].value, next_edge[1].value) == (1,2)
    previous_edge = iterator.previous()
    assert (previous_edge[0].value, previous_edge[1].value) == (1,3)
    assert iterator.index == 0
    next(iterator)
    next(iterator)
    with pytest.raises((AttributeError,StopIteration)):
        iterator.index = 0
        next(iterator)
        
def test_const_incident_edge_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.const_incident_edge_iterator(1))
    next_edge = next(iterator)
    assert (next_edge[0].value, next_edge[1].value) == (1,3)
    assert iterator.index == 1
    next(iterator)
    with pytest.raises((AttributeError,StopIteration)):
        iterator.index = 0
        next(iterator)
        
def test_const_reverse_edge_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.const_reverse_edge_iterator())
    next_edge = next(iterator)
    assert (next_edge[0].value, next_edge[1].value) == (1,3)
    previous_edge = iterator.previous()
    assert (previous_edge[0].value, previous_edge[1].value) == (1,2)
    assert iterator.index == 1
    next(iterator)
    next(iterator)
    with pytest.raises((AttributeError,StopIteration)):
        iterator.index = 0
        next(iterator)
        
def test_const_reverse_incident_edge_iterator():
    graph = create_graph()
    graph.add_vertex(3)
    graph.add_edge(1,3)
    iterator = iter(graph.const_reverse_incident_edge_iterator(1))
    next_edge = next(iterator)
    assert (next_edge[0].value, next_edge[1].value) == (1,2)
    assert iterator.index == 0
    next(iterator)
    with pytest.raises((AttributeError,StopIteration)):
        iterator.index = 0
        next(iterator)
        
def test_remove_vertex_by_iterator():
    graph = create_graph()
    iterator = iter(graph.vertex_iterator())
    graph.remove_vertex_by_iterator(iterator)
    assert not graph.has_vertex(1)
    assert graph.vertex_count() == 1
    assert graph.edges_count() == 0
    
def test_remove_edge_by_iterator():
    graph = create_graph()
    iterator = iter(graph.edge_iterator())
    graph.remove_edge_by_iterator(iterator)
    assert graph.edges_count() == 0
    assert graph.vertex_degree(1) == 0
    assert graph.vertex_degree(2) == 0