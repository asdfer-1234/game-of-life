#pragma once
#include "Position.hpp"
#include <vector>

using namespace std;

class Rule {
private:
	bool direction[directionCount];
	bool toTrue[2][directionCount];
public:
	static const Rule life;
	static const Rule highLife;
	static const Rule longLife;
	bool IsToTrue(bool state, int adjacent);
};