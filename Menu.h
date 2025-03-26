#pragma once
#include "Student.h"
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
	void ShowStud(int index);
	void ShowListStud();
	int SheachStudent();
	void SeachExam();
	/*
	+ вивід середнього значення оцінки студента
	-- сортування по сердньому балі
	-- сортування струдентві по оцінці з екзамену
	-- додавання оцінки 
*/
	int showMiddelRating(int index);
	void showStudentListAverage();
	void showStudentRatingExam();
	void AddratingExamStudent(int index);

};

