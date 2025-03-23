#include "Teacher.h"
#include <iostream>

Teacher::Teacher(TeacherPosition position, string lastname, string firstname) :Person(lastname, firstname)
{ this->position = position; }

Teacher::Teacher(const Teacher& other) :Person(other), position(other.position) {
    cout << "Викликано конструктор копіювання для Teacher" << endl;
}
Teacher::Teacher(Teacher&& other):Person(move(other)), position(other.position) {
    cout << "Викликано конструктор переміщення для Teacher" << endl;
}
Teacher::Teacher() :Person()  {  }
Teacher::~Teacher() {}


void Teacher::SetTeacher(TeacherPosition position, string lastname, string firstname)
{
    SetPerson(lastname, firstname);
    this->position = position;

}
string Teacher::GetTeacher() {
    return "\nПосада " +  positionToString(position) + " \nВикладач :\n" + GetPerson();
}

void Teacher::Show() {
    cout << GetTeacher() << endl;
}

Teacher& Teacher::operator=(const Teacher& other) {
    if (this != &other) {
        Person::operator=(other);
        Teacher::position = other.position;
    }
    return *this;
}
Teacher& Teacher::operator=(Teacher&& other)  {
    if (this != &other) {
        Person::operator=(move(other));
        Teacher::position = other.position;
    }
    return *this;
}

ostream& operator<<(ostream& os, Teacher& teach) {
    os << teach.GetTeacher();
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