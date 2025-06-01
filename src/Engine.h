#pragma once

#include "Board.h"

//Will be used for running the game in a class rather than 
//in a while loop in main
//TODO: Define functions
class Engine {
public:
	Engine();  //Starts and runs the game
	
private:
//	Board board(boardSize); //TODO: finish board.cpp
	bool gameIsOver = false;
	bool programIsDone = false;
//	boardSize(int size = 8);  //changes size
//	boardReset();  //Resets the board using the current size
	int boardSize;
};
