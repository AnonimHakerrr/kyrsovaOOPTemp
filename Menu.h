#pragma once
#include "Student.h"
#include "vector"
using namespace std;
class Menu
{
	vector<Student> stud;
public:
	void setStudent();
	void setStudentExam(int index);
	void ShowStud();
	void ShowListStud();
	int SheachStudent();
	void SeachExam();

};

