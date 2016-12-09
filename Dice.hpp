#ifndef DICE_H
#define DICE_H

#include <array>
#include <vector>
#include <map>

// TODO: Make singleton with getInstance call that only allows 1 instance

class Dice{
	private:
		std::array<int, 5> _dice;
		// Sums for each dice value eg. 4 ones: {1:4},...
		std::map<int, int> scoringValues;
		// Update values of scoring options based on current dice configuration.
		void updateScoreValues();
		// Change score values back to 0 before next update of their values.
		void resetScoreValues();
		void resetScoreOptions();
		void createDice();
		bool threeOfAKind = false;
		bool fourOfAKind = false;
		bool smallStraight = false;
		bool largeStraight = false;
		bool fullHouse = false;
		bool yahtzee = false;
	public:
		Dice();
		const int DICE_AMOUNT  = 5;
		void rollDice(std::vector<int> diceToKeep);
		// Get number of times a die landed on a given number
		int getValueFrequency(int die);
		bool hasThreeOfAKind();
		bool hasFourOfAKind();
		bool hasSmallStraight();
		bool hasLargeStraight();
		bool hasFullHouse();
		bool hasYahtzee();

};

#endif
