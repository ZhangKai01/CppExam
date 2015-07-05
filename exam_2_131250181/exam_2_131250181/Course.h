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
		// 将id由int转为char数组，再由string(char*)构造函数构造字符串
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
