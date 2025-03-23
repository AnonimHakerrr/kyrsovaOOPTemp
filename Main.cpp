#include <iostream>
#include <string>
#include <locale>
#include <sstream>

#include <vector>
#include "Iterator.h"
#include "Exam.h"
#include "File.h"
#include "RecordBook.h"
#include "Student.h"
#include "Teacher.h"
using namespace  std;
 

int main() {
	setlocale(LC_CTYPE, "ukr");
	/*vector<Student> stud;
	vector<Teacher> tech;
stud.push_back(	Student ("ipzs-11", "Soltys", "Oleksandr"));
stud.push_back(Student ("ipzs-11", "�������", "���������"));
stud.push_back(Student ("ipzs-11", "�����", "����"));
stud.push_back(Student ("ipzs-11", "������", "�����"));
stud.push_back(Student ("ipzs-11", "������", "³����"));
tech.push_back(Teacher ("��������", "�����", "�������"));
tech.push_back(Teacher ("��������", "����������", "���������"));
tech.push_back(Teacher ("��������", "����", "���"));
 
	RecordBook rec(3);

	for (auto student : stud)
	{
		Exam e(student, tech.at(0), "������", "03.12.2024", 15, 5);
		rec.Add(e);
	}
	for (auto student : stud)
	{
		Exam e(student, tech.at(1), "����", "03.12.2024", 15, 5);
		rec.Add(e);
	}
	for (auto student : stud)
	{
		Exam e(student, tech.at(2), "���", "03.12.2024", 15, 5);
		rec.Add(e);
	}

	
	Iterator begin(rec.begin(), rec.end());
	Iterator end(rec.end(), rec.end());
	File file("C:/Users/oleks/Desktop/test2.txt");

	for (Iterator it = begin; it != end; ++it) {
		(*it).Show();
		file.WriteFile(*it);
	}
	cout << "\nSize : " << rec.GetSize();
	vector<vector<string > > str =file.ReadFile();
	for (auto x : str)
	{
			Exam exam(Student(x[4], x[5], x[6]), Teacher(x[7], x[8], x[9]), x[0], x[1], stoi(x[2]), stoi(x[3]));
			rec.Add(exam);
	}
	cout<<"\nSize : "<< rec.GetSize();
	 begin = Iterator(rec.begin(), rec.end());
	end = Iterator(rec.end(), rec.end());
	for (Iterator it = begin; it != end; ++it) {
		(*it).Show();
	 
	}
	cout << "\nSize : " << rec.GetSize();*/

	Teacher tech;
	cin >> tech;
	Student* stud=new Student("ipzs-11", "������", "³����",5);

	stud->SetRecordBookStudent(Exam(Teacher(positionToEnum("��������"), "�����", "�������"), "������", "03.12.2024", 15, 5));
 
	stud->Show();

	return 0;
}
