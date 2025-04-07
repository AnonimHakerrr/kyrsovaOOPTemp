#pragma once
#include "Student.h"
#include "Iterator.h"
#include "File.h"
#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;
class Menu{
	vector<Student> stud;
public:
	void setStudent();
	void setStudentExam(int index);
	void deleteStudent(int index);
	void deleteStudentExam(int index);
	void showStud(vector<int> index);
	void showListStud();
	int sheachStudent();
	vector<int> sheachStudents();
	void seachExam();
	int showMiddelRating(int index);
	void showStudentListAverage();
	void showStudentRatingExam();
	void addratingExamStudent(int index);
	void setListStudents(vector<Student>& st );
	void writeFileStudens(File& f);
};

