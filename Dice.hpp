#ifndef DICE_H
#define DICE_H

#include <array>
#include <map>

class Dice{
	private:		
		std::array<int, 6> _dice;
		int diceSize;
		std::map<int, int> scoringValues;
		// Sums for each dice value eg. 4 ones: {1:4},...		
		// Update values of scoring options based on current dice configuration.
		void updateScoreValues();
		// Change score values back to 0 before next update of their values.	
		void resetScoreValues();
		void createDice();
	public:	
		Dice();
		int id;
		void rollDice();
		// Get number of times a die landed on a given number
		int getValueFrequency(int die);
		
};

#endif