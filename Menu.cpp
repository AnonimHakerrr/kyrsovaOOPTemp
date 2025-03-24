#include "Menu.h"
#include "Iterator.h"




void Menu::setStudent() {
	Student studTemp;
	cin >> studTemp;
	stud.push_back(studTemp);
}
void  Menu::setStudentExam(int index)
{
	Exam x;
	cin >> x;
	stud[index].SetRecordBookStudent(x);
}
void  Menu::ShowStud() {
	try {
		for (Student st : stud)
		{
			st.Show();
		}
	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}

void  Menu::ShowListStud()
{
	try
	{
		for (Student st : stud)
		{
			st.GetStudent();
		}
	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}
int  Menu::SheachStudent()
{
	Student seachStud;
	cin >> seachStud;
	/*for (Student st : stud)
	{
		if (seachStud == st)
			st.Show();

	}*/

	auto it = find(stud.begin(), stud.end(), seachStud);
	if (it != stud.end()) {
		int index = distance(stud.begin(), it);
		it->Show();
		return index;
	}
	else
		throw runtime_error("Студента не знайдено у векторі!");
}
void Menu::SeachExam()
{
	string str;
	cout << "Ведіть назву екзамену: ";
	cin >> str;
	for (Student st : stud)
	{
		RecordBook rec = st.getRecordBookStudent();
		Iterator begin(rec.begin(), rec.end());
		Iterator end(rec.end(), rec.end());
		for (Iterator it = begin; it != end; ++it) {
			if ((*it).getNameExam().compare(str))
				st.GetStudent();

		}
	}
}