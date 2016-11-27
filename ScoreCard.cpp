#include <iostream>
#include "ScoreCard.hpp"

using namespace std;

ScoreCard::ScoreCard(Dice &dice): _dice(dice) {
	cout << "ScoreCard constructor called" << endl;
	initScoringOptionMap();
}

void ScoreCard::displayScoringOptions(){		
	for ( auto it = _scoringOptions.begin(); it != _scoringOptions.end(); ++it){
		cout << it->first << ". " << "This option" << endl;

	}


	// for (int i = 1; i <= _dice.DICE_AMOUNT; i++){		
	// 	cout << i << ". Sum of all " << i << "'s " << "  ["
	// 		 << getValueSum(i) << "]\n";
	// }

	// cout << _dice.DICE_AMOUNT + 1 << ". Chance: Sum of all 5 dice" << "  ["
	// 	 << getChanceValue() << "]\n";
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

// TODO: if the scoring option is in upper section list
// add to that score and check if bonus is hit
// same for upper
void ScoreCard::selectScoringOption(int selection){
	cout << "In selectScoringOption()" << endl;
}

void ScoreCard::initScoringOptionMap(){	
	_scoringOptions = {
		{ScoreType::AcesSum, make_tuple(0, false)},
		{ScoreType::TwosSum, make_tuple(0, false)},
		{ScoreType::ThreesSum, make_tuple(0, false)},
		{ScoreType::FoursSum, make_tuple(0, false)},
		{ScoreType::FivesSum, make_tuple(0, false)},
		{ScoreType::SixesSum, make_tuple(0, false)},
		{ScoreType::ThreeOfAKind, make_tuple(0, false)},
		{ScoreType::FourOfAKind, make_tuple(0, false)},
		{ScoreType::FullHouse, make_tuple(0, false)},
		{ScoreType::SmallStraight, make_tuple(0, false)},
		{ScoreType::LargeStraight, make_tuple(0, false)},
		{ScoreType::Yahtzee, make_tuple(0, false)},
		{ScoreType::Chance, make_tuple(0, false)}
	};

}