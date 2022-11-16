#include "Position.hpp"

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

Position::Position() : Position(0) {}

Position::Position(int x) : Position(x, x) {}

Position::Position(int x, int y) : x(x), y(y) {}

int Position::Size() { return x * y; }

Position Position::Flip() { return Position(y, x); }

Position Position::operator-() const { return Position(-x, -y); }

Position Position::operator+(Position other) const {
  return Position(x + other.x, y + other.y);
}

Position Position::operator-(Position other) const { return *this + -other; }

Position Position::operator*(Position other) const { return Position(x * other.x, y * other.y); }

Position Position::operator*(int other) const { return *this * Position(other); }

Position Position::operator/(Position other) const { return Position(x / other.x, y / other.y); }

Position Position::operator/(int b) const { return *this / Position(b); }

Position Position::operator%(Position other) const { return Position(x % other.x, y % other.y); }

Position Position::operator%(int other) const { return *this / Position(other); }