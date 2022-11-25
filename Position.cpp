#include "Position.hpp"
#include "Configuration.hpp"

const Position Position::zero = Position(0);
const Position Position::one = Position(1);
const Position Position::minus = Position(-1);
const Position Position::right = Position(1, 0);
const Position Position::left = -right;
const Position Position::down = Position(0, 1);
const Position Position::up = -down;
const Position Position::rightdown = right + down;
const Position Position::rightup = right + up;
const Position Position::leftdown = left + down;
const Position Position::leftup = left + up;
const Position Position::directions[directionCount] = {right, left, down, up, rightdown, rightup, leftdown, leftup};
const Position Position::spaces[directionCount + 1] = {zero, right, left, down, up, rightdown, rightup, leftdown, leftup};

Position::Position(): Position(0) {}

Position::Position(int x): Position(x, x) {}

Position::Position(int x, int y): x(x), y(y) {}

bool Position::Within(Position start, Position end) {
	return start.x <= x && x <= end.x && start.y <= y && y <= end.y;
}

int Position::Size() const {
	return x * y;
}

Position Position::Flip() const {
	return Position(y, x);
}

Position Position::operator-() const {
	return Position(-x, -y);
}

Position Position::operator+(Position other) const {
	return Position(x + other.x, y + other.y);
}

Position& Position::operator+=(Position other) {
	return *this = *this + other;
}

Position Position::operator-(Position other) const {
	return *this + -other;
}

Position& Position::operator-=(Position other) {
	return *this = *this - other;
}

Position Position::operator*(Position other) const {
	return Position(x * other.x, y * other.y);
}

Position Position::operator*(int other) const {
	return *this * Position(other);
}

Position& Position::operator*=(Position other) {
	return *this = *this * other;
}

Position& Position::operator*=(int other) {
	return *this = *this - other;
}

Position Position::operator/(Position other) const {
	return Position(x / other.x, y / other.y);
}

Position Position::operator/(int b) const {
	return *this / Position(b);
}

Position& Position::operator/=(Position other) {
	return *this = *this / other;
}

Position& Position::operator/=(int other) {
	return *this = *this / other;
}

Position Position::operator%(Position other) const {
	return Position(x % other.x, y % other.y);
}

Position Position::operator%(int other) const {
	return *this % Position(other);
}

Position& Position::operator%=(Position other) {
	return *this = *this % other;
}

Position& Position::operator%=(int other) {
	return *this = *this % other;
}