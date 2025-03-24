#include "Person.h"
#include <iostream>


Person::Person(string lastname, string firstname):lastname(lastname),firstname(firstname) {}

Person::Person() {}
Person::~Person() {}
void Person::SetPerson(string lastname, string firstname)
{
    this->firstname = firstname;
    this->lastname = lastname;
}
string Person::GetPerson() {
    return "�������: " + lastname + ", ��'�: " + firstname;
}

void Person::Show() {
    cout << "�������: " << lastname << ", ��'�: " << firstname << endl;
}
bool Person::operator ==(const Person& other)
{
    return (lastname == other.lastname && firstname == other.firstname);

}
ostream& operator<<(ostream& os, const Person& person) {
    os << "�������: " << person.lastname << ", ��'�: " << person.firstname;
    return os;
}

istream& operator>>(istream& is, Person& person) {
    cout << "������ �������: ";
    is >> person.lastname;
    cout << "������ ��'�: ";
    is >> person.firstname;
    return is;
}