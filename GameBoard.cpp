/* Game state holder especially including dice values */
#include <iostream>
#include "GameBoard.hpp"
#include "ScoreCard.hpp"

using namespace std;

// GameBoard constructor.  Takes in amount of players who will be
// playing with this board
GameBoard::GameBoard(int playerAmount){
	_playerAmount = playerAmount;
	cout << "GameBoard object constructed\n";
}

// Set up board for a game.
void GameBoard::setUpBoard(){			
	cout << "The Gameboard has " << _playerAmount << " players" << endl;
	
	for (int i = 0; i < _playerAmount; ++i){
		_players.push_back( Player("Player" + to_string(i)) );
	}


	for (Player p : _players){
		cout << "Player " << p.getPlayerName() << endl;
		// [  (p._scoreCard->myMethod());  ] Example of how to call method from ScoreCard
	}

}

// Main game loop
void GameBoard::playGame(){
	//while ( playerMovesRemaining()){
	

		for ( Player p : _players){
			p.startTurn();
		}
		
}


// // Check if the players have moves left ie. scorecard has a spot that can be filled. 
bool GameBoard::playerMovesRemaining(){
	cout << "Player Moves Remaining called\n";
	for ( Player p : _players){
			if (p.isScoreCardFull()){
				return false;
			}
	
	}

	return true;
}




// Create board and other relevant entities to play the game.
// Introduce user to game.
GameBoard initializeBoard(){
	int playerAmount;

	cout << "Welcome to Yahtzee!\n";
	cout << "Enter the amount of players: ";
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