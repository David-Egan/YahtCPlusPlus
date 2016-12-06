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
	int rollsLeft = 3;
	vector<int> diceToKeep;

	cout << "It is " << _playerName << "'s turn.\n";
	cout << "Press ENTER to roll your dice";
	cin.ignore();
	cin.get();

	_dice.rollDice(diceToKeep);
	--rollsLeft;

	while (rollsLeft >= 0){
		cout << "Choose how you want your dice to be scored or Re-roll" << endl;
		if (rollsLeft > 0 ) { cout << "0. Re-roll\n"; }
		displayScoringOptions();

		cout << rollsLeft << " roll(s) left\n";
		makeScoringSelection(rollsLeft, diceToKeep);
		diceToKeep.clear();
	}
}


void Player::makeScoringSelection(int &rollsLeft, vector<int> &diceToKeep){
	int scoringSelection = 0;
	string temp;
	bool quit = false;

	cin >> scoringSelection;
	while (!rollsLeft && scoringSelection == 0){
		cout << "No re-rolls left, choose a way to score your dice\n";
		cin >> scoringSelection;
	}

	if (scoringSelection != 0){
		_scoreCard.selectScoringOption(scoringSelection);
		return;
	}
	else{
		chooseDiceToKeep(diceToKeep);
		_dice.rollDice(diceToKeep);
		--rollsLeft;
	}

}

void Player::chooseDiceToKeep(vector<int> &diceToKeep){
		bool quit = false;
		string temp;

		cout << "Select the number under a die to keep it."
		     << " Enter 'f' when you are finished making your selections\n";

		while (!quit && diceToKeep.size() < 4){
			cin >> temp;

			if (temp == "f"){
				quit = true;
			}
			else{
				diceToKeep.push_back(atoi(temp.c_str()));
			}
		}
		quit = false;
}
