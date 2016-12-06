#include <iostream>
#include "ScoreCard.hpp"

using namespace std;

ScoreCard::ScoreCard(Dice &dice): _dice(dice) {
	cout << "ScoreCard constructor called" << endl;
	initScoringOptions();
	initPlayerOptions();
}

void ScoreCard::displayScoringOptions(){
	updateOptionsValues();

	auto scoreIt = _scoringOptions.begin();
	auto playerIt = _playerOptions.begin();

	cout << _scoringOptions.size() <<endl;
	while (scoreIt != _scoringOptions.end()){
		cout << scoreIt->first << ". " << scoreIt->second << "  ["
		 		 << playerIt->second.possibleValue << "]"    << endl;

				 scoreIt++;
				 playerIt++;
	}

}

void ScoreCard::updateOptionsValues(){
	// Update all scoring options done by sum of the dice value
 	for (int i = 1; i <= _dice.DICE_AMOUNT; i++){
	 	// The int repesents the scoring option so we can cast it here
	 	ScoreType currScoreType = static_cast<ScoreType>(i);
	}

	// If their conditions are met these scoring values are the sum of the dice
	int sumOfDice = getSumOfDice();

	_playerOptions[ScoreType::Chance].possibleValue = sumOfDice;
	_playerOptions[ScoreType::ThreeOfAKind].possibleValue = sumOfDice;
	_playerOptions[ScoreType::FourOfAKind].possibleValue = sumOfDice;

	//TODO: rest of scoring options (Lower Section

}

int ScoreCard::getValueSum(int value){
	int frequency = _dice.getValueFrequency(value);
	return frequency * value;
}

// could combine this with getValueSum to prevent repeating calls
int ScoreCard::getSumOfDice(){
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

void ScoreCard::initScoringOptions(){
	_scoringOptions[ScoreType::AcesSum] = "Sum of Ones";
	_scoringOptions[ScoreType::TwosSum] = "Sum of Twos";
	_scoringOptions[ScoreType::ThreesSum] = "Sum of Threes";
	_scoringOptions[ScoreType::FoursSum] = "Sum of Fours";
	_scoringOptions[ScoreType::FivesSum] = "Sum of Fives";
	_scoringOptions[ScoreType::SixesSum] = "Sum of Sixes";
	_scoringOptions[ScoreType::ThreeOfAKind] = "Three of a Kind";
	_scoringOptions[ScoreType::FourOfAKind] = "Four of a Kind";
	_scoringOptions[ScoreType::FullHouse] = "Full House";
	_scoringOptions[ScoreType::SmallStraight] = "Small Straight";
	_scoringOptions[ScoreType::LargeStraight] = "Large Straight";
  _scoringOptions[ScoreType::Chance] = "Chance";
	_scoringOptions[ScoreType::Yahtzee] = "Yahtzee";
}

void ScoreCard::initPlayerOptions(){
	// Score values based on certain dice value
	_playerOptions[ScoreType::TwosSum] = {2, -1, false};
	_playerOptions[ScoreType::AcesSum] = {1, -1, false};
	_playerOptions[ScoreType::ThreesSum] = {3, -1, false};
	_playerOptions[ScoreType::FoursSum] = {4, -1, false};
	_playerOptions[ScoreType::FivesSum] = {5, -1, false};
	_playerOptions[ScoreType::SixesSum] = {6, -1, false};
	// Score values based on sum
	_playerOptions[ScoreType::ThreeOfAKind] = {0, -1, false};
	_playerOptions[ScoreType::FourOfAKind] = {0, -1, false};
	_playerOptions[ScoreType::Chance] = {0, -1, false};
	// Constant scoring values
	_playerOptions[ScoreType::FullHouse] = {0, -1, false};
	_playerOptions[ScoreType::SmallStraight] = {0, -1, false};
	_playerOptions[ScoreType::LargeStraight] = {0, -1, false};
	_playerOptions[ScoreType::Yahtzee] = {0, -1, false};
}
