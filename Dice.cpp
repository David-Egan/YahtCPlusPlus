#include <iostream>

#include <initializer_list>
#include "Dice.hpp"

using namespace std;

Dice::Dice(){	
	scoringValues = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}};
	diceSize = 6;
	// Pretty sure we are safe not initializing dice values so we'll
	// leave this commented out for now
	/* 
	auto diceInit = std::initializer_list<int>{0,0,0,0,0,0};
	std::copy(diceInit.begin(), diceInit.end(), _dice);
	*/
	
	cout << "Dice Constructed" << endl;	
	rollDice();
	
}

void Dice::rollDice(){
	cout << "Rolling Dice\n";	
	srand(time(NULL));	
		
	//TODO: try to shorten type definition for iterator
	for ( int i = 0; i < diceSize; ++i){
	// Generate value between 1 and 6 '1 +' ensures it's never 0
		int rollValue = 1 + (rand() % 6);
		_dice[i] = rollValue;
	}
	
	updateScoreValues();
}

void Dice::updateScoreValues(){
	resetScoreValues();

	int currDieNumber;

	for (int i = 0; i < diceSize; ++i){
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


//int getOnesValue

//void isStraight()

//void isYahtzee()
