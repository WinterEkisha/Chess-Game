#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

#include "Board.h"

struct Move {
  Move(const std::string& notationInput);

  std::string notation;
  std::string pieceType = "pawn";
  std::string targetSquareName = "";
  bool isCheck = false;
  bool isCheckmate = false;
  bool isCapture = false;
  bool isPromotion = false;
  std::string promotionPiece = "";

  void printParsedResults();
};

void test_move();
