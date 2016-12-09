#include <iostream>

#include <initializer_list>
#include <algorithm>
#include "Dice.hpp"

using namespace std;


/* TODO: consider using the observer pattern to update ScoreCard
   when Dice are rolled.  Concern with this is we would update
   all scorecards when we just need to update the current one.
*/

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
	resetScoreOptions();

	int currDieNumber = 0;

	for (int i = 0; i < 5; ++i){
		currDieNumber = _dice[i];
		scoringValues[currDieNumber]++;
	}	

	//FindLowerSectionBools
	int ascendingValueCount = 0;
	int maxAscendingValueCount = 0;
	bool exactlyTwoOfAKind = 0;

	for (std::map<int, int>::iterator it = scoringValues.begin();
	 							it != scoringValues.end(); ++it ){
		// Check if we have at 3 of ONE kind and 2 of ANOTHER
		if (it->second == 2) exactlyTwoOfAKind = true;

		switch(it->second){
			case 5: yahtzee = true;
			case 4: fourOfAKind = true;
			case 3: threeOfAKind = true;
		}
		// Count how many consecutive times values occur
		if (it->second >= 1 ){
			ascendingValueCount++;
		}
		else{
			if (ascendingValueCount >= maxAscendingValueCount){
				maxAscendingValueCount = ascendingValueCount;
			}
			ascendingValueCount = 0;
		}
	}

	switch (maxAscendingValueCount){
		case 5: largeStraight = true;
		case 4: smallStraight = true;
	}

	if (exactlyTwoOfAKind && threeOfAKind) {fullHouse = true;}
}

void Dice::resetScoreValues(){
	for ( std::map<int,int>::iterator it = scoringValues.begin();
								 it != scoringValues.end(); ++it){
		it->second = 0;
	}
}

void Dice::resetScoreOptions(){
	threeOfAKind = false;
	fourOfAKind = false;
	smallStraight = false;
	largeStraight = false;
	fullHouse = false;
	yahtzee = false;
}

int Dice::getValueFrequency(int scoringOption){
	return scoringValues[scoringOption];
}

bool Dice::hasThreeOfAKind() {return threeOfAKind;}
bool Dice::hasFourOfAKind() {return fourOfAKind;}
bool Dice::hasSmallStraight() {return smallStraight;}
bool Dice::hasLargeStraight() {return largeStraight;}
bool Dice::hasFullHouse() {return fullHouse;}
bool Dice::hasYahtzee() {return yahtzee;}
