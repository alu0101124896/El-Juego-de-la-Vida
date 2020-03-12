#include "../include/board.hpp"
#include "../include/cell.hpp"

#include <chrono>
#include <iostream>
#include <thread>

// 146x633 - Desktop Arch Linux
// 34x54 - Note 8T Android

int main() {
  int n, m, t, c, i, j;

  std::cout << "Dimensiones de la malla:\n";
  std::cout << "N: ";
  std::cin >> n;
  std::cout << "M: ";
  std::cin >> m;
  std::cout << "Numero de turnos: ";
  std::cin >> t;

  Board board(n, m);

  // std::cout << "Numero de celulas madre: ";
  // std::cin >> c;
  // for (int k = 0; k < c; k++) {
  //   std::cout << "Posicion de la celula madre numero " << k + 1 << ":\n";
  //   std::cout << "i: ";
  //   std::cin >> i;
  //   std::cout << "j: ";
  //   std::cin >> j;

  //   board.get_cell(i, j)->set_alive(true);
  //   board.increment_population();
  //   board.print();
  // }

  for (int j = (m / 2) - 64; j < (m / 2) + 64; j++) {
    board.get_cell(n / 2, j)->set_alive(true);
    board.increment_population();
  }

  for (int k = 1; k <= t; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        board.get_cell(i, j)->count_alive_neighbours(board);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        board.get_cell(i, j)->update_state(board);
      }
    }
    board.print();
    std::cout << "Iteracion: " << k << "\t Poblacion: " << board.get_population()
              << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  std::cout << "Celulas que han permanecido muertas: " 
            << board.get_cells_has_not_been_alive() << "\n";
}
