
#pragma once
#include <iostream>
#include <string>

namespace Piece_Classes {

// TODO: 2d array of int maybe easier than char and int,
//  add virtual functions checkLegalMove(),

/*
how piece location works:
@yLocation is the numbers on a chess board
@xLocation is the letters
TODO: could later be optimized to a single variable by using % and /
        eg. (17-1) / 8 + 1 = 3 = yLocation
        eg. (17-1) % 8 + 1 = 1 = A = xLocation

*/

class Piece {
 protected:
  unsigned char xLocation = 0, yLocation = 0, location = 0;
  bool color;         // used to check if piece is white or black
  bool white = true;  // arbitrary t/f for w/b
  bool black = false;

 public:
  void printLocation();  // prints xLocation and yLocation of specific piece
  unsigned char getLocation();          // returns location
  void moveTo(unsigned char location);  // moves piece regardless if it is
                                        // occupied or not a legal move
  bool isSpaceOccupied();
  virtual bool getLegalMove(unsigned char location);
};

class King : public Piece {
 public:
  King();
  King(unsigned char start);
  bool getLegalMove(unsigned char location);
};

class Rook : public Piece {
 public:
};

class Bishop : public Piece {
 public:
};

class Queen : public Piece {
 public:
};

class Pawn : public Piece {
 public:
};

}  // namespace Piece_Classes
