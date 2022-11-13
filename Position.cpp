#include "Position.hpp"

const Position Position::zero = Position(0);
const Position one = Position(1);
const Position minus = Position(-1);
const Position right = Position(1, 0);
const Position left = -right;
const Position down = Position(0, 1);
const Position up = -down;
const Position rightdown = right + down;
const Position rightup = right + up;
const Position leftdown = left + down;
const Position leftup = left + up;

Position::Position() : Position(0) {}

Position::Position(int x) : Position(x, x) {}

Position::Position(int x, int y) : x(x), y(y) {}

int Position::Size(){
	return x * y;
}

Position Position::Flip(){
	return Position(y, x);
}

Position operator-(Position a){
	return Position(-a.x, -a.y);
}

Position operator+(Position a, Position b){
	return Position(a.x + b.x, a.y + b.y);
}

Position operator-(Position a, Position b){
	return a + -b;
}

Position operator*(Position a, Position b){
	return Position(a.x * b.x, a.y * b.y);
}

Position operator*(Position a, int b){
	return a * Position(b);
}

Position operator/(Position a, Position b){
	return Position(a.x / b.x, a.y / b.y);
}

Position operator/(Position a, int b){
	return a / Position(b);
}

Position operator%(Position a, Position b){
	return Position(a.x % b.x, a.y % b.y);
}

Position operator%(Position a, int b){
	return Position(a.x % b, a.y % b);
}