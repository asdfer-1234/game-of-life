#include "Rule.hpp"

const Rule Rule::life = Rule(vector<Position>(begin(Position::directions), end(Position::directions)), vector<bool>({false, false, true, true, false, false, false, false, false}), vector<bool>{false, false, false, true, false, false, false, false, false});
const Rule Rule::highLife = Rule(vector<Position>(begin(Position::directions), end(Position::directions)), vector<bool>({false, false, true, true, false, false, false, false, false}), vector<bool>{false, false, false, true, false, false, false, false, false});
const Rule Rule::longLife = Rule(vector<Position>(begin(Position::directions), end(Position::directions)), vector<bool>({false, false, false, false, true, false, false, false, false}), vector<bool>{false, false, false, true, true, true, false, false, false});
const Rule Rule::maze = Rule(vector<Position>(begin(Position::directions), end(Position::directions)), vector<bool>({false, true, true, true, true, false, false, false, false}), vector<bool>{false, false, false, true, true, true, false, false, false});

Rule::Rule(const vector<Position>& direction, const vector<bool>& trueTo, const vector<bool>& falseTo): direction(direction), trueTo(trueTo), falseTo(falseTo) {}

bool Rule::IsToTrue(bool value, int adjacent) const {
	if(value) {
		if(trueTo.size() > adjacent) {
			return trueTo[adjacent];
		}
	} else {
		if(falseTo.size() > adjacent) {
			return falseTo[adjacent];
		}
	}
	return true;
}