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
		void displayScoringOptions();
};

#endif