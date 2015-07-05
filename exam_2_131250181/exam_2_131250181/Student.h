#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Course.h"
using namespace std;

class Student {
public:
	int ID;
	string name;
	string department;
	vector<Course> courses;

	Student(int stuID = 0, string stuName = "", string stuDepartment = "") {
		ID = stuID;
		name = stuName;
		department = stuDepartment;
	}

	friend ostream& operator <<(ostream& os, Student& stu) {
		os << "StudentInfo:" << endl;
		os << stu.ID << " " << stu.name << " " << stu.department << endl;
		return os;
	}

	Student& operator +(Course &course) {
		courses.push_back(course);
		return (*this);
	}

	Student& operator -(Course &course) {
		vector<Course>::iterator itr;
		for (itr = courses.begin(); itr != courses.end(); itr++) {
			if (*itr == course) {
				courses.erase(itr);
				break;
			}
		}
		return (*this);
	}

	void showSchedule() {
		cout << (*this);
		vector<Course>::iterator itr;
		for (itr = courses.begin(); itr != courses.end(); itr++) {
			cout << "CourseInfo:" << endl;
			string cour_s = (*itr).toString();
			cout << cour_s << endl;
		}
	}

	bool operator == (const Student& stu){
		return this->ID == stu.ID;
	}
};