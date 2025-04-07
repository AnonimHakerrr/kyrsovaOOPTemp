#include "Student.h"
#include <iostream>
#include "Person.h"
#include "Iterator.h"

using namespace std;
Student::Student(string nomerGrup, string lastname, string firstname) :Person(lastname, firstname) {
	this->recordBook = new RecordBook(5);
	this->nomerGrup = nomerGrup;
}

Student::Student(const Student& other) :Person(other), nomerGrup(other.nomerGrup), recordBook(other.recordBook) {
 }
Student::Student(Student&& other) :Person(move(other)), nomerGrup(move(other.nomerGrup)), recordBook(other.recordBook) {
 }
Student::Student() :Person() {
	this->recordBook = new RecordBook(5);
};

Student::~Student() {}

void Student::setStudent(string nomerGrup, string lastname, string firstname) {
	setPerson(lastname, firstname);
	this->nomerGrup = nomerGrup;
}

string Student::getStudent() {
	return "\nCтудент √рупи : " + nomerGrup + getPerson() + "\n";
}

void Student::setRecordBookStudent(Exam exam) {
	recordBook->add(exam);
}

RecordBook Student::getRecordBookStudent() {
	return *recordBook;
}

void Student::show() {
	cout << "\nCтудент √рупи :" + nomerGrup + getPerson() << endl;
	if (recordBook->getSize() != 0) {
		Iterator begin(recordBook->begin(), recordBook->end());
		Iterator end(recordBook->end(), recordBook->end());
		for (Iterator it = begin; it != end; ++it) {
			(*it).show();
		}
	}
	else {
		cout << "\n≈кзамен≥в не знайдено!" << endl;
	}
}

void Student::deleteExam(int index) {
	recordBook->deleteExam(index);
}

Student& Student::operator=(const Student& other) {
	if (this != &other) {
		Person::operator=(other);
		Student::nomerGrup = other.nomerGrup;
	}
	return *this;
}

Student& Student::operator=(Student&& other) {
	if (this != &other) {
		Person::operator=(move(other));
		Student::nomerGrup = move(other.nomerGrup);
	}
	return *this;
}

bool Student::operator==(const Student& st) {
	return Person::operator==(st) && (nomerGrup == st.nomerGrup);
}

ostream& operator<<(ostream& os, Student& stud) {
	os << stud.getStudent();
	return os;
}

istream& operator>>(istream& is, Student& stud) {
	is >> static_cast<Person&>(stud);
	cout << "¬вед≥ть √рупу: ";
	is >> stud.nomerGrup;
	return is;
}