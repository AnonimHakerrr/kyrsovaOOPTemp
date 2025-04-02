#pragma once
#include "Person.h"
#include <string>
#include "RecordBook.h"
using namespace std;
class Student :public Person
{
private :
	string nomerGrup;
	RecordBook* recordBook  ;
public: 
	Student(string nomerGrup, string lastname, string firstname);
	Student(const Student& other);
	Student(Student&& other);
	Student();
	virtual ~Student();
	void setStudent(string nomerGrup, string lastname, string firstname);
	string getStudent();
 	void setRecordBookStudent(Exam exam);
	RecordBook getRecordBookStudent();
	void show() override;
	void deleteExam(int index);
	Student& operator=(const Student& other);
	Student& operator=(Student&& other);
    bool operator==(const Student& st) ;
	friend ostream& operator<<(ostream& os, const Student& Student);
	friend istream& operator>>(istream& is, Student& Student);



};

