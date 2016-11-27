#ifndef SCORETYPE_H
#define SCORETYPE_H

enum class ScoreType : unsigned int{
	// Upper Section
	AcesSum = 1,
	TwosSum,
	ThreesSum,
	FoursSum,
	FivesSum,
	SixesSum,
	// Lower Section
	ThreeOfAKind,
	FourOfAKind,
	FullHouse,
	SmallStraight,
	LargeStraight,
	Yahtzee,
	Chance
};

// TODO: figure out why exactly this needs to be inline
// is this a code smell?
inline std::ostream& operator<<(std::ostream& os, ScoreType s)
{
    std::cout << static_cast<int>(s);
    return os;
}

#endif