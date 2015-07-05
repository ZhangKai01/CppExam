#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Student.h"
using namespace std;

// ÔÚmain.cppÖĞ
extern Course courses[];
extern const int COURSE_SIZE;
// --------------------------

class StudentSet {
public:
	vector<Student> students;

	friend ostream& operator <<(ostream& os, StudentSet& stuSet) {
		vector<Student>::iterator itr;
		for (itr = stuSet.students.begin(); itr != stuSet.students.end(); itr++) {
			os << (*itr);
		}
		return os;
	}

	StudentSet& operator +=(Student &stu) {
		students.push_back(stu);
		return (*this);
	}

	StudentSet& operator -=(Student &stu) {
		vector<Student>::iterator itr;
		for (itr = students.begin(); itr != students.end(); itr++) {
			if ((*itr) == stu) {
				students.erase(itr);
				break;
			}
		}
		return (*this);
	}

	Student& getById(int studentId) {
		vector<Student>::iterator itr;
		for (itr = students.begin(); itr != students.end(); itr++) {
			if ((*itr).ID == studentId) {
				return (*itr);
			}
		}
		return *itr;
	}

	void update(int studentId, string newName, string newDepartment) {
		Student &stu = getById(studentId);
		stu.name = newName;
		stu.department = newDepartment;
	}

	void displayByCourse() {
		for (int i = 0; i < COURSE_SIZE; i++) {
			cout << "CourseInfo:" << endl;
			string cour_s = courses[i].toString();
			cout << cour_s << endl;
			vector<Student>::iterator itrS;
			for (itrS = students.begin(); itrS != students.end(); itrS++) {
				vector<Course>::iterator itrC;
				for (itrC = (*itrS).courses.begin(); itrC != (*itrS).courses.end(); itrC++) {
					if ((*itrC) == courses[i]) {
						cout << (*itrS);
					}
				}
			}
		}
	}

};