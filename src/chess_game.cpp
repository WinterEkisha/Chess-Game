// Chess Game.cpp : This file contains the 'main' function. Program execution
// begins and ends there. Authors: Luke/WinterEkiska

#include <iostream>
#include <string>

#include "Board.h"
#include "Piece.h"

bool white = true;  // arbitrary t/f for w/b
bool black = false;


int main() {
	Board board;
	King King;  // starts on e1, [5,1]

	// king.printLocation();
	// std::cout << "printing king location: " << (int)king.getLocation();

	board.print(white);
	
	board.print(black);

  return 0;
}
