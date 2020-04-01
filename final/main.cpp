#include <iostream>
#include <set>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;

/**
 * Class for interaction with date
 */
class Date {
public:
  int GetYear() const {
	  return this->year;
  };

  int GetMonth() const {
	  return this->month;
  };

  int GetDay() const {
	  return this->day;
  };

  int GetTimestamp() const {
	  return this->timestamp;
  }

  Date(){};

  Date(int year, int month, int day) {
	  if (month <= 0 || month > 12) {
		  throw invalid_argument("Month value is invalid: " + to_string(month));
	  }
	  if (day <= 0 || day > 31) {
		  throw invalid_argument("Day value is invalid: " + to_string(day));
	  }

	  this->year = year;
	  this->month = month;
	  this->day = day;

	  int dt = 24 * 3600, mt = dt * 31, yt = 12 * mt;
	  this->timestamp = (this->year * yt) + (this->month * mt) + (this->day * dt);
  }

protected:
  int year = 0;
  int month = 0;
  int day = 0;
  int timestamp = 0;
};

ostream& operator <<(ostream& stream, const Date& dt) {
	stream << setfill('0')
		   << setw(4) << dt.GetYear() << '-'
		   << setw(2) << dt.GetMonth() << '-'
		   << setw(2) << dt.GetDay();

	return stream;
}

istream& operator >>(istream& stream, Date& dt) {
	string date;
	stream >> date;

	stringstream inner(date);

	int year = 0, month = 0, day = 0;
	inner >> year;
	inner.ignore(1);
	inner >> month;
	inner.ignore(1);
	inner >> day;
	if (!inner || !inner.eof()) {
		throw invalid_argument("Wrong date format: " + date);
	}

	dt = Date(year, month, day);

	return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
	return lhs.GetTimestamp() < rhs.GetTimestamp();
};


/**
 * Database with dates and events
 */
class Database {
public:
	/**
	 * Ad new event
	 */
	void AddEvent(const Date& date, const string& event) {
		this->data[date].insert(event);
	};

	/**
	* Delete event in date
	*/
	bool DeleteEvent(const Date& date, const string& event) {
		if (this->data.count(date) == 0 || this->data[date].count(event) == 0) {
		    return false;
		}

		this->data[date].erase(event);

		return true;
	};

	/**
	* Delete data and all its events
	*/
	int DeleteDate(const Date& date) {
		int deleted = 0;
		if(this->data.count(date) != 0) {
			deleted = this->data[date].size();
			this->data.erase(date);
		}

		return deleted;
	};

	/**
	* Search for date in database
	*/
	set<string> Find(const Date& date) const {
		set<string> result;
		if (this->data.count(date)) {
			result = this->data.at(date);
		}

		return result;
	};

	/**
	* Print database
	*/
	void Print(ostream& out) const {
		for (auto& item : this->data) {
			for (string event : item.second) {
				out << item.first << " " << event << endl;
			}
		}
	};

protected:
	map<Date,set<string>> data;
};


void process(istream& in, ostream& out) {
	Database db;

	try {
		string line;
		while (getline(in, line)) {
			stringstream stream(line);

			string command;
			stream >> command;
			if (command.length() == 0) {
				continue;
			}

			if (command == "Add") {
				Date dt; string event;
				stream >> dt >> event;
				db.AddEvent(dt, event);

			} else if (command == "Del") {
				Date dt;
				stream >> dt;
				if (stream.eof()) {
					out << "Deleted " << db.DeleteDate(dt) << " events" << endl;
				} else {
					string event;
					stream >> event;
					out << (db.DeleteEvent(dt, event) ? "Deleted successfully" : "Event not found") << endl;
				}

			} else if (command == "Find") {
				Date dt;
				stream >> dt;
				for(const string& e : db.Find(dt)) {
					out << e << endl;
				}

			} else if (command == "Print") {
				db.Print(out);

			} else {
				throw invalid_argument("Unknown command: " + command);
			}
		}
	} catch(invalid_argument& e) {
		out << e.what() << endl;
	} catch (exception& e) {
		out << "Unknown exception: " << e.what() << endl;
	}
}

/**
 * ============ Tests ===============
 */

