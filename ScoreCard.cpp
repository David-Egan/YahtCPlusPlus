#include <iostream>
#include "ScoreCard.hpp"


using namespace std;

ScoreCard::ScoreCard(Dice *dice){
	_dice = dice;
	cout << "ScoreCard constructed" << endl;	
}

void ScoreCard::displayScoringOptions(){
	int oneValue = 3535262;
	cout << "1. Ones\n" << "  [" << oneValue << "]\n";
}