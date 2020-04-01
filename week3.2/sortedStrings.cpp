#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    sorted.push_back(s);
    sort(sorted.begin(), sorted.end());
  }
  vector<string> GetSortedStrings() {
    return sorted;
  }
private:
  vector<string> sorted;
};

