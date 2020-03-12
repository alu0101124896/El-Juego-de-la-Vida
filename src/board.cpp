#include "../include/board.hpp"
#include "../include/cell.hpp"

#include <iostream>
#include <vector>

Board::Board() {}

Board::Board(int _n, int _m) {
  n = _n;
  m = _m;
  population = 0;
  for (int i = 0; i < n + 2; i++) {
    std::vector<Cell *> temp_vect;
    for (int j = 0; j < m + 2; j++) {
      temp_vect.push_back(new Cell(i, j));
    }
    grid.push_back(temp_vect);
  }
}

int Board::get_n() const { return n; }

int Board::get_m() const { return m; }

int Board::get_population() const { return population; }

Cell *Board::get_cell(int i, int j) { return grid.at(i).at(j); }

Cell *Board::get_cell(int i, int j) const { return grid.at(i).at(j); }

int Board::get_cells_has_not_been_alive() const {
  int cells = n * m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (grid.at(i).at(j)->get_has_been_alive())
      {
        cells--;
      }
    }
  }
  return cells;
}

void Board::increment_population() { population++; }

void Board::decrement_population() { population--; }

void Board::print() {
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++) {
      if (i == 0 && j == 0) {
        std::cout << "╔";
      } else if (i == 0 && j == m + 1) {
        std::cout << "╗";
      } else if (i == n + 1 && j == 0) {
        std::cout << "╚";
      } else if (i == n + 1 && j == m + 1) {
        std::cout << "╝";
      } else if (i == 0 || i == n + 1) {
        std::cout << "═";
      } else if (j == 0 || j == m + 1) {
        std::cout << "║";
      } else {
        std::cout << *grid.at(i).at(j);
      }
    }
    std::cout << "\n";
  }
}
