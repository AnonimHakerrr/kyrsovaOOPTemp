
#include "Exam.h"



Exam::Exam(string name, string dateStartExam, int hours, int rating):
Teacher::Teacher(),
 
name(name),
dateStartExam(dateStartExam),
hours(hours),
rating(rating)
{}
Exam::Exam(TeacherPosition position, 
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

void Exam::Evaluation(Exam& exam,int rating){
	try {
		if (rating >= 0 && rating <= 100)
		{
			exam.rating = rating; 
			
		}
		else
		{
			throw invalid_argument("Помилка: оцінка повинна бути в межах 0-100!");
		}
	}catch(invalid_argument e)
	{
		cout << e.what();
 	}
}
void Exam::SetExam(string name, string dateStartExam, int hours, int rating=0)
{
	this->name = name;
	this->dateStartExam = dateStartExam;
	this->hours = hours;
	this->rating = rating;

}
int Exam::getRating()
{
	return rating;
}
string Exam::getNameExam()
{
	return name;

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
//			return "\nНазва предмету " + name + "\nДата проведення " + dateStartExam+"\nКількість годин на предмет " + to_string(hours)+"\nОцінка "+ to_string(rating);
//			break;
//		}
//}
void Exam::Show()
{
	cout << GetInfoExam();
}

bool Exam::getValidNumber(istream& is, int& value) {
	string input;
	getline(is, input);
	stringstream ss(input);
	return (ss >> value) && ss.eof();
}

string Exam::GetInfoExam()
{
	return ( "\nНазва предмету : " + name +
		"\nДата проведення : " + dateStartExam + 
		"\nКількість годин на предмет : " + to_string(hours) + 
		"\nОцінка : " + to_string(rating) +
		"\n"+ GetTeacher());
}
 

istream& operator>>(istream& is, Exam& ex)
{
	cout << "Ведіть назву предмета :";
	is >> ex.name;
	cout << "Ведіть дату початку:";
	is >> ex.dateStartExam;
	is.ignore();
	cout << "Ведіть кількість відведених годин:";
	while (!Exam::getValidNumber(is, ex.hours)) {
		cout << "\nПомилка! Введіть число: ";
	}
	cout << "Ведіть кількість балів :";
	while (!Exam::getValidNumber(is, ex.rating)&& (ex.rating >= 0 && ex.rating <= 100)) {
		cout << "\nПомилка! Введіть число: ";
	}
	is >> static_cast<Teacher&>(ex);


	return is;


}