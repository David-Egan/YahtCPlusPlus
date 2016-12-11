#ifndef PLAYER_H
#define PLAYER_H

#include "ScoreCard.hpp"
#include "Dice.hpp"
#include <string>
#include <vector>

class GameBoard;

class Player{
	private:
		// This players score sheet
		ScoreCard _scoreCard;
		GameBoard &_gameBoard;
		Dice &_dice;
		std::string _playerName;
		// Make selection return true if selection made, false if dice rerolled
		bool makeScoringSelection(int &rollsLeft, std::vector<int> &diceToKeep);
		void chooseDiceToKeep(std::vector<int> &diceToKeep);
	public:
		Player(std::string playerName, Dice &dice, GameBoard &gameBoard);
		// Begin this players turn
		void startTurn();
		bool hasNoMoreMoves();
		// Getter for player name
		std::string getPlayerName();
		// Check if this player has used up all scoring options
		bool isScoreCardFull();
		void displayScoringOptions();
		void rollDice();
};

#endif
