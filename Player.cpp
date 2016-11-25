/* A Yahtzee player.  Players each have a score card */
#include <string>
#include <iostream>
#include <vector>
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
	int scoringSelection = 0;
	int rollsLeft = 3;
	string temp;
	bool quit = false;
	vector<int> diceToKeep;

	cout << "It is " << _playerName << "'s turn.\n";
	
	cout << "Press ENTER to roll your dice";
	cin.ignore();
	cin.get();	
	

	while (rollsLeft > 0){				
		rollsLeft--;

		_dice.rollDice(diceToKeep);							
		
		cout << "Choose how you want your dice to be scored or Re-roll" << endl;
		if (rollsLeft > 0 ) {
			cout << "0. Re-roll\n";
		}
		displayScoringOptions();

		cout << rollsLeft << " roll(s) left\n";

		cin >> scoringSelection;
		while (rollsLeft == 0 && scoringSelection == 0){
			cout << "No re-rolls left, choose a way to score your dice\n";
			cin >> scoringSelection;
		}

		if (scoringSelection == 0){
			cout << "Select the number under a die to keep it." 
			     << " Enter 'f' when you are finished making your selections\n";
					

			while (!quit){
				cin >> temp;

				if (temp == "f" || diceToKeep.size() == 4 ){
					quit = true;
				}
				else{
					// convert string to int
					diceToKeep.push_back(atoi(temp.c_str()));
				}
			}			
		}
		else{	
			_scoreCard.selectScoringOption(scoringSelection);
			return;
		}				
	}	



		
	

	


	

	
	//allow selection of scoring option through ScoreBoard object  
}

