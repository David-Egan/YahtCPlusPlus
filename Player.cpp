/* A Yahtzee player.  Players each have a score card */
#include <string>
#include <iostream>
#include "Player.hpp"
#include "ScoreCard.hpp"

using namespace std;

Player::Player(string playerName, Dice *dice, GameBoard *gameBoard) 
			: _playerName(playerName), _dice(dice), _gameBoard(gameBoard){	
	_gameBoard = gameBoard;
	cout << "player constructor called\n";
	ScoreCard _scoreCard(dice);
}

string Player::getPlayerName(){
	return _playerName;
} 

bool Player::isScoreCardFull(){

}

void Player::displayScoringOptions(){
	_scoreCard->displayScoringOptions();
}

void Player::startTurn(){
	int scoringSelection;

	cout << "It is " << _playerName << "'s turn.\n" <<
		"Press any key to roll your dice\n";
	cin.ignore();
	cin.get();


	cout << "Choose how you want your dice to be scored" << endl;
	displayScoringOptions();

	cin >> scoringSelection;
	//dice.rollDice();
	
	
	// displayScoringOptions();
	
	//ScoreBoard.checkforoptions
	//for each option print out  
}

void Player::rollDice(){

}