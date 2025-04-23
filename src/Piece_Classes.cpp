
#include "Piece_Classes.h"

#include <iostream>
#include <string>

using namespace Piece_Classes;

// king constructor and functions

// eg. (17-1) / 8 + 1 = 3 = yLocation = numbers
// eg. (17 - 1) % 8 + 1 = 1 = xLocation = letters
void piece::printLocation() {
  // std::cout << "prints piece location\n";
  std::cout << (char)(((location - 1) % 8 + 1) + 96)
            << (int)((location - 1) / 8 + 1) << std::endl;
}

unsigned char piece::getLocation() {
  // std::cout << "returns a pieces location\n";
  return location;
}

void piece::moveTo(unsigned char location) {
  // std::cout << "moves a piece to a specifed location, does not check if move
  // is valid\n";
}

bool piece::isSpaceOccupied() {  // TODO: (maybe useful for getLegalMove) finish
                                 // definition; will check if a space is
                                 // occupied
  return false;
}

bool piece::getLegalMove(unsigned char location) {
  // std::cout << "Checks if a piece can make specific moove\n";
  return false;
}

king::king() {
  location = 5;  // universal location for e1
}

king::king(unsigned char start) {
  location = start;  // specific location
}

bool king::getLegalMove(unsigned char moveLocation) {
  // needs left-right, up-down, and diagonal conditions
  //  edges will be dealt with out side of this function as well
  return false;
}
