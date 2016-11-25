#ifndef SCORECARD_H
#define SCORECARD_H

#include <map>
#include "Dice.hpp"

/* Score card for a player */
class ScoreCard{
	private:
		Dice &_dice;
	public:			
		ScoreCard(Dice &dice);
		// Show user all their options for scoring this turn
		void displayScoringOptions();
		// Get point value of scoring with a certain value
		// ex. three 5's on the dice would return 15
		int getValueSum(int value);
		// Get score total of all 5 dice
		int getChanceValue();
};

#endif