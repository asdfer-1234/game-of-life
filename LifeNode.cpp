#include "LifeNode.hpp"
#include "Stem.hpp"
#include <exception>
using namespace std;

Position LifeNode::GetParentPosition() const {
	for(Position i: Position::spaces) {
		if(&parent.GetChildren(i) == this) {
			return i;
		}
	}
	throw exception("No parent child object");
}

LifeNode& LifeNode::GetRelativeLifeNode(Position position) const {
	Position parentPosition = GetParentPosition();
	Position centerRelative = position - parentPosition;
	if(centerRelative.Within(position.minus, position.one)) {
		return parent.GetChildren(centerRelative);
	} else {
		LifeNode& node = GetRelativeLifeNode((centerRelative + Position::one) / 3);
		return dynamic_cast<Stem&>(node).GetChildren(((position + Position::one) % 3 - Position::one));
	}
}

LifeNode& LifeNode::operator=(const LifeNode& other) {
	parent = other.parent;
	return *this;
}