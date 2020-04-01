#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

bool operator <(const Region& lhs, const Region& rhs)  {
	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
			tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	uint result = 0;
	map<Region, uint> repeets;
	for (const auto& r : regions) {
		result = max(result, ++repeets[r]);
	}
	return result;
}
