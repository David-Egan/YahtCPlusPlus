#ifndef PLAYER_H
#define PLAYER_H

#include "ScoreCard.hpp"
#include <string>

class GameBoard;

class Player{
	private:
		ScoreCard *_scoreCard;
		GameBoard *_gameBoard;
		Dice *_dice;
		std::string _playerName;
	public:			
		Player(std::string playerName, Dice *dice, GameBoard *gameBoard);	
		void startTurn();
		std::string getPlayerName();
		bool isScoreCardFull();
		void displayScoringOptions();
		void rollDice();
};

#endif