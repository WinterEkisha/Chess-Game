
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
	  boardStream << "[" << boardV[i][j]->boardPrintHelper() << "]"; //TODO: add way to tell which piece is what color
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
	for (int i = 0; i < SIZE; i++) { //initialize empty pieces to avoid invalid memory accessing errors
		for (int j = 0; j < SIZE; j++)
			boardV[i][j] = new emptyPiece();
	}
	for (int i = 0; i < SIZE; i++) { //WHITE PIECES
		//R N B Q K B N Q
		switch (i) {
		case 0:
		case 7:
			boardV[0][i] = new Rook(true);
			break;
		case 1:
		case 6:
			boardV[0][i] = new Knight(true);
			break;
		case 2:
		case 5:
			boardV[0][i] = new Bishop(true);
			break;
		case 3:
			boardV[0][i] = new Queen(true);
			break;
		case 4:
			boardV[0][i] = new Queen(true); //TODO: change to King() after testing
			break;
		}
	}
	for (int i = 0; i < SIZE; i++) { //WHITE PAWNS
		boardV[1][i] = new Pawn(true); 
	}
	for (int i = 0; i < SIZE; i++) { //BLACK PIECES
		//R N B Q K B N Q
		switch (i) {
		case 0:
		case 7:
			boardV[SIZE - 1][i] = new Rook(false);
			break;
		case 1:
		case 6:
			//knight
			boardV[SIZE - 1][i] = new Knight(false);
			break;
		case 2:
		case 5:
			//bishop
			boardV[SIZE - 1][i] = new Bishop(false);
			break;
		case 3:
			//queen
			boardV[SIZE - 1][i] = new Queen(false);
			break;
		case 4:
			//king
			boardV[SIZE - 1][i] = new Queen(false); //TODO: change to King() after testing
			break;
		}
	}
	for (int i = 0; i < SIZE; i++) { //BLACK PAWNS
		boardV[SIZE - 2][i] = new Pawn(false); 
	}
	
}
