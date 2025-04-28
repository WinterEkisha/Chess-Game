#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"

class Board {
 public:
  const size_t SIZE;

  Board() : SIZE(8) {};  // initialize the board with a constructor

  void print(const bool whiteView = true);  // prints the current board

  unsigned char locationToNumber();

 private:
  // TODO: maybe useful to store array here for each piece and square
  std::vector<Piece_Classes::Piece> pieces;
};
