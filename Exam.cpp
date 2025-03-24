
#include "Exam.h"



Exam::Exam(string name, string dateStartExam, int hours, int rating=0):
Teacher::Teacher(),
 
name(name),
dateStartExam(dateStartExam),
hours(hours),
rating(rating)
{}
Exam::Exam(TeacherPosition position, 
	string lastname, string firstname,
	string name, string dateStartExam, int hours, int rating=0):Teacher::Teacher(position,lastname,firstname),
	name(name),
	dateStartExam(dateStartExam),
	hours(hours),
	rating(rating)
{}
Exam::Exam( const Teacher& t, string name, string dateStartExam, int hours, int rating=0)
:Teacher(t),
 	name(name),
	dateStartExam(dateStartExam),
	hours(hours),
	rating(rating){}


Exam::Exam() {}
Exam::~Exam() {}

void Exam::Evaluation(int rating){
	if (rating >= 0 && rating <= 100)
		this->rating = rating;
	else
		throw invalid_argument("�������: ������ ������� ���� � ����� 0-100!");

}
void Exam::SetExam(string name, string dateStartExam, int hours, int rating=0)
{
	this->name = name;
	this->dateStartExam = dateStartExam;
	this->hours = hours;
	this->rating = rating;

}
//string Exam::get(int x)
//{	
//		switch (x)
//		{
//		case 1:
//			return name;
//		case 2:
//			return dateStartExam;
//		case 3:
//			return to_string(hours);
//		case 4:
//			return to_string(rating);
//
//		default:
//			return "\n����� �������� " + name + "\n���� ���������� " + dateStartExam+"\nʳ������ ����� �� ������� " + to_string(hours)+"\n������ "+ to_string(rating);
//			break;
//		}
//}
void Exam::Show()
{
	cout << "\n����� �������� " + name + "\n���� ���������� " + dateStartExam + "\nʳ������ ����� �� ������� " + to_string(hours) + "\n������ " + to_string(rating) << "\n"   << GetTeacher() << endl;
}