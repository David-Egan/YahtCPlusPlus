#include <iostream>

#include "Dice.hpp"

using namespace std;

Dice::Dice(){
	cout << "Dice Constructed" << endl;
}

void Dice::rollDice(){
	cout << "Rolling Dice\n";
}

/* Get sum of each '1' on dice */
int Dice::getOnesValue(){

	return 1;
}