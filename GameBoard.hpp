#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Dice.hpp"
#include "Player.hpp"
#include <vector>

class Player;

class GameBoard{
	private:
		Dice _dice;
		int _playerAmount;
		std::vector<Player> _players;
		bool playerMovesRemaining();
		void rollDice();		
	public:
		void setUpBoard();	
		void playGame();		
		GameBoard(int playerAmount); 
};

#endif