#ifndef PLAYER_H
#define PLAYER_H

#include "ScoreCard.hpp"
#include <string>

using namespace std;

class Player{
	private:
		ScoreCard *_scoreCard;
		std::string _playerName;
	public:			
		Player(std::string playerName);	
		string getPlayerName();
};

#endif