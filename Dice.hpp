#ifndef DICE_H
#define DICE_H

#include <array>
#include <vector>
#include <map>

class Dice{
	private:		
		std::array<int, 6> _dice;		
		// Sums for each dice value eg. 4 ones: {1:4},...	
		std::map<int, int> scoringValues;		
		// Update values of scoring options based on current dice configuration.
		void updateScoreValues();
		// Change score values back to 0 before next update of their values.	
		void resetScoreValues();
		void createDice();
	public:	
		Dice();
		const int DICE_AMOUNT  = 5;
		void rollDice(std::vector<int> diceToKeep);
		// Get number of times a die landed on a given number
		int getValueFrequency(int die);
		
};

#endif