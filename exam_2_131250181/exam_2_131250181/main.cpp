#pragma   warning(disable:4786)
#include <iostream>
#include <string>
#include <map>
#include "Student.h"
#include "Course.h"
#include "StudentSet.h"

const int COURSE_SIZE = 4;

enum Command {
	// student command
	ADD_STUDENT,
	DELETE_STUDENT,
	UPDATE_STUDENT,
	SHOW_STUDENT,
	SHOW_STUDENTS,
	// selection command
	ADD_COURSE,
	DELETE_COURSE,
	SHOW_SCHEDULE,
	SHOW_SELECTION,
	END
};

map<string, Command> commandMap;
void initMap() {
	commandMap["AddStudent"] = ADD_STUDENT;			//format:AddStudent studentId name department
	commandMap["DeleteStudent"] = DELETE_STUDENT;	//format:DeleteStudent studentId
	commandMap["UpdateStudent"] = UPDATE_STUDENT;	//format:UpdateStudent studentId newName newDepartment
	commandMap["ShowStudent"] = SHOW_STUDENT;		//format:ShowStudent studentId
	commandMap["ShowStudents"] = SHOW_STUDENTS;		//format:ShowStudents
	commandMap["AddCourse"] = ADD_COURSE;			//format:AddCourse studentId courseId 
	commandMap["DeleteCourse"] = DELETE_COURSE;		//format:DeleteCourse studentId courseId 	
	commandMap["ShowSelection"] = SHOW_SELECTION;	//format:ShowSelection
	commandMap["ShowSchedule"] = SHOW_SCHEDULE;		//format:ShowSchedule studentId
	commandMap["End"] = END;						//format:End
}
StudentSet students;
Course courses[COURSE_SIZE] = {
	Course(1, "algorithms", "teacherA"),
	Course(2, "C++ Programming", "teacherB"),
	Course(3, "Network", "teacherC"),
	Course(4, "Java Programming", "teacherD")
};
int courseCount = COURSE_SIZE;
Course getCourseById(int courseId);

int main(int argc, char* argv[]){
	initMap();
	Command command;
	string  commandStr;
	do{
		cin >> commandStr;
		command = commandMap[commandStr];
		switch (command) {
		case ADD_STUDENT:
			// ���һ��ѧ����¼
		{
			int studentId;
			string  name, department;
			cin >> studentId >> name >> department;
			students += Student(studentId, name, department);
			break;
		}
		case DELETE_STUDENT:
			//ɾ��һ��ѧ����¼
		{
			int studentId;
			cin >> studentId;
			students -= Student(studentId);
			break;
		}
		case UPDATE_STUDENT:
			//�޸�ѧ����Ϣ�е����ֺ�Ժϵ
		{
			int studentId;
			string newName, newDepartment;
			cin >> studentId >> newName >> newDepartment;
			students.update(studentId, newName, newDepartment);
			break;
		}
		case SHOW_STUDENT:
			// ���չ涨�ĸ�ʽ���ѧ����Ϣ
		{
			int studentId;
			cin >> studentId;
			cout << students.getById(studentId);
			break;
		}
		case SHOW_STUDENTS:
			// ����ѧ�����˳���������ѧ����Ϣ
		{
			cout << students;
			break;
		}
		case ADD_COURSE:
			//Ϊ������ѧ�����һ�ſγ�
		{
			int studentId, courseId;
			cin >> studentId >> courseId;
			Course course = getCourseById(courseId);
			students.getById(studentId) + course;
			break;
		}
		case DELETE_COURSE:
			//Ϊ������ѧ��ȥ��һ�ſγ�
		{
			int studentId, courseId;
			cin >> studentId >> courseId;
			Course course = getCourseById(courseId);
			students.getById(studentId) - course;
			break;
		}
		case SHOW_SCHEDULE:
			//���չ涨��ʽ���������ѧ����Ϣ�Լ�����ѧ��ѡ������пγ���Ϣ
		{
			int studentId;
			cin >> studentId;
			students.getById(studentId).showSchedule();
			break;
		}
		case SHOW_SELECTION:
			//����courses�����пγ̵�˳��������пγ̵���Ϣ��ѡ�����ſγ̵�����ѧ����Ϣ
		{
			students.displayByCourse();
			break;
		}

		case END:
			break;
		}

	} while (command != END);
	return 0;
}

Course getCourseById(int courseId){
	Course course;
	for (int i = 0; i < COURSE_SIZE; i++){
		if (courses[i] == Course(courseId)){
			course = courses[i];
		}
	}
	return course;
}
