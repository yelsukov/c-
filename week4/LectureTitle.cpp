#include <iostream>

using namespace std;

struct Specialization {
	string value;
	explicit Specialization(const string& v) {
		this->value = v;
	}
};
struct Course {
	string value;
	explicit Course(const string& v) {
		this->value = v;
	}
};

struct Week {
	string value;
	explicit Week(const string& v) {
		this->value = v;
	}
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  explicit LectureTitle(const Specialization& s, const Course& c, const Week& w) {
	  this->specialization = s.value;
	  this->course = c.value;
	  this->week = w.value;
  }
};
