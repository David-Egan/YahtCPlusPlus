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
		// Constant score value, values
		static const int FULL_HOUSE_VAL = 25;
		static const int SMALL_STRAIGHT_VAL = 30;
		static const int LARGE_STRAIGHT_VAL = 40;
		static const int YAHTZEE_VAL = 50;
		static const int UPPER_SECTION_BONUS = 35;
		const std::array<ScoreType, 6> _upperSectionOptions = {{
			ScoreType::AcesSum,
			ScoreType::TwosSum,
			ScoreType::ThreesSum,
			ScoreType::FoursSum,
			ScoreType::FivesSum,
			ScoreType::SixesSum,
		}};
		const int NEEDED_FOR_UPPER_BONUS = 63;
		int upperSectionTotal;
		std::map<ScoreType, std::string> _scoringOptions;
		std::map<ScoreType, PlayerScoreOption> _playerOptions;
		void updateOptionsValues();
		void initScoringOptions();
		void initPlayerOptions();
	public:
		ScoreCard(Dice &dice);
		int getTotalScore();
		bool isScoreCardFull();
		bool scoringSelectionIsValid(int scoringSelection);
		// Show user all their options for scoring this turn
		void displayScoringOptions();
		int totalScore;
		// Get point value of scoring with a certain value
		// ex. three 5's on the dice would return 15
		int getValueSum(int value);
		// Get score total of all 5 dice
		int getSumOfDice();
		void selectScoringOption(int selection);
};



#endif
