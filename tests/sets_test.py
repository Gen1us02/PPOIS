from unittest import TestCase
from Set.sets import Set
from Set.utils import *


class TestSets(TestCase):
    def test_add_True(self):
        elem = "{a, b}"
        self.assertTrue(Set("").add(elem))
        
    def test_add_False(self):
        elem = "aj-ka;"
        self.assertFalse(Set("").add(elem))
        
    def test_del_elem_True(self):
        test_set = Set("{1, 2, 3, 4, 5}")
        elem = '1'
        self.assertTrue(test_set.del_elem(elem))
        
    def test_del_elem_False(self):
        test_set = Set("{a, b, {c, d}, f, g}")
        elem = 'ab'
        self.assertFalse(test_set.del_elem(elem))
        
    def test_is_empty_True(self):
        self.assertTrue(Set("").is_empty())
    
    def test_is_empty_False(self):
        self.assertFalse(Set("{1, 2}").is_empty())
        
    def test_power(self):
        self.assertTrue(Set("{a, abc, {cde}, 7}").power() == 4)
        
    def test_boolean(self):
        test_set = Set("{1, 2, 3}")
        self.assertTrue(test_set.boolean() == "{{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}}")
        
    def test_operator_add(self):
        union_set = Set("{1, 2, 3}") + Set("{abc}")
        self.assertTrue(union_set.set == ["1", "2", "3", "abc"])
        
    def test_operator_add_with_asigment(self):
        union_set = Set("{a, b, c}")
        union_set += Set("{1, 2, 3}")
        self.assertTrue(union_set.set == ["a", "b", "c", "1", "2", "3"])
        
    def test_operator_sub(self):
        difference_set = Set("{1, 2, 3, 6}") - Set("{2, 3, 4, 5}")
        self.assertTrue(difference_set.set == ["1", "6"])
        
    def test_operator_sub_with_asigment(self):
        diff_set = Set("{a, b, c, {}, {d, e, f}}")
        diff_set -= Set("{a, b, c}")
        self.assertTrue(diff_set.set == ["{d,e,f}", "{}"])
        
    def test_operator_mul(self):
        inter_set = Set("{100, 80, 34, 92}") * Set("{100, 34, 53, 12}")
        self.assertTrue(inter_set.set == ["100", "34"])
        
    def test_operator_mul_with_asigment(self):
        inter_set = Set("{a, b, c, {}, {d, e, f}}")
        inter_set *= Set("{a, b, c}")
        self.assertTrue(inter_set.set == ["a", "b", "c"])
        
    def test_contains_True(self):
        elem = "67"
        self.assertTrue(elem in Set("{1, 2, 35, 67, 88}"))
        
    def test_contains_False(self):
        elem = "157"
        self.assertFalse(elem in Set("{a, abc, {d,f,g}, 88}"))
        
    def test_remove_duplicates(self):
        test_set_list = ["1", "1", "2", "35", "73", "2"]
        self.assertTrue(remove_duplicates(test_set_list) == ["1", "2", "35", "73"])
        
    def test_convert_to_string(self):
        test_set_list = ["f", "g", "{h,i,k}", "103"]
        self.assertTrue(convert_to_string(test_set_list) == "{f,g,{h,i,k},103}")
        
    def test_convert_to_list(self):
        test_set_string = "{45, 86, 190, 33, 20}"
        self.assertTrue(convert_to_list(test_set_string) == ["45", "86", "190", "33", "20"])
        
    def test_sort_set(self):
        set_for_sort = "{2, 1, 3, 5}"
        self.assertTrue(sort_set(set_for_sort) == "{1,2,3,5}")
        
    def test_breckets_check_True(self):
        breckets_sequence = "{{}, {{{}}}, {{}}}"
        self.assertTrue(breckets_check(breckets_sequence))
        
    def test_breckets_check_False(self):
        breckets_sequence = "{{, {{{}, {{}}"
        self.assertFalse(breckets_check(breckets_sequence))
        
    def test_is_valid_elem_True(self):
        elem = "13649"
        self.assertTrue(is_valid_elem(elem))
        
    def test_is_valid_elem_False(self):
        elem = ";klaks nmcas"
        self.assertFalse(is_valid_elem(elem))
        
    def test_is_correct_set_True(self):
        test_set = "{adc, 123, {34, 103, ofk}}"
        self.assertTrue(is_correct_set(test_set))
        
    def test_is_correct_set_False(self):
        test_set = "ad-c, 123, msn2ksl, {34, 103, ofk}}"
        self.assertFalse(is_correct_set(test_set))