#ifndef SCORECARD_H
#define SCORECARD_H

#include <map>
#include <string>
#include "Dice.hpp"
#include "ScoreType.hpp"

/* Info about a specific scoring option for this specific scoreboard */
struct PlayerScoreOption{
	int possibleValue;
	int scoredValue;
	bool isScored;

	// PlayerScoreOption(int possValue, int scoredValue, bool isScored) :
	// 	possibleValue(possValue), scoredValue(scoredValue), isScored(isScored){}

};

/* Score card for a player */
class ScoreCard{
	private:
		Dice &_dice;
		// TODO: make this map static
		std::map<ScoreType, std::string> _scoringOptions;
		std::map<ScoreType, PlayerScoreOption> _playerOptions;
		void updateOptionsValues();
		void initScoringOptions();
		void initPlayerOptions();
	public:
		ScoreCard(Dice &dice);
		// Show user all their options for scoring this turn
		void displayScoringOptions();
		// Get point value of scoring with a certain value
		// ex. three 5's on the dice would return 15
		int getValueSum(int value);
		// Get score total of all 5 dice
		int getSumOfDice();
		void selectScoringOption(int selection);
};



#endif
