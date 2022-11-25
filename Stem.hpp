#pragma once
#include "Configuration.hpp"
#include "LifeNode.hpp"
#include "Position.hpp"

class Stem: public LifeNode {
private:
	LifeNode* children[stemChildrenSize][stemChildrenSize];
public:
	Stem();
	virtual ~Stem();
	LifeNode& GetChildren(Position position) const;
	LifeNode& SetChildren(Position position, LifeNode& children);
	Stem& operator=(const Stem& other);
};
