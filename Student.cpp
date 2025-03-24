#include "Student.h"
#include <iostream>
#include "Person.h"
#include "Iterator.h"

using namespace std;
Student::Student(string nomerGrup, string lastname, string firstname, int maxsize):Person(lastname, firstname) 
{ 
this->recordBook = new RecordBook(5); 
this->nomerGrup = nomerGrup; 
}

Student::Student(const Student& other):Person(other), nomerGrup(other.nomerGrup),recordBook(other.recordBook) {
    cout << "��������� ����������� ��������� ��� Student" << endl;
}
Student::Student(Student&& other):Person(move(other)), nomerGrup(move(other.nomerGrup)), recordBook(other.recordBook) {
    cout << "��������� ����������� ���������� ��� Student" << endl;
}
Student::Student():Person() {
    this->recordBook = new RecordBook(5);
};
Student::~Student() {}
void Student::SetStudent(string nomerGrup, string lastname, string firstname)
{
    SetPerson(lastname, firstname);
    this->nomerGrup = nomerGrup;
      
     
}
string Student::GetStudent() {
    
    return "\n����� " + nomerGrup + " \n������� :\n"+GetPerson();
}
void Student::SetRecordBookStudent(Exam exam ) {
    recordBook->Add(exam);
}
RecordBook Student::getRecordBookStudent()
{
    return *recordBook;
}
void Student::Show() {
    
    cout << "����� ����� "<<nomerGrup <<" \n������� :\n"<< GetPerson() << endl;
    Iterator begin(recordBook->begin(), recordBook->end());
    Iterator end(recordBook->end(), recordBook->end());
    for (Iterator it = begin; it != end; ++it) {
        (*it).Show();
    }

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
bool Student::operator==(const Student& st) 
{
 
    return Person::operator==(st) && (nomerGrup == st.nomerGrup);
}
ostream& operator<<(ostream& os,Student& stud) {
    os << stud.GetStudent();
    return os;
}

istream& operator>>(istream& is, Student& stud) {
    is >> static_cast<Person&>(stud);
    cout << "������ �����: ";
    is >> stud.nomerGrup;
    return is;
}