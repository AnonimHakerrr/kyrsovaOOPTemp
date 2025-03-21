#pragma once
#include "Student.h"
#include "Teacher.h"
#include <string>
#include <iostream>

 
using namespace std; 
class Exam :public Teacher, public Student
{
private:
	string name, dateStartExam;
	int hours, rating;
 

public :
	Exam(string name, string dateStartExam, int hours, int rating);
	Exam(const Student& s, const Teacher& t,string name, string dateStartExam, int hours, int rating);
	Exam(string nomerGrup,string position, string lastnameStud, string firstnameStud, string lastname,string firstname ,string name, string dateStartExam, int hours, int rating);
	Exam();
	~Exam();
	void SetExam(string name, string dateStartExam, int hours, int rating);
	string get(int x);
	void Show() override;
	//update

	

};
