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
    return "\nПрізвище : " + lastname + "  Ім'я : " + firstname;
}

void Person::Show() {
    cout << "\nПрізвище: " << lastname << "Ім'я: " << firstname << endl;
}
bool Person::operator ==(const Person& other)
{
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