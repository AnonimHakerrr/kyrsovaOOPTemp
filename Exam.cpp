
#include "Exam.h"

Exam::Exam(string name, string dateStartExam, int hours, int rating) :
	tech(),
	name(name),
	dateStartExam(dateStartExam),
	hours(hours),
	rating(rating) {}

Exam::Exam(TeacherPosition position,
	string lastname, string firstname,
	string name, string dateStartExam, int hours, int rating) :tech(position, lastname, firstname),
	name(name),
	dateStartExam(dateStartExam),
	hours(hours),
	rating(rating) {}

Exam::Exam(const Teacher& t, string name, string dateStartExam, int hours, int rating)
	:tech(t),
	name(name),
	dateStartExam(dateStartExam),
	hours(hours),
	rating(rating) {}

Exam::Exam() {}
Exam::~Exam() {}

void Exam::evaluation(Exam& exam, int rating) {
	try {
		if (rating >= 0 && rating <= 100) {
			exam.rating = rating;
		}
		else {
			throw invalid_argument("�������: ������ ������� ���� � ����� 0-100!");
		}
	}
	catch (invalid_argument e) {
		cout << e.what();
	}
}
void Exam::setExam(string name, string dateStartExam, int hours, int rating = 0) {
	this->name = name;
	this->dateStartExam = dateStartExam;
	this->hours = hours;
	this->rating = rating;
}
int Exam::getRating() {
	return rating;
}

string Exam::getNameExam() {
	return name;
}

void Exam::show() {
	cout << getInfoExam();
}

bool Exam::getValidNumber(istream& is, int& value) {
	string input;
	getline(is, input);
	stringstream ss(input);
	return (ss >> value) && ss.eof();
}

string Exam::getInfoExam() {
	return ("\n����� �������� : " + name +
		"\n���� ���������� : " + dateStartExam +
		"\nʳ������ ����� �� ������� : " + to_string(hours) +
		"\n������ : " + to_string(rating) +
		"\n" + tech.getTeacher());
}

istream& operator>>(istream& is, Exam& ex) {
	cout << "����� ����� �������� :";
	is >> ex.name;
	cout << "����� ���� �������:";
	is >> ex.dateStartExam;
	is.ignore();
	cout << "����� ������� ��������� �����:";
	while (!Exam::getValidNumber(is, ex.hours)) {
		cout << "\n�������! ������ �����: ";
	}
	cout << "����� ������� ���� :";
	while (!Exam::getValidNumber(is, ex.rating) && (ex.rating >= 0 && ex.rating <= 100)) {
		cout << "\n�������! ������ �����: ";
	}
	is >> ex.tech;
	return is;
}