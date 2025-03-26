#pragma once
#include "Student.h"
#include "Iterator.h"
#include "File.h"
#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;
class Menu
{
	vector<Student> stud;
public:
	void setStudent();
	void setStudentExam(int index);
	void deleteStudent(int index);
	void deleteStudentExam(int index);
	void ShowStud(int index);
	void ShowListStud();
	int SheachStudent();
	void SeachExam();
	int showMiddelRating(int index);
	void showStudentListAverage();
	void showStudentRatingExam();
	void AddratingExamStudent(int index);
	void setListStudents(vector<Student>& st );
	void WriteFileStudens(File& f);
};

