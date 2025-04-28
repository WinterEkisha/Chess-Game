#include "Move.h"

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

void test_move() {
  std::string notationInput;
  std::cout << "Input chess notation (Enter 'q' to QUIT):\n";
  while (std::cin >> notationInput && notationInput != "q") {
    try {
      Move move(notationInput);
      move.printParsedResults();

    } catch (const std::exception& e) {
      std::cout << e.what() << '\n';
      continue;
    }
  }
}

Move::Move(const std::string& notationInput) {
  if (notationInput.empty()) throw std::domain_error("Empty notation input.");
  if (notationInput.size() < 2)
    throw std::domain_error("Notation length must be greater than two.");

  notation = notationInput;

  // HANDLE CHECKS
  if (notation.back() == '+') {
    isCheck = true;
    notation.pop_back();

  } else if (notation.back() == '#') {
    isCheck = true;
    isCheckmate = true;
    notation.pop_back();
  }

  // HANDLE CASTLE
  if (notation == "O-O") {
    pieceType = "castle kingside";
    return;

  } else if (notation == "O-O-O") {
    pieceType = "castle queenside";
    return;
  }

  size_t idx = 0;

  // HANDLE PIECE
  if (isupper(notation[idx])) {
    switch (notation[idx]) {
      case 'N':
        pieceType = "knight";
        break;
      case 'B':
        pieceType = "bishop";
        break;
      case 'R':
        pieceType = "rook";
        break;
      case 'Q':
        pieceType = "queen";
        break;
      case 'K':
        pieceType = "king";
        break;
      default:
        throw std::domain_error("Unknown piece type.");
    }
    idx++;
  }

  // todo: HANDLE DISAMBIGUATION
  // sometimes a file or rank comes before 'x' or destination

  // HANDLE CAPTURE
  if (idx < notation.size() && notation[idx] == 'x') {
    isCapture = true;
    idx++;
  }

  // HANDLE TARGET SQUARE
  if (idx + 1 >= notation.size()) {
    throw std::domain_error("Target square missing.");
  }

  char file = notation[idx];
  char rank = notation[idx + 1];

  // todo: base on SIZE instead of assumed 8x8 board
  if (file < 'a' || file > 'h') throw std::domain_error("Invalid file letter.");
  if (rank < '1' || rank > '8') throw std::domain_error("Invalid rank number.");

  targetSquareName = std::string(1, file) + std::string(1, rank);
  idx += 2;

  // HANDLE PROMOTION
  if (idx < notation.size() && notation[idx] == '=') {
    idx++;
    if (idx >= notation.size()) {
      throw std::domain_error("Promotion piece missing.");
    }
    isPromotion = true;
    promotionPiece = notation[idx];
  }

  return;
}

void Move::printParsedResults() {
  std::stringstream output;

  if (pieceType.substr(0, 6) == "castle") {
    output << pieceType << '\n';
  } else {
    output << pieceType << " moves to " << targetSquareName << '\n';
  }

  if (isCheckmate) {
    output << "Checkmate" << '\n';
  } else if (isCheck) {
    output << "Check" << '\n';
  }

  if (isCapture) {
    output << "Capture" << '\n';
  }

  if (isPromotion) {
    output << "Promotion to " << promotionPiece << '\n';
  }

  std::cout << output.str() << std::flush;
}
