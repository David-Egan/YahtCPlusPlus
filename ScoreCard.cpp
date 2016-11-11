#include <iostream>
#include "ScoreCard.hpp"


using namespace std;

ScoreCard::ScoreCard(Dice *dice){
	_dice = dice;
	cout << "ScoreCard constructed" << endl;
}

void ScoreCard::displayScoringOptions(){
	cout << "1. Ones";
}