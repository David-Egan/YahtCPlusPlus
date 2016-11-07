/* A Yahtzee player.  Players each have a score card */
#include <string>
#include <iostream>
#include "Player.hpp"
#include "ScoreCard.hpp"

using namespace std;

Player::Player(string playerName) : _playerName(playerName){
	cout << "player constructor called\n";
	ScoreCard *_scoreCard;
}

string Player::getPlayerName(){
	return _playerName;
} 