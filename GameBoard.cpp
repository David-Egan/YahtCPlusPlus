/* Game state holder especially including dice values */
#include <iostream>
#include "GameBoard.hpp"

using namespace std;
//
GameBoard::GameBoard(int playerAmount){
	_playerAmount = playerAmount;	
	cout << "GameBoard object constructed\n";
 }

void GameBoard::setUpBoard(){			
	cout << "The Gameboard has " << _playerAmount << " players" << endl;		

	for (int i = 0; i < _playerAmount; ++i){\
		Player newPlayer = Player("Player #" + to_string(i), _dice, *this);
		_players.push_back( newPlayer );
	}

	for (Player p : _players){
		cout << "Player " << p.getPlayerName() << endl;		
	}

}

void GameBoard::playGame(){
	//while ( playerMovesRemaining()){
		for ( Player p : _players){
			p.startTurn();
		}
		
}

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