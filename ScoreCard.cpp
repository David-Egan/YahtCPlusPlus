#include <iostream>
#include "ScoreCard.hpp"

using namespace std;

ScoreCard::ScoreCard(Dice &dice): _dice(dice) {
	cout << "ScoreCard constructor called" << endl;	
}

void ScoreCard::displayScoringOptions(){		
	for (int i = 1; i <= _dice.DICE_AMOUNT; i++){		
		cout << i << ". Sum of all " << i << "'s " << "  ["
			 << getValueSum(i) << "]\n";
	}

	cout << _dice.DICE_AMOUNT + 1 << ". Chance: Sum of all 5 dice" << "  ["
		 << getChanceValue() << "]\n";
}

int ScoreCard::getValueSum(int value){
	int frequency = _dice.getValueFrequency(value);
	return frequency * value;
}

// could combine this with getValueSum to prevent repeating calls
int ScoreCard::getChanceValue(){
	int diceSum = 0;

	for (int i = 1; i <= _dice.DICE_AMOUNT; i++){
		diceSum += getValueSum(i);
	}

	return diceSum;
}

void ScoreCard::selectScoringOption(int selection){
	cout << "In selectScoringOption()" << endl;
}