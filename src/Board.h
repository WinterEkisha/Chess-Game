#pragma once

#include <iostream>
#include <string>

#include "Piece.h"

class Board {
 public:
  const int SIZE = 8;

  int boardInit();   // initialized the board
  int boardPrint();  // prints the current board

  unsigned char locationToNumber();

 private:
  // TODO: maybe useful to store array here for each piece and square
};
