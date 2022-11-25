#include "Stem.hpp"

LifeNode& Stem::GetChildren(Position position) const {
	return *children[position.x + stemCenter][position.y + stemCenter];
}

LifeNode& Stem::SetChildren(Position position, LifeNode& lifeNode) {
	return GetChildren(position) = lifeNode;
}

Stem& Stem::operator=(const Stem& other) {
	LifeNode::operator=(other);
	for(int x = -1; x <= 1; x++) {
		for(int y = -1; y <= 1; y++) {
			SetChildren(Position(x, y), other.GetChildren(Position(x, y)));
		}
	}
	return *this;
}