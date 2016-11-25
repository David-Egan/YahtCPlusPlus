#ifndef PLAYER_H
#define PLAYER_H

#include "ScoreCard.hpp"
#include "Dice.hpp"
#include <string>

class GameBoard;

class Player{
	private:
		// This players score sheet
		ScoreCard _scoreCard;
		GameBoard *_gameBoard;
		Dice *_dice;
		std::string _playerName;
	public:
		Player(std::string playerName, Dice *dice, GameBoard *gameBoard);	
		// Begin this players turn
		void startTurn();
		// Getter for player name
		std::string getPlayerName();
		// Check if this player has used up all scoring options
		bool isScoreCardFull();	
		void displayScoringOptions();
		void rollDice();
};

#endif