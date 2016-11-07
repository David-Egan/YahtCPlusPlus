#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Player.hpp"
#include <vector>

using namespace std;

class GameBoard{
	private:
		int _dice[5];
		int _playerAmount;
		vector<Player> _players;
		bool playerMovesRemaining();		
	public:
		void setUpBoard();	
		void playGame();		
		GameBoard(int playerAmount);

};

#endif