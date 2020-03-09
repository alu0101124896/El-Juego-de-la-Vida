#pragma once

#include "cell.hpp"

#include <iostream>
#include <vector>

class Cell;

class Board {
 private:
  int n, m;  // Dimentions of board
  int population;
  std::vector<std::vector<Cell *>> grid;

 public:
  Board();
  Board(int _n, int _m);

  int get_n() const;
  int get_m() const;
  int get_population() const;
  Cell *get_cell(int i, int j);
  Cell *get_cell(int i, int j) const;

  void increment_population();
  void decrement_population();
  void print();
};
