#pragma once
 
#include "Teacher.h"
 #include <iostream>
#include <sstream>
#include <string>
#include <limits>
 
using namespace std; 
class Exam :public Teacher
{
private:
	string name, dateStartExam;
	int hours=0, rating=0;
 
	
public :

	Exam(string name, string dateStartExam, int hours, int rating);
	Exam(const Teacher& t,string name, string dateStartExam, int hours, int rating);
	Exam (TeacherPosition position, string lastname,string firstname ,string name, string dateStartExam, int hours, int rating);
	Exam();
	~Exam();
	void SetExam(string name, string dateStartExam, int hours, int rating);
	static bool Evaluation(Exam& exam,int rating);
	int getRating();
	string getNameExam();
	void Show() override;
	static bool getValidNumber(istream& is, int& value);
	friend istream& operator>>(istream& is, Exam& ex);
};
