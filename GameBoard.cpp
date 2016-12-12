/* Game state holder especially including dice values */
#include <iostream>
#include "GameBoard.hpp"

using namespace std;
//
GameBoard::GameBoard(int playerAmount){
	_playerAmount = playerAmount;
 }

void GameBoard::setUpBoard(){
	for (int i = 0; i < _playerAmount; ++i){
		// are these two lines good design?
		Player *newPlayer = new Player("Player #" + to_string(i), _dice, *this);
		_players.push_back( newPlayer );
	}
}

void GameBoard::playGame(){
	while ( playerMovesRemaining() ){
		for ( Player *p : _players){
			p->startTurn();
		}
	}
	endGame();
}

void GameBoard::endGame(){
	// Collection of players to track ties
	vector<Player*> winners;
	// One of the players who currently has the best score to be compared against
	int currWinningScore = 0;

	for (Player *p : _players){
		if ( p->getScore() > currWinningScore){
			winners.clear();
			winners.push_back(p);
			currWinningScore = p->getScore();
		}
		else if (p->getScore() == currWinningScore){
			cout << "equal" << endl;
			winners.push_back(p);
		}
	}

	if (winners.size() > 1) cout << "The winner are: " << endl;
	else cout << "The winners are: ";

	for (Player *p : winners){
		cout << p->getPlayerName() << " [" << p->getScore() << "]" << endl;
	}
}

bool GameBoard::playerMovesRemaining(){
	// Doesn't matter which player we look
	Player *firstPlayer = _players.front();

	return !( firstPlayer->hasNoMoreMoves() );
}

// Create board and other relevant entities to play the game.
// Introduce user to game.
GameBoard initializeBoard(){
	int playerAmount;

	cout << "Welcome to Yahtzee!\n";
	cout << "How many players are there? ";
	cin >> playerAmount;

	GameBoard gameBoard(playerAmount);
	return gameBoard;
}


int main(){
	GameBoard gameBoard = initializeBoard();
	gameBoard.setUpBoard();
	gameBoard.playGame();

	cout << "Thanks for playing\n";
	return 0;
}
