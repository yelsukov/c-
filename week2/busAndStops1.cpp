#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Map for collecting stops and relations with routes
 */
map<string, vector<string>> gStops;
/**
 * Map for collecting routes and relations with stops
 */
map<string, vector<string>> gRoutes;

/**
 * Structure for handling data from results of searching a stops
 */
struct fndStop {
	string stop;
	vector<string> buses;
};

/**
 * Creates route and stops for it
 *
 * @param string bus - name of bus
 * @param uint stopQty - how many stops to create for new route
 */
void newRoute(string bus, uint stopQty) {
	// Create route for new bus and link it with bus
	vector<string> stops(stopQty);
	for (string& s : stops) {
		cin >> s;
		gStops[s].push_back(bus);
	}
	gRoutes[bus] = stops;
}

/**
 * Searches for bus/route by stop in the routes
 *
 * @param string stop - Name of stop
 * @return vector<string>
 */
vector<string> findBuses(string stop) {
	vector<string> result;
	if (gStops.count(stop) == 1) {
		result = gStops[stop];
	}

	return result;
}

/**
 * Searches for stops by bus
 *
 * @param string bus - Name of bus/route
 * @return vector<fndStop>
 */
vector<fndStop> findStops(string bus) {
	vector<fndStop> result;

	// Check is route exists
	if (gRoutes.count(bus) == 0) {
		return result;
	}

	// Get stops for this route
	vector<string> stops = gRoutes[bus];
	for (auto stop : stops) {
		// Get buses for current stop and prepare it for results
		vector<string>buses = findBuses(stop);
		vector<string>::iterator pos = find(buses.begin(), buses.end(), bus);
		if (pos != buses.end()) {
			buses.erase(pos);
		}
		fndStop fnd = {stop, buses};
		result.push_back(fnd);
	}

	return result;
}

/**
 * Prints list of routes
 */
void printRoutes() {
	if (gRoutes.size() == 0) {
		cout << "No buses" << endl;
		return;
	}

	for (auto r : gRoutes) {
		 cout << "Bus " << r.first << ": ";
		 for(string s : r.second) {
			 cout << s << " ";
		 }
		 cout << endl;
	}
}

int main_bs_1() {
	uint qty;
	cin >> qty;

	while (qty != 0) {
		string cmd;
		cin >> cmd;
		if (cmd == "NEW_BUS") { // Create new route with stops
			string bus;
			uint stopQty;
			cin >> bus >> stopQty;
			newRoute(bus, stopQty);
		} else if (cmd == "BUSES_FOR_STOP") { // Find buses for stop
			string stop;
			cin >> stop;
			vector<string> result = findBuses(stop);
			if (!result.empty()) {
				for (string bus : result) {
					cout << bus << " ";
				}
				cout << endl;
			} else {
				cout << "No stop" << endl;
			}
		} else if (cmd == "STOPS_FOR_BUS") { // Find stops for bus
			string bus;
			cin >> bus;
			vector<fndStop> result = findStops(bus);
			if (!result.empty()) {
				for (auto fnd : result) {
					cout << "Stop " << fnd.stop << ": ";
					if (!fnd.buses.empty()) {
						for (string b : fnd.buses) {
							cout << b << " ";
						}
					} else {
						cout << "no interchange";
					}
					cout << endl;
				}
			} else {
				cout << "No bus" << endl;
			}
		} else if (cmd == "ALL_BUSES") {
			printRoutes();
		} else {
			cout << "Unrecognized command " << cmd << endl;
			continue;
		}
		qty--;
	}
	return 0;
}
