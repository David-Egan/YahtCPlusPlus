#include <iostream>
#include "ScoreCard.hpp"

using namespace std;

ScoreCard::ScoreCard(Dice &dice): _dice(dice) {
	cout << "ScorecCard constructor called" << endl;	
}

void ScoreCard::displayScoringOptions(){		
	
	cout << "1. Ones" << "  [" << _dice.getValueFrequency(1) << "]\n";
}