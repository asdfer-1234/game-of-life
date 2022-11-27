#pragma once
#include "Position.hpp"
#include "Rule.hpp"
class Stem;

class LifeNode {
protected:
	static Position InnerPosition(Position position);
	static Position OuterPosition(Position position);
	static bool PositionInStem(Position position);
	LifeNode* ReturnSelf() const;
public:
	Stem* parent;
	LifeNode();
	LifeNode(Stem* parent);
	/**
	 * @brief Get the position of this on the parent stem object
	 * 
	 * @return Position of this in the parent stem object
	 */
	Position GetPositionFromParent() const;
	virtual LifeNode* FetchRelativeLifeNode(Position position, bool isChunk = false);
	virtual LifeNode* GetRelativeLifeNode(Position position) const;
	virtual ~LifeNode() = 0;
	virtual void Step() = 0;
};
