#ifndef DICE_H
#define DICE_H

class Dice{
	private:
		int _dice[6];
	public:
		void rollDice();
		int getOnesValue();
		Dice();
};

#endif