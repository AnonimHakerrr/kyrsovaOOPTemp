#include "Teacher.h"
#include <iostream>

Teacher::Teacher(TeacherPosition position, string lastname, string firstname) :Person(lastname, firstname) {
	this->position = position;
}

Teacher::Teacher(const Teacher& other) :Person(other), position(other.position) {
 }

Teacher::Teacher(Teacher&& other) :Person(move(other)), position(other.position) {
 }

Teacher::Teacher() :Person() {}

Teacher::~Teacher() {}

void Teacher::setTeacher(TeacherPosition position, string lastname, string firstname) {
	setPerson(lastname, firstname);
	this->position = position;
}

string Teacher::getTeacher() {
	return "\nПосада : " + positionToString(position) + getPerson();
}

void Teacher::show() {
	cout << getTeacher() << endl;
}

Teacher& Teacher::operator=(const Teacher& other) {
	if (this != &other) {
		Person::operator=(other);
		Teacher::position = other.position;
	}
	return *this;
}

Teacher& Teacher::operator=(Teacher&& other) {
	if (this != &other) {
		Person::operator=(move(other));
		Teacher::position = other.position;
	}
	return *this;
}

ostream& operator<<(ostream& os, Teacher& teach) {
	os << teach.getTeacher();
	return os;
}

istream& operator>>(istream& is, Teacher& teach) {
	is >> static_cast<Person&>(teach);
	cout << "Введіть Посаду: ";
	string str;
	is >> str;
	teach.position = positionToEnum(str);
	return is;
}