#pragma once
#include "Configuration.hpp"
#include "LifeNode.hpp"
#include "Position.hpp"
#include "Rule.hpp"

class Chunk: public LifeNode {
private:
	int data;
	int GetIndex(bool state, Position position);
	bool GetLocalData(bool state, Position position);
	void SetLocalData(bool state, Position position, bool value);
public:
	Chunk();
	Chunk& GetRelativeLifeNode(Position position) const;
	bool GetData(bool state, Position position);
	void SetData(bool state, Position position, bool value);
	void Step(bool state, Rule rule);
	Chunk& operator=(const Chunk& other);
};
