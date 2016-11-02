/* Main File */
#include <iostream>
#include "GameBoard.hpp"

using namespace std;

// Create board and other relevant entities to play the game.
// Introduce user to game.
void initializeGame(){
	int playerAmount;

	cout << "Welcome to Yahtzee!\n";
	cout << "Enter the amount of players: ";
	cin >> playerAmount;

	GameBoard gameBoard(playerAmount);	
	//Construct players -- Players will construct their own score cards
	gameBoard.setUpBoard(); //main game loop
}

// Main game loop
void playGame(){
	cout << "Playing Game\n";
}

int main(){	
	initializeGame();
	playGame();
	
	cout << "Thanks for playing";
	return 0;
}