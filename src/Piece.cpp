
#include "Piece.h"

#include <iostream>
#include <string>

using namespace Piece_Classes;

// King constructor and functions

// eg. (17-1) / 8 + 1 = 3 = yLocation = numbers
// eg. (17 - 1) % 8 + 1 = 1 = xLocation = letters
void Piece::printLocation() {
  // std::cout << "prints piece location\n";
  std::cout << (char)(((location - 1) % 8 + 1) + 96)
            << (int)((location - 1) / 8 + 1) << std::endl;
}

unsigned char Piece::getLocation() {
  // std::cout << "returns a pieces location\n";
  return location;
}

void Piece::moveTo(unsigned char location) {
  // std::cout << "moves a piece to a specifed location, does not check if move
  // is valid\n";
}

bool Piece::isSpaceOccupied() {  // TODO: (maybe useful for getLegalMove) finish
                                 // definition; will check if a space is
                                 // occupied
  return false;
}

bool Piece::getLegalMove(unsigned char location) {
  // std::cout << "Checks if a piece can make specific moove\n";
  return false;
}

King::King() {
  location = 5;  // universal location for e1
}

King::King(unsigned char start) {
  location = start;  // specific location
}

bool King::getLegalMove(unsigned char moveLocation) {
  // needs left-right, up-down, and diagonal conditions
  //  edges will be dealt with out side of this function as well
  return false;
}
