#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"

class Board {
 public:
	const int SIZE; 
	
	Board();  // initialize the board with a constructor
	
	void print(const bool whiteView = true);  // prints the current board
	
	unsigned char locationToNumber();
	
	//public so Engine can access it	
	std::vector<std::vector<Piece*>> boardV;

};
