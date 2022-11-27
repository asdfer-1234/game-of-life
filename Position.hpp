#pragma once
#include "Configuration.hpp"

struct Position {
	static const Position zero;
	static const Position one;
	static const Position minus;
	static const Position right;
	static const Position left;
	static const Position down;
	static const Position up;
	static const Position rightdown;
	static const Position rightup;
	static const Position leftdown;
	static const Position leftup;
	static const Position directions[directionCount];
	static const Position spaces[directionCount + 1];
	int x;
	int y;
	Position();
	Position(int x);
	Position(int x, int y);
	int Size() const;
	Position Flip() const;
	bool Within(Position start, Position end);
	Position Clamped(Position range);
	Position Clamped(int range);
	Position Sloped(Position range);
	Position Sloped(int range);
	Position operator-() const;
	Position operator+(Position other) const;
	Position& operator+=(Position other);
	Position operator-(Position other) const;
	Position& operator-=(Position other);
	Position operator*(Position other) const;
	Position operator*(int other) const;
	Position& operator*=(Position other);
	Position& operator*=(int other);
	Position operator/(Position other) const;
	Position operator/(int other) const;
	Position& operator/=(Position other);
	Position& operator/=(int other);
	Position operator%(Position other) const;
	Position operator%(int other) const;
	Position& operator%=(Position other);
	Position& operator%=(int other);
	bool operator==(Position other) const;
	bool operator!=(Position other) const;
};
