#include "Student.h"
#include <iostream>
#include "Person.h"
using namespace std;
Student::Student(string nomerGrup, string lastname, string firstname) :Person(lastname, firstname) { this->nomerGrup = nomerGrup; }

Student::Student(const Student& other):Person(other), nomerGrup(other.nomerGrup) {
    cout << "Викликано конструктор копіювання для Student" << endl;
}
Student::Student(Student&& other):Person(move(other)), nomerGrup(move(other.nomerGrup)) {
    cout << "Викликано конструктор переміщення для Student" << endl;
}
Student::Student():Person() {};
Student::~Student() {}
void Student::SetStudent(string nomerGrup, string lastname, string firstname)
{
    SetPerson(lastname, firstname);
    this->nomerGrup = nomerGrup;
     
}
string Student::GetStudent() {
    
    return "\nГрупа " + nomerGrup + " \nСтудент :\n"+GetPerson();
}

void Student::Show() {
    
    cout << "Номер групи "<<nomerGrup <<" \nСтудент :\n"<< GetPerson() << endl;
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

ostream& operator<<(ostream& os,Student& stud) {
    os << stud.GetStudent();
    return os;
}

istream& operator>>(istream& is, Student& stud) {
    cout << "Введіть Групу: ";
    is >> stud.nomerGrup;
    return is;
}