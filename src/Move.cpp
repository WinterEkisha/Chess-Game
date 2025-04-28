#include "Move.h"

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

// Populates move with algebraic notation input
Move::Move(const std::string& notationInput) {
  // First, we take care of edge cases that would cause us to return early.
  // Throwing an exception is not the best way to do this if we are batch
  // analyzing chess games, but for a user input loop it makes sense.

  notation = notationInput;

  if (notation.empty()) throw std::domain_error("Empty notation input.");
  if (notation.size() < 2)
    throw std::domain_error("Notation length must be greater than two.");

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

  // Next, come at the input string from both directions because the middle of
  // the notation is sometimes ambiguous. That way - if both indexes don't meet
  // by the end - then we know we have a rank and/or file qualifiers.

  size_t fwdIdx = 0;
  size_t reverseIdx = notation.size() - 1;

  // --------------------
  // FORWARD SCAN
  // --------------------

  // HANDLE PIECE
  if (isupper(notation[fwdIdx])) {
    switch (notation[fwdIdx]) {
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
    fwdIdx++;
  }

  // --------------------
  // BACKWARD SCAN
  // --------------------

  // HANDLE PROMOTION
  if (notation[reverseIdx] == '=') {
    throw std::domain_error("Promotion piece missing.");
  }

  if (std::string("QRBN").find(notation[reverseIdx]) != std::string::npos) {
    isPromotion = true;
    promotionPiece = notation[reverseIdx];
    --reverseIdx;
    if (reverseIdx >= 0 && notation[reverseIdx] == '=') {
      --reverseIdx;
    }
  }

  // HANDLE TARGET SQUARE
  char rank = notation[reverseIdx];
  char file = notation[--reverseIdx];

  // todo: base on SIZE instead of assumed 8x8 board
  if (file < 'a' || file > 'h') throw std::domain_error("Invalid file letter.");
  if (rank < '1' || rank > '8') throw std::domain_error("Invalid rank number.");

  targetSquareName = {file, rank};  // brace-initialization

  // HANDLE CAPTURE
  if (--reverseIdx >= fwdIdx && notation[reverseIdx] == 'x') {
    isCapture = true;
    --reverseIdx;
  }

  // HANDLE DISAMBIGUATION
  if (fwdIdx && fwdIdx <= reverseIdx) {
    disambiguationId = notation.substr(fwdIdx, reverseIdx);
  }
}

void Move::printParsedResults() {
  std::stringstream output;

  if (pieceType.substr(0, 6) == "castle") {
    output << pieceType << '\n';
  } else {
    output << pieceType;
    if (!disambiguationId.empty()) {
      output << " on " << disambiguationId;
    }
    output << " moves to " << targetSquareName << '\n';
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

  std::cout << output.str() << std::endl;
}

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
