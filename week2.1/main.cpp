#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

map<string, QueryType> CmdNames = {
	{"NEW_BUS", QueryType::NewBus},
	{"BUSES_FOR_STOP", QueryType::BusesForStop},
	{"STOPS_FOR_BUS", QueryType::StopsForBus},
	{"ALL_BUSES", QueryType::AllBuses}
};

istream& operator >> (istream& is, Query& q) {
	string cmd;
	is >> cmd;
	if (CmdNames.count(cmd) == 0) {
		throw invalid_argument("Wrong command");
	}

	q.type = CmdNames[cmd];
	if (q.type == QueryType::NewBus || q.type == QueryType::StopsForBus) {
		is >> q.bus;
		if (q.type == QueryType::NewBus) {
			int stop_count;
			is >> stop_count;
			q.stops.resize(stop_count);
			for (string& stop : q.stops) {
				is >> stop;
			}
		}
	} else if (q.type == QueryType::BusesForStop) {
		is >> q.stop;
	}

	return is;
}

template<typename T>
ostream& operator <<(ostream& os, const vector<T> v) {
	bool isFirst = true;
	for (const auto& i : v) {
		if(!isFirst) {
			os << " ";
		}
		isFirst = false;
		os << i;
	}

	return os;
}

struct BusesForStopResponse {
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses.empty()) {
		os << "No stop";
	} else {
		os << r.buses;
	}

	return os;
}

struct StopsForBusResponse {
	vector<pair<string, vector<string>>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops.empty()) {
		os << "No bus";
		return os;
	}

	size_t sz = r.stops.size();
	for (const auto& stop : r.stops) {
		sz--;
		os << "Stop " << stop.first << ": ";
		if (stop.second.empty()) {
			os << "no interchange";
		} else {
			os << stop.second;
		}
		if (sz != 0) {
			 os << endl;
		}
	}

	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses.empty()) {
		os << "No buses";
	} else {
		size_t sz = r.buses.size();
		for (const auto& bus_item : r.buses) {
			sz--;
			os << "Bus " << bus_item.first << ": " << bus_item.second;
			if (sz != 0) {
				os << endl;
			}
		}
	}

	return os;
}


class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		this->buses_to_stops[bus] = stops;
		for (const string& s : stops) {
			this->stops_to_buses[s].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse r;
		if (this->stops_to_buses.count(stop) == 0) {
			return r;
		}
		r.buses = this->stops_to_buses.at(stop);

		return r;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse r;
		if (this->buses_to_stops.count(bus) == 0) {
			return r;
		}

		for (const string& s : this->buses_to_stops.at(bus)) {
			vector<string> buses = this->stops_to_buses.at(s);
			buses.erase(find(buses.begin(), buses.end(), bus));
			r.stops.push_back({s, buses});
		}

		return r;
	}

  AllBusesResponse GetAllBuses() const {
    return {this->buses_to_stops};
  }

protected:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