void checkCases(const string testName, const vector<string>& cases, stringstream& stream) {
	string line, error;
	uint n = 0;
	bool isSuccess = true;
	cout << "Testing " << testName << " - ";
	while (getline(stream, line)) {
		if (cases.size() < (n + 1)) {
			isSuccess = false;
			error = "Unregistered line #" + to_string(n) + " in output: " + line + "";
			break;
		}

		if (cases[n] != line) {
			isSuccess = false;
			error = "at line " + to_string(n) + ": '" + cases[n] + "' != '" + line + "'";
			break;
		}
		n++;
	}
	if (n == 0 && line == "" && cases.size() > 0) {
		isSuccess = false;
		error = "Empty output";
	}
	cout << (isSuccess ? "OK" : ("FAIL - " + error)) << endl;
}

void testInput() {
	// One event, one date in different formats
	{
		stringstream in, out;
		vector<string> commands = {
			"Add 2019-5-9 celebration",
			"Add 2019-05-09 celebration",
			"",
			"Add 2019-5-09 celebration",
			"Add 2019-05-9 celebration",
			"Print",
		};
		for (string cmd : commands) {
			in <<  cmd << endl;
		}
		process(in, out);

		checkCases("Test Input #1", {"2019-05-09 celebration"}, out);
	}

	// Invalid date after correct
	{
		stringstream in, out;
		vector<string> commands = {
				"Add a-15-40 e",
				"Add 2019-a-40 e",
				"Add 2019-15-9 e",
				"Add 2019-11-40 e",
				"Add 2019--11-40 e",
				"Add 2019-11--14 e",
				"Add -2-14-11 e",
				"Add -0001-11-214 e",
				"Add 2019-11-1d",
				"Add 201d-11-02",
				"Add 21-11-02",
				"Add 2019--1",
				"Add 2019-1d-1",
		};
		for (string cmd : commands) {
			in << cmd;
			process(in, out);
		}
		checkCases("Test Input #2", {
			"Wrong date format: a-15-40",
			"Wrong date format: 2019-a-40",
			"Month value is invalid: 15",
			"Day value is invalid: 40",
			"Wrong date format: 2019--11-40",
			"Wrong date format: 2019-11--14",
			"Month value is invalid: 14",
			"Day value is invalid: 214",
			"Wrong date format: 2019-11-1d",
			"Wrong date format: Add 201d-11-02",
			"Wrong date format: Add 21-11-02",
			"Wrong date format: Add 2019--1",
			"Wrong date format: Add 2019-1d-1",
		}, out);
	}

	// Test correct dates and output order
	{
		stringstream in, out;
		vector<string> commands = {
				"Add 0-12-1 e",
				"Add 0000-01-02 e",
				"Add 0000-01-01 e",
				"Add 0-1-1 e5",
				"Add 0-1-1 e2",
				"Add 1-12-01 e",
				"Print"
		};
		for (string cmd : commands) {
			in << cmd << endl;
		}
		process(in, out);
		checkCases("Input Test #3", {
			"0000-01-01 e",
			"0000-01-01 e2",
			"0000-01-01 e5",
			"0000-01-02 e",
			"0000-12-01 e",
			"0001-12-01 e",
		}, out);
	}
}

void testFind() {
	// Find events
	{
		stringstream in, out;
		vector<string> commands = {
			"Add 2019-05-9 a",
			"Add 2019-5-09 b",
			"Add 2019-5-04 c",
			"Find 2019-05-09",
			"Find 2018-01-09",
			"Find 2019-5-4"
		};
		for (string cmd : commands) {
			in <<  cmd << endl;
		}
		process(in, out);

		checkCases("Test Find #1", {"a", "b", "c"}, out);
	}
}

void testDelete() {
	// Find events
	{
		stringstream in, out;
		vector<string> commands = {
			"Add 2019-05-9 a",
			"Add 2019-5-09 b",
			"Add 2019-5-04 c",
			"Add 2019-5-04 d",
			"Del 2019-05-09 d",
			"Del 2019-05-01",
			"Del 2019-05-09 b",
			"Del 2019-05-04",
			"Print",
		};
		for (string cmd : commands) {
			in <<  cmd << endl;
		}
		process(in, out);

		checkCases("Test Delete #1", {
				"Event not found",
				"Deleted 0 events",
				"Deleted successfully",
				"Deleted 2 events",
				"2019-05-09 a",
		}, out);
	}
}

/**
 * ============ End Tests ===============
 */

int main() {
	process(cin, cout);

//	testInput();
//	testFind();
//	testDelete();

	return 0;
}
