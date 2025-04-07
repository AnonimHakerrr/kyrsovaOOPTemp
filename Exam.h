#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include "Teacher.h"
#include "TeacherPosition.h"
 
using namespace std; 
class Exam {
private:
	Teacher tech;
	string name, dateStartExam;
	int hours=0, rating=0;
public :
	Exam(string name, string dateStartExam, int hours, int rating);
	Exam(const Teacher& t,string name, string dateStartExam, int hours, int rating);
	Exam (TeacherPosition position, string lastname,string firstname ,string name, string dateStartExam, int hours, int rating);
	Exam();
	~Exam();
	void setExam(string name, string dateStartExam, int hours, int rating);
	static void evaluation(Exam& exam,int rating);
	int getRating();
	string getNameExam();
	void show();
	static bool getValidNumber(istream& is, int& value);
	string getInfoExam();
	friend istream& operator>>(istream& is, Exam& ex);
};
