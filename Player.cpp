/* A Yahtzee player.  Players each have a score card */
#include <string>
#include <iostream>
#include "Player.hpp"

using namespace std;

Player::Player(string playerName, Dice &dice, GameBoard &gameBoard)
			: _playerName(playerName), _dice(dice), _gameBoard(gameBoard),
			  _scoreCard(ScoreCard(dice)){
}

string Player::getPlayerName(){
	return _playerName;
}

int Player::getScore(){
	_scoreCard.getTotalScore();
}

bool Player::hasNoMoreMoves(){
	return _scoreCard.isScoreCardFull();
}

void Player::displayScoringOptions(){
	_scoreCard.displayScoringOptions();
}

void Player::startTurn(){
	int rollsLeft = 3;
	bool selectionMade = false;
	vector<int> diceToKeep;

	cout << "It is " << _playerName << "'s turn.\n";
	cout << "Press ENTER to roll your dice";
	cin.ignore();
	cin.get();

	_dice.rollDice(diceToKeep);
	--rollsLeft;

	while (rollsLeft >= 0 && !selectionMade){
		cout << "Choose how you want your dice to be scored or Re-roll" << endl;
		if (rollsLeft > 0 ) {
			cout << "0. Re-roll" << " {" << rollsLeft << " ROLL(S) LEFT}\n";
		}
		displayScoringOptions();

		selectionMade = makeScoringSelection(rollsLeft, diceToKeep);
		diceToKeep.clear();
	}

	cout << _playerName << "'s score is now: " << _scoreCard.getTotalScore()
		 << endl;
}


bool Player::makeScoringSelection(int &rollsLeft, vector<int> &diceToKeep){
	int scoringSelection = 0;
	string temp;
	bool quit = false;

	cin >> scoringSelection;

	// TODO: clean this up
	while ( (!rollsLeft && scoringSelection == 0) ||
	 		(scoringSelection != 0 && !_scoreCard.scoringSelectionIsValid(scoringSelection))){
		cout << "Pick a valid scoring option\n";
		cin >> scoringSelection;
	}

	if (scoringSelection == 0){
		chooseDiceToKeep(diceToKeep);
		_dice.rollDice(diceToKeep);
		--rollsLeft;
		return false;
	}
	else{
		_scoreCard.selectScoringOption(scoringSelection);
		return true;
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
