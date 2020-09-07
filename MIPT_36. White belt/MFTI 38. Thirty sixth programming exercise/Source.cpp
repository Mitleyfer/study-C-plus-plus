#include <iostream>
#include <string>

using namespace std;

struct Specialization {
	string specialization;
	explicit Specialization(string new_specialization) {
		specialization = new_specialization;
	}
};
struct Course {
	string course;
	explicit Course(string new_course) {
		course = new_course;
	}
};
struct Week {
	string week;
	explicit Week(string new_week) {
		week = new_week;
	}
};
struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization new_specialization, Course new_course, Week new_week) {
		specialization = new_specialization.specialization;
		course = new_course.course;
		week = new_week.week;
	}
};

int main() {
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	//cout << title.specialization << " " << flush;
	//cout << title.course << " " << flush;
	//cout << title.week << endl;

	return 0;
}