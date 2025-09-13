from unittest import TestCase
from Tic_Tac_Toe.tic_tae_toe import Tic_Tac_Toe
from Tic_Tac_Toe.utils import *


class TestTic_Tac_Toe(TestCase):
    def test_change_turn(self):
        game = Tic_Tac_Toe(3)
        game.change_turn()
        self.assertTrue(game.player == "O")
        
    def test_win_check_True(self):
        game = Tic_Tac_Toe(3)
        game[(0, 0)], game[(1,1)], game[(2,2)] = [game.player for _ in range(3)]
        self.assertTrue(game.win_check())
        
    def test_win_check_False(self):
        game = Tic_Tac_Toe(3)
        game[(0, 0)] = game.player
        self.assertFalse(game.win_check())
        
    def test_draw_check_True(self):
        game = Tic_Tac_Toe(3)
        game[(0, 1)], game[(1,0)], game[(1,1)], game[(2, 0)], game[(2,2)] = ["X" for _ in range(5)]
        game[(0, 0)], game[(0,2)], game[(1,2)], game[(2,1)] = ["O" for _ in range(4)]
        self.assertTrue(game.draw_check())
        
    def test_draw_check_False(self):
        game = Tic_Tac_Toe(3)
        game[(1, 1)] = "X"
        self.assertFalse(game.draw_check())
        
    def test_getitem_and_setitem(self):
        game = Tic_Tac_Toe(3)
        game[(1, 1)] = "X"
        self.assertTrue(game[(1, 1)] == "X")