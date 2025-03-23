#pragma once
#include "Person.h"
#include "TeacherPosition.h"
class Teacher :public Person
{
private:
	//enume змінити 
	TeacherPosition position;
public:
	Teacher(TeacherPosition position, string lastname, string firstname);
	Teacher(const Teacher& other);
	Teacher(Teacher&& other);
	 Teacher();
	virtual ~Teacher();
	void SetTeacher(TeacherPosition position, string lastname, string firstname);
	string GetTeacher();
	void Show() override;
	Teacher& operator=(const Teacher& other);
	Teacher& operator=(Teacher&& other);

	friend ostream& operator<<(ostream& os, const Teacher& Teacher);

	friend istream& operator>>(istream& is, Teacher& Teacher);







};

