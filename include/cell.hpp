#pragma once

#include "board.hpp"

#include <iostream>

class Board;

class Cell {
 private:
  bool alive;
  int i, j;  // Position on board
  int alive_neighbours;

 public:
  Cell();
  Cell(int _i, int _j, bool _alive = false);

  bool is_alive() const;
  int get_i() const;
  int get_j() const;
  int get_alive_neighbours() const;

  void set_alive(bool _alive);

  void count_alive_neighbours(const Board& board);
  void update_state(Board& board);

  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};
