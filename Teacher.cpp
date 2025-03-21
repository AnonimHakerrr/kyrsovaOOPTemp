#include "Teacher.h"
#include <iostream>

Teacher::Teacher(string position, string lastname, string firstname) :Person(lastname, firstname)
{ this->position = position; }

Teacher::Teacher(const Teacher& other) :Person(other), position(other.position) {
    cout << "Викликано конструктор копіювання для Teacher" << endl;
}
Teacher::Teacher(Teacher&& other) :Person(move(other)), position(move(other.position)) {
    cout << "Викликано конструктор переміщення для Teacher" << endl;
}
Teacher::Teacher():Person() {}
Teacher::~Teacher() {}


void Teacher::SetTeacher(string position, string lastname, string firstname)
{
    SetPerson(lastname, firstname);
    this->position = position;

}
string Teacher::GetTeacher() {
    return "\nПосада " + position+ " \nВикладач :\n" +GetPerson();
}

void Teacher::Show() {
    cout << "Посада " << position << " \nВикладач :\n" << GetPerson() << endl;
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
        Teacher::position = move(other.position);
    }
    return *this;
}

ostream& operator<<(ostream& os, Teacher& stud) {
    os << stud.GetTeacher();
    return os;
}

istream& operator>>(istream& is, Teacher& stud) {
    cout << "Введіть Групу: ";
    is >> stud.position;
    return is;
}