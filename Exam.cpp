
#include "Exam.h"



Exam::Exam(string name, string dateStartExam, int hours, int rating):
Teacher::Teacher(),
 
name(name),
dateStartExam(dateStartExam),
hours(hours),
rating(rating)
{}
Exam::Exam(  string position, 
	string lastname, string firstname,
	string name, string dateStartExam, int hours, int rating):Teacher::Teacher(position,lastname,firstname),
	 
	name(name),
	dateStartExam(dateStartExam),
	hours(hours),
	rating(rating)
{}
Exam::Exam( const Teacher& t, string name, string dateStartExam, int hours, int rating)
:Teacher(t),
 	name(name),
	dateStartExam(dateStartExam),
	hours(hours),
	rating(rating){}


Exam::Exam() {}
Exam::~Exam() {}
void Exam::SetExam(string name, string dateStartExam, int hours, int rating)
{
	this->name = name;
	this->dateStartExam = dateStartExam;
	this->hours = hours;
	this->rating = rating;

}
string Exam::get(int x) {
	
	while (x <=4)
	{
		switch (x)
		{
		case 1:
			return name;
		case 2:
			return dateStartExam;
		case 3:
			return to_string(hours);
		case 4:
			return to_string(rating);

		default:
			return "\nНазва предмету " + name + "\nДата проведення " + dateStartExam+"\nКількість годин на предмет " + to_string(hours)+"\nОцінка "+ to_string(rating);
			break;
		}
	}
	return "";



}
void Exam::Show()
{
	cout << get(0) << "\n"   << GetTeacher() << endl;
}