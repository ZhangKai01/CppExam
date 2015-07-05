#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class  Course
{
public:
	Course(int courseId = 0, string courseName = "", string teacherName = "")
		:id(courseId), name(courseName), teacher(teacherName){}

	string toString(){
		char studentId[12];
		// ��id��intתΪchar���飬����string(char*)���캯�������ַ���
		_itoa_s(id, studentId, sizeof(studentId));
		return string(studentId) + " " + name + " " + teacher;
	}

	bool operator == (const Course& course){
		return this->id == course.id;
	}

private:
	int id;
	string name;
	string teacher;
};

#endif
