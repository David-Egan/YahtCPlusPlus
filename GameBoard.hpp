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
		// Check if the players have moves left ie. scorecard has a spot 
		// that can be filled. 
		bool playerMovesRemaining();				
	public:
		// Set up board for a game.
		void setUpBoard();
		// Main game loop	
		void playGame();
		// GameBoard constructor.  Takes in amount of players who will be
		// playing with this board		
		GameBoard(int playerAmount); 
};

#endif