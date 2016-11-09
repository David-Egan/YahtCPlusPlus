#ifndef SCORECARD_H
#define SCORECARD_H

/* Score card for a player */
class ScoreCard{
	private:
		bool onesScored = false;
		bool twosScored = false;
		bool threesScored = false;
		bool foursScored = false;
		bool fivesScored = false;
		bool sixesScored = false;
	public:			
		ScoreCard();
		void displayScoringOptions ();		
};

#endif