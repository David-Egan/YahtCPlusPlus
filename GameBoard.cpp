/* Game state holder especially including dice values */
#include <iostream>
#include "GameBoard.hpp"

using namespace std;

// Set up board for a game.
void GameBoard::setUpBoard(){		
	cout << "The Gameboard has " << playerAmount << " players" << endl;
	//while (playerMovesRemaining()){
		//iterate through players
			//prompt for roll
			//prompt for scoring decision
	//}
}
	
// Check if the players have moves left ie. scorecard has a spot
// that can be filled. 
bool GameBoard::playerMovesRemaining(){
	cout << "Player Moves Remaining called\n";
}

// GameBoard constructor.  Takes in amount of players who will be
// playing with this board
GameBoard::GameBoard(int _playerAmount){
	playerAmount = _playerAmount;
	cout << "GameBoard object constructed\n";
}
