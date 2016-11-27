#include <iostream>

#include <initializer_list>
#include <algorithm>
#include "Dice.hpp"

using namespace std;


Dice::Dice(){
	_dice = {{0,0,0,0,0}};
	scoringValues = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}};
}

//TODO: Don't roll dice in indexes that diceToKeep contain 
// eg. if diceToKeep has a 0 then don't re-roll the first die
void Dice::rollDice(vector<int> diceToKeep){		
	// seed for random number generator
	srand(time(NULL));	
	for ( int i = 0; i < DICE_AMOUNT; ++i){
		if(!( std::find(diceToKeep.begin(), diceToKeep.end(), i+1) 
				!= diceToKeep.end())){
	// Generate value between 1 and 5 '1 +' ensures it's never 0
			int rollValue = 1 + (rand() % DICE_AMOUNT);
			_dice[i] = rollValue;			
		}
		cout << "Die " << i+1 << ": [" <<  _dice[i] << "]" << "  ";
	}
	cout << endl;

	updateScoreValues();	
}

void Dice::updateScoreValues(){	
	resetScoreValues();	
	int currDieNumber;

	for (int i = 0; i < 6; ++i){
		currDieNumber = _dice[i];			
		scoringValues[currDieNumber]++;				
	}
	
}


void Dice::resetScoreValues(){	
	for ( std::map<int,int>::iterator it = scoringValues.begin(); 
				it != scoringValues.end(); ++it){		
		it->second = 0;
	}	
}

int Dice::getValueFrequency(int scoringOption){
	return scoringValues[scoringOption];
}

// STUB
bool isStraight(){
	return true;
}


//void isYahtzee()
