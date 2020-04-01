#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    return "";
}

class TimeServer {
public:
  string GetCurrentTime() {
	  try {
		  this->LastFetchedTime = AskTimeServer();
	  } catch (const system_error&) {
	  }

	  return this->LastFetchedTime;
  }
private:
  string LastFetchedTime = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
}
