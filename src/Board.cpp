
#include "Board.h"

#include <iostream>
#include <sstream>

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
      boardStream << "[ ]"; //TODO: add a way to get which piece should go here
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

Board::Board() : SIZE(8){
    boardV.resize(SIZE, std::vector<Piece*>(SIZE));
    //TODO: for loop for each piece type
	for (int i = 0; i < SIZE; i++) {
		//R N B Q K B N Q
		switch (i) {
		case 0:
		boardV[0][i] = new Rook; 
			break;
		case 1:
			//knight
			break;
		case 2:
			//bishop
			break;
		case 3:
			//queen
		case 4:
			//king
		case 5:
			//bishop
		case 6:
			//knight
		case 7:
			//rook
		}
	}
	for (int i = 0; i < SIZE; i++) {
		boardV[1][i] = new Pawn; 
	}
}
