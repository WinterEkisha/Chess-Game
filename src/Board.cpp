
#include "Board.h"

#include <cctype>
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

struct Move {
  std::string notation;
  std::string pieceType = "pawn";
  std::string targetSquareName = "";
  bool isCheck = false;
  bool isCheckmate = false;
  bool isCapture = false;
  bool isPromotion = false;
  std::string promotionPiece = "";

  Move(std::string notation) : notation(notation) {}
};

void printParsedResults(const Move& move) {
  std::stringstream output;

  if (move.pieceType.substr(0, 6) == "castle") {
    output << move.pieceType << '\n';
  } else {
    output << move.pieceType << " moves to " << move.targetSquareName << '\n';
  }

  if (move.isCheckmate) {
    output << "Checkmate" << '\n';
  } else if (move.isCheck) {
    output << "Check" << '\n';
  }

  if (move.isCapture) {
    output << "Capture" << '\n';
  }

  if (move.isPromotion) {
    output << "Promotion to " << move.promotionPiece << '\n';
  }

  std::cout << output.str() << std::flush;
}

Move parseAlgebraicNotation(const std::string& notationInput) {
  if (notationInput.empty()) throw std::domain_error("Empty notation input.");
  if (notationInput.size() < 2)
    throw std::domain_error("Notation length must be greater than two.");

  Move move(notationInput);

  // HANDLE CHECKS
  if (move.notation.back() == '+') {
    move.isCheck = true;
    move.notation.pop_back();

  } else if (move.notation.back() == '#') {
    move.isCheck = true;
    move.isCheckmate = true;
    move.notation.pop_back();
  }

  // HANDLE CASTLE
  if (move.notation == "O-O") {
    move.pieceType = "castle kingside";
    return move;

  } else if (move.notation == "O-O-O") {
    move.pieceType = "castle queenside";
    return move;
  }

  size_t idx = 0;

  // HANDLE PIECE
  if (isupper(move.notation[idx])) {
    switch (move.notation[idx]) {
      case 'N':
        move.pieceType = "knight";
        break;
      case 'B':
        move.pieceType = "bishop";
        break;
      case 'R':
        move.pieceType = "rook";
        break;
      case 'Q':
        move.pieceType = "queen";
        break;
      case 'K':
        move.pieceType = "king";
        break;
      default:
        throw std::domain_error("Unknown piece type.");
    }
    idx++;
  }

  // todo: HANDLE DISAMBIGUATION
  // sometimes a file or rank comes before 'x' or destination

  // HANDLE CAPTURE
  if (idx < move.notation.size() && move.notation[idx] == 'x') {
    move.isCapture = true;
    idx++;
  }

  // HANDLE TARGET SQUARE
  if (idx + 1 >= move.notation.size()) {
    throw std::domain_error("Target square missing.");
  }

  char file = move.notation[idx];
  char rank = move.notation[idx + 1];

  // todo: base on SIZE instead of assumed 8x8 board
  if (file < 'a' || file > 'h') throw std::domain_error("Invalid file letter.");
  if (rank < '1' || rank > '8') throw std::domain_error("Invalid rank number.");

  move.targetSquareName = std::string(1, file) + std::string(1, rank);
  idx += 2;

  // HANDLE PROMOTION
  if (idx < move.notation.size() && move.notation[idx] == '=') {
    idx++;
    if (idx >= move.notation.size()) {
      throw std::domain_error("Promotion piece missing.");
    }
    move.isPromotion = true;
    move.promotionPiece = move.notation[idx];
  }

  return move;
}

void test_parseAlgebraicNotation() {
  std::string notationInput;
  std::cout << "Input chess notation (Enter 'q' to QUIT):\n";
  while (std::cin >> notationInput && notationInput != "q") {
    try {
      Move move = parseAlgebraicNotation(notationInput);
      printParsedResults(move);

    } catch (const std::exception& e) {
      std::cout << e.what() << '\n';
      continue;
    }
  }
}
