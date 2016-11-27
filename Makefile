yahtzee: GameBoard.o ScoreCard.o Player.o Dice.o 
	g++ -std=c++1y GameBoard.o ScoreCard.o Player.o Dice.o -o yahtzee.out
GameBoard.o: GameBoard.cpp GameBoard.hpp Dice.hpp Player.hpp 
	g++ -c -std=c++1y GameBoard.cpp
Dice.o: Dice.cpp Dice.hpp
	g++ -c -std=c++1y Dice.cpp
Player.o: Player.cpp Player.hpp ScoreCard.hpp Dice.hpp
	g++ -c -std=c++1y Player.cpp 
ScoreCard.o: ScoreCard.cpp ScoreCard.hpp Dice.hpp ScoreType.hpp
	g++ -c -std=c++1y ScoreCard.cpp