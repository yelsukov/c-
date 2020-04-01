#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
  void ChangeFirstName(uint year, const string& first_name) {
	  first_names[year] = first_name;
  }

  void ChangeLastName(uint year, const string& last_name) {
	  last_names[year] = last_name;
  }

  string GetFullName(uint year) {
	  return prepareFullName(findName(first_names, year, false), findName(last_names, year, false));
  }

  string GetFullNameWithHistory(uint year) {
	  return prepareFullName(findName(first_names, year, true), findName(last_names, year, true));
  }

private:
  map<uint, string> first_names;
  map<uint, string> last_names;

  string prepareFullName(const string& fname, const string& lname) {
	  if (fname == "" && lname == "") {
		  return "Incognito";
	  }

	  if (fname != "" && lname != "") {
		  return fname + " " + lname;
	  } else {
		  return (fname == "") ? lname + " with unknown first name" : fname + " with unknown last name";
	  }
  }

  string findName(const map<uint, string>& dict, uint year, bool withHistory = false) {
	  string result;
	  vector<string> prev_names;
	  for (const auto& item : dict) {
		  if(item.first <= year) {
			  result = item.second;
			  if (find(prev_names.begin(), prev_names.end(), item.second) == prev_names.end()) {
				  prev_names.push_back(item.second);
			  }
		  } else {
			  break;
		  }
	  }

	  if (prev_names.size() > 0 && prev_names.back() == result) {
		  prev_names.pop_back();
	  }

	  if (withHistory && prev_names.size() > 0) {
		  result += " (";

		  for(auto it = prev_names.rbegin(); it != prev_names.rend(); it++) {
			  result += *it;
			  if(next(it) != prev_names.rend())
				  result += ", ";
		  }
		  result += ")";
	  }
	  return result;
  }
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
