#ifndef GAMEBOARD_H
#define GAMEBOARD_H

using namespace std;

class GameBoard{
	public:
		int dice[5];
		int playerAmount;

		GameBoard(int playerAmount);
		void setUpBoard();	
		bool playerMovesRemaining();

};

#endif