#pragma once
#include "Configuration.hpp"
#include "LifeNode.hpp"
#include "Position.hpp"
#include "Rule.hpp"

class Stem: public LifeNode {
private:
	LifeNode* children[stemChildrenSize][stemChildrenSize];
	LifeNode*& GetChildrenReference(Position position);
public:
	Stem();
	virtual ~Stem();
	LifeNode* AddChildren(Position position, LifeNode* node);
	LifeNode* FetchChildren(Position position, bool isChunk = false);
	LifeNode* GetChildren(Position position) const;
	LifeNode* ConnectChildren(Position position, LifeNode* children);
	void Step();
};
