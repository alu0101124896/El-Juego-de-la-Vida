#include "../include/cell.hpp"
#include "../include/board.hpp"

#include <iostream>

Cell::Cell() {}

Cell::Cell(int _i, int _j, bool _alive) {
  i = _i;
  j = _j;
  alive = _alive;
}

bool Cell::is_alive() const { return alive; }

int Cell::get_i() const { return i; }

int Cell::get_j() const { return j; }

int Cell::get_alive_neighbours() const { return alive_neighbours; }

void Cell::set_alive(bool _alive) { alive = _alive; }

void Cell::count_alive_neighbours(const Board& board) {
  alive_neighbours = 0;
  if (board.get_cell(i - 1, j - 1).is_alive()) {
    alive_neighbours++;
  }
  if (board.get_cell(i - 1, j).is_alive()) {
    alive_neighbours++;
  }
  if (board.get_cell(i - 1, j + 1).is_alive()) {
    alive_neighbours++;
  }
  if (board.get_cell(i, j - 1).is_alive()) {
    alive_neighbours++;
  }
  if (board.get_cell(i, j + 1).is_alive()) {
    alive_neighbours++;
  }
  if (board.get_cell(i + 1, j - 1).is_alive()) {
    alive_neighbours++;
  }
  if (board.get_cell(i + 1, j).is_alive()) {
    alive_neighbours++;
  }
  if (board.get_cell(i + 1, j + 1).is_alive()) {
    alive_neighbours++;
  }
}

void Cell::update_state(Board& board) {
  if (alive && alive_neighbours != 3 && alive_neighbours != 2) {
    alive = false;
    board.decrement_population();
  } else if (!alive && alive_neighbours == 3) {
    alive = true;
    board.increment_population();
  }
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.is_alive()) {
    os << "█";
  } else {
    os << " ";
  }
  return os;
}
