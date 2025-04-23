
#include "Piece_Classes.h"

#include <iostream>
#include <string>

// king constructor and functions

// eg. (17-1) / 8 + 1 = 3 = yLocation = numbers
// eg. (17 - 1) % 8 + 1 = 1 = xLocation = letters
void Piece_Classes::piece::printLocation() {
  // std::cout << "prints piece location\n";
  std::cout << (char)(((location - 1) % 8 + 1) + 96)
            << (int)((location - 1) / 8 + 1) << std::endl;
}

unsigned char Piece_Classes::piece::getLocation() {
  // std::cout << "returns a pieces location\n";
  return location;
}

void Piece_Classes::piece::moveTo(unsigned char location) {
  // std::cout << "moves a piece to a specifed location, does not check if move
  // is valid\n";
}

bool Piece_Classes::piece::
    isSpaceOccupied() {  // TODO: (maybe useful for getLegalMove) finish
                         // definition; will check if a space is occupied
  return false;
}

bool Piece_Classes::piece::getLegalMove(unsigned char location) {
  // std::cout << "Checks if a piece can make specific moove\n";
  return false;
}

Piece_Classes::king::king() {
  location = 5;  // universal location for e1
}

Piece_Classes::king::king(unsigned char start) {
  location = start;  // specific location
}

bool Piece_Classes::king::getLegalMove(unsigned char moveLocation) {
  // needs left-right, up-down, and diagonal conditions
  //  edges will be dealt with out side of this function as well
  return false;
}
