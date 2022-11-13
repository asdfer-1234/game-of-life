#pragma once
struct Position
{
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
	Position Flip();
};

Position operator-(Position a);
Position operator+(Position a, Position b);
Position operator-(Position a, Position b);
Position operator*(Position a, Position b);
Position operator*(Position a, int b);
Position operator/(Position a, Position b);
Position operator/(Position a, int b);
Position operator%(Position a, Position b);
Position operator%(Position a, int b);
