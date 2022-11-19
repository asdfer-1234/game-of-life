#pragma once

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
	int x;
	int y;
	Position();
	Position(int x);
	Position(int x, int y);
	int Size();
	Position Flip();
	Position operator-() const;
	Position operator+(Position other) const;
	Position operator-(Position other) const;
	Position operator*(Position other) const;
	Position operator*(int other) const;
	Position operator/(Position other) const;
	Position operator/(int other) const;
	Position operator%(Position other) const;
	Position operator%(int other) const;
};
