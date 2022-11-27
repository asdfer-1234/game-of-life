#include "LifeNode.hpp"
#include "Game.hpp"
#include "Rule.hpp"
#include "Stem.hpp"
#include <exception>
using namespace std;

Position LifeNode::InnerPosition(Position position) {
	return (position + Position::one).Clamped(stemChildrenSize) - Position::one;
}

Position LifeNode::OuterPosition(Position position) {
	return (position + Position::one).Sloped(3);
}

bool LifeNode::PositionInStem(Position position) {
	return position.Within(Position::minus, Position::one);
}

LifeNode* LifeNode::ReturnSelf() const {
	return const_cast<LifeNode*>(this);
}

LifeNode::LifeNode(): LifeNode(nullptr) {}

LifeNode::~LifeNode() {}

LifeNode::LifeNode(Stem* parent): parent(parent) {}

Position LifeNode::GetPositionFromParent() const {
	for(Position i: Position::spaces) {
		if(parent->GetChildren(i) == this) {
			return i;
		}
	}
	throw exception("No parent child object");
}

LifeNode* LifeNode::FetchRelativeLifeNode(Position target, bool isChunk) {
	if(target == Position::zero) {
		return ReturnSelf();
	}
	if(parent == nullptr) {
		Game::Extend();
	}

	Position positionFromParent = GetPositionFromParent();
	Position centerRelative = target + positionFromParent;

	if(PositionInStem(centerRelative)) {
		return parent->FetchChildren(centerRelative, isChunk);
	} else {
		LifeNode* node = parent->FetchRelativeLifeNode(OuterPosition(centerRelative));
		return dynamic_cast<Stem*>(node)->FetchChildren(InnerPosition(centerRelative), isChunk);
	}
}

LifeNode* LifeNode::GetRelativeLifeNode(Position target) const {
	if(target == Position::zero) {
		return ReturnSelf();
	}
	if(parent == nullptr) {
		return nullptr;
	}

	Position positionFromParent = GetPositionFromParent();
	Position centerRelative = target + positionFromParent;

	if(PositionInStem(centerRelative)) {
		return parent->GetChildren(centerRelative);
	} else {
		LifeNode* node = parent->GetRelativeLifeNode(OuterPosition(centerRelative));
		if (node == nullptr) {
			return nullptr;
		}
		return dynamic_cast<Stem*>(node)->GetChildren(InnerPosition(centerRelative));
	}
}