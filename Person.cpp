#include "Person.h"
#include <iostream>


Person::Person(string lastname, string firstname) :lastname(lastname), firstname(firstname) {}

Person::Person() {}

Person::~Person() {}

void Person::setPerson(string lastname, string firstname) {
	this->firstname = firstname;
	this->lastname = lastname;
}
string Person::getPerson() {
	return "\nПрізвище : " + lastname + "  Ім'я : " + firstname+"\n";
}

void Person::show() {
	cout << "\nПрізвище: " << lastname << "Ім'я: " << firstname << endl;
}

bool Person::operator ==(const Person& other) {
	return (lastname == other.lastname && firstname == other.firstname);
}
ostream& operator<<(ostream& os, const Person& person) {
	os << "\nПрізвище: " << person.lastname << "Ім'я: " << person.firstname;
	return os;
}

istream& operator>>(istream& is, Person& person) {
	cout << "Введіть прізвище: ";
	is >> person.lastname;
	cout << "Введіть ім'я: ";
	is >> person.firstname;
	return is;
}