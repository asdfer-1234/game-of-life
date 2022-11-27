#pragma once
#include "Position.hpp"
#include <vector>

using namespace std;

class Rule {
public:
	vector<Position> direction;
	vector<bool> trueTo;
	vector<bool> falseTo;
	static const Rule life;
	static const Rule highLife;
	static const Rule longLife;
	static const Rule maze;
	Rule(const vector<Position>& direction, const vector<bool>& trueToTrue, const vector<bool>& falsekTo);
	bool IsToTrue(bool state, int adjacent) const;
};