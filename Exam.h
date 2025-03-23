#pragma once
 
#include "Teacher.h"
#include <string>
#include <iostream>

 
using namespace std; 
class Exam :public Teacher
{
private:
	string name, dateStartExam;
	int hours, rating;
 

public :
	Exam(string name, string dateStartExam, int hours, int rating);
	Exam(const Teacher& t,string name, string dateStartExam, int hours, int rating);
	Exam (string position, string lastname,string firstname ,string name, string dateStartExam, int hours, int rating);
	Exam();
	~Exam();
	void SetExam(string name, string dateStartExam, int hours, int rating);
	string get(int x);
	void Show() override;
	//update

	

};
