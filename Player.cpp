/* A Yahtzee player.  Players each have a score card */
#include <string>
#include <iostream>
#include "Player.hpp"

using namespace std;

Player::Player(string playerName, Dice &dice, GameBoard &gameBoard) 
			: _playerName(playerName), _dice(dice), _gameBoard(gameBoard),
			  _scoreCard(ScoreCard(dice)){		
	cout << "player constructor called\n";
}

string Player::getPlayerName(){
	return _playerName;
} 

bool Player::isScoreCardFull(){

}

void Player::displayScoringOptions(){
	_scoreCard.displayScoringOptions();	
}

void Player::startTurn(){
	int scoringSelection;

	cout << "It is " << _playerName << "'s turn.\n" <<
		"Press ENTER to roll your dice";
	cin.ignore();
	cin.get();
	_dice.rollDice();

	cout << "Choose how you want your dice to be scored" << endl;
	displayScoringOptions();

	cin >> scoringSelection;
	
	//allow selection of scoring option through ScoreBoard object  
}

