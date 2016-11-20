#ifndef DICE_H
#define DICE_H

#include <map>

class Dice{
	private:
		// not using a vector just to
		// get to know c arrays a little more
		int  _dice[6];
		int diceSize;
		std::map<int, int> scoringValues;
		// Sums for each dice value eg. 4 ones: {1:4},...		
		// Update values of scoring options based on current dice configuration.
		void updateScoreValues();
		// Change score values back to 0 before next update of their values.	
		void resetScoreValues();
		void createDice();
	public:		
		void rollDice();
		// Get number a given die landed on
		int getDieNumber(int die);
		Dice();
};

#endif