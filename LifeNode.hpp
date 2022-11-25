#pragma once
#include "Position.hpp"
class Stem;

class LifeNode {
public:
	Stem& parent;
	Position GetParentPosition() const;
	virtual LifeNode& GetRelativeLifeNode(Position position) const;
	virtual ~LifeNode() = 0;
	virtual LifeNode& operator=(const LifeNode& other);
};
