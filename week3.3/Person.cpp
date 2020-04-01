#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
	Person(const string& first_name, const string&last_name, const uint& year) {
		birth_year = year;
		first_names[year] = first_name;
		last_names[year] = last_name;
	}

	void ChangeFirstName(uint year, const string& first_name) {
		if (year >= birth_year) {
			first_names[year] = first_name;
		}
	}

	void ChangeLastName(uint year, const string& last_name) {
		if (year >= birth_year) {
			last_names[year] = last_name;
		}
	}

	string GetFullName(uint year) const {
		if (year < birth_year) {
			return "No person";
		}
		return prepareFullName(findName(first_names, year, false), findName(last_names, year, false));
	}

	string GetFullNameWithHistory(uint year) const {
		if (year < birth_year) {
			return "No person";
		}
		return prepareFullName(findName(first_names, year, true), findName(last_names, year, true));
	}

private:
	map<uint, string> first_names;
	map<uint, string> last_names;
	uint birth_year;

	string prepareFullName(const string& fname, const string& lname) const {
		if (fname == "" && lname == "") {
			return "Incognito";
		}

		if (fname != "" && lname != "") {
			return fname + " " + lname;
		} else {
			return (fname == "") ? lname + " with unknown first name" : fname + " with unknown last name";
		}
  }

  string findName(const map<uint, string>& dict, uint year, bool withHistory = false) const {
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


