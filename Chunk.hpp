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
	Chunk(Stem* parent);
	~Chunk();
	void SetParent(Stem* parent);

	Chunk* FetchRelativeLifeNode(Position position, bool isChunk = true);
	Chunk* GetRelativeLifeNode(Position position);
	bool FetchData(bool state, Position position);
	void SetData(bool state, Position position, bool value);
	bool GetData(bool state, Position position);
	void Step();
};