#pragma once
#include "Person.h"
#include <string>
#include "RecordBook.h"
using namespace std;
class Student :public Person
{
private :
	string nomerGrup;
	RecordBook* recordBook;
public: 
	Student(string nomerGrup, string lastname, string firstname,int maxsize);
	Student(const Student& other);
	Student(Student&& other);
	Student();
	virtual ~Student();
	void SetStudent(string nomerGrup, string lastname, string firstname);
	string GetStudent();
	void ShowRecordBookStudent();
	void SetRecordBookStudent(Exam exam);
	void Show() override;
	Student& operator=(const Student& other);
	Student& operator=(Student&& other);

	friend ostream& operator<<(ostream& os, const Student& Student);

	friend istream& operator>>(istream& is, Student& Student);



};

