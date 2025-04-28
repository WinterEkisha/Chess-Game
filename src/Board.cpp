
#include "Board.h"

#include <iostream>
#include <sstream>

#include "Piece.h"

void Board::print(const bool whiteView) {
  std::stringstream boardStream;

  // iterating through squares regular / reverse doesn't have an effect when
  // board is empty but will be useful when we pass a array with pieces into it
  const int start_idx = whiteView ? 0 : SIZE - 1;
  const int end_idx = whiteView ? SIZE : -1;
  const int step = whiteView ? 1 : -1;

  // board contents and row indices
  for (int i = start_idx; i != end_idx; i += step) {
    boardStream << SIZE - i;
    for (int j = start_idx; j != end_idx; j += step) {
      boardStream << "[ ]";
    }
    boardStream << '\n';
  }

  // column indices
  boardStream << ' ';  // compensate for index column
  for (int j = start_idx; j != end_idx; j += step) {
    const char indexChar = 'A' + j;
    boardStream << ' ' << indexChar << ' ';
  }

  // prints to console and immediately flushes the buffer
  std::cout << boardStream.str() << std::endl;
}
