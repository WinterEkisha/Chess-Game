
#include "Board.h"

#include <iostream>
#include <sstream>
#include <string>

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

void Board::parseAlgebraicNotation(const std::string notation) {
  // Edge cases:
  // Castling
  // Disambiguation (two pieces can move to the same row, col, or both)
  // Captures
  // Promotions
  // Check and Checkmate

  // Proposed data shapes, possibly make global?
  //   struct Square {
  //     int row;
  //     char col;
  //   };

  enum PieceType {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN,
    CASTLE_KING,
    CASTLE_QUEEN,
  };

  enum Modifier {
    CHECK,
    CHECKMATE,
    CAPTURE,
    PROMOTION,
  };

  //   PieceType pieceType;
  //   std::vector<Modifier> modifiers;

  //   if (notation.size() < 2) {
  //     throw std::domain_error("Notation length must be two or greater.");
  //   }

  //   char row = notation[notation.size() - 2];
  //   int col = static_cast<int>(notation[notation.size() - 1]);

  //   if (col < 0 || col > SIZE) {
  //     throw std::domain_error("Column outside of range");
  //   }

  //   if (row < 0 || row > SIZE) {
  //     throw std::domain_error("Row outside of range");
  //   }

  //   std::cout << "ROW: " << row << "\nCOL: " << col << '\n';

  //   if (notation.size() == 2) {
  //     pieceType = PAWN;
  //   }
};
