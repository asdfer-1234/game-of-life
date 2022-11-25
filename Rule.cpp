#include "Rule.hpp"

bool Rule::IsToTrue(bool value, int adjacent) {
	return toTrue[value][adjacent];
}