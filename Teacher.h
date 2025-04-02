#pragma once
#include "Person.h"
#include "TeacherPosition.h"
class Teacher :public Person
{
private:
	
	TeacherPosition position;
public:
	Teacher(TeacherPosition position, string lastname, string firstname);
	Teacher(const Teacher& other);
	Teacher(Teacher&& other);
	 Teacher();
	virtual ~Teacher();
	void setTeacher(TeacherPosition position, string lastname, string firstname);
	string getTeacher();
	void show() override;
	Teacher& operator=(const Teacher& other);
	Teacher& operator=(Teacher&& other);

	friend ostream& operator<<(ostream& os, const Teacher& Teacher);

	friend istream& operator>>(istream& is, Teacher& Teacher);







};

