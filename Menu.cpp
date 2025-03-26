#include "Menu.h"





void Menu::setStudent() {
	Student studTemp;
	cin >> studTemp;
	stud.push_back(studTemp);
}
void  Menu::setStudentExam(int index)
{
	if (index != -1)
	{
		Exam x;
		cin >> x;
		stud[index].SetRecordBookStudent(x);
	}
}
void Menu::deleteStudent(int index)
{
	try {
		if (!stud.empty() && index != -1)
			stud.erase(stud.begin() + index);
		else
			throw runtime_error("\nСтудента не знайдено !");

	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}

void Menu::deleteStudentExam(int index)
{
	try {
		if (!stud.empty() && index != -1)
		{
			int x = 0;
			string str;
			cout << "Ведіть назву екзамену: ";
			cin >> str;

			RecordBook rec = stud[index].getRecordBookStudent();
			Iterator begin(rec.begin(), rec.end());
			Iterator end(rec.end(), rec.end());
			for (Iterator it = begin; it != end; ++it) {
				if ((*it).getNameExam() == str)
				{

					stud[index].deleteExam(x);
					break;
				}
				x++;
			}
			throw runtime_error("\nЕкзамена не знайдено !");
		}
		else
			throw runtime_error("\nСтудента не знайдено !");

	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}

void  Menu::ShowStud(int index) {
	try {
		if (!stud.empty() && index != -1)
		{
			stud[index].Show();

		}
		else
			cout << "\nСтудентів ще немає";
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
		if (!stud.empty())
		{
			for (Student st : stud)
			{
				cout << st.GetStudent();
			}
		}
		else
			throw runtime_error("\nСтудента не знайдено !");
	}
	catch (const runtime_error& e)
	{
		cout << e.what();

	}
}
int  Menu::SheachStudent()
{
	try
	{
		if (!stud.empty())
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

				return index;
			}
			else
				throw runtime_error("\nСтудента не знайдено !");
		}
	}
	catch (const runtime_error& e)
	{
		cout << e.what();
		return -1;
	}
}
void Menu::SeachExam()
{
	if (!stud.empty())
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
				if ((*it).getNameExam() == str)
					cout << st.GetStudent();

			}
		}
	}
	else
		cout << "\nСтудентів ще немає";
}
int Menu::showMiddelRating(int index)
{
	try {
		if (!stud.empty() && index != -1)
		{
			float averageScore = 0;
			int count = 0;

			RecordBook rec = stud[index].getRecordBookStudent();
			if (rec.GetSize()!=0) {
				Iterator begin(rec.begin(), rec.end());
				Iterator end(rec.end(), rec.end());
				for (Iterator it = begin; it != end; ++it) {

					averageScore += (*it).getRating();
					count++;
				}

				averageScore /= count;
				cout << "\nСередній бал струдента -> " << averageScore << endl;
				return averageScore;
			}
			else
			{
				return 0;
				throw runtime_error("\nСтудента не знайдено екаменів !");
			}
		}
		else
		{
			return 0;
			throw runtime_error("\nСтудента не знайдено !");
		}
	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}

void Menu::showStudentListAverage()
{
	try
	{
		if (!stud.empty())
		{
			vector<int> index(stud.size());


			for (int i = 0; i < index.size(); i++) {
				index[i] = i;
			}

			sort(index.begin(), index.end(), [this](const int a, const  int b) {
				system("cls");
				return showMiddelRating(a) > showMiddelRating(b);
				});

			for (int i : index)
			{
				cout << stud[i].GetStudent();
				showMiddelRating(i);
			}

		}
		else
			throw runtime_error("\nСтудента не знайдено  !");

	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}


void Menu::showStudentRatingExam()
{
	try {
		if (!stud.empty())
		{
			vector<Student> newStud;
			string str;
			int index = 0;
			cout << "Ведіть назву екзамену: ";
			cin >> str;
			for (Student st : stud)
			{
				RecordBook rec = st.getRecordBookStudent();
				Iterator begin(rec.begin(), rec.end());
				Iterator end(rec.end(), rec.end());
				for (Iterator it = begin; it != end; ++it) {
					if ((*it).getNameExam() == str)
					{
						newStud.push_back(st);
						break;
					}
					index++;

				}
			}
			sort(newStud.begin(), newStud.end(), [this, index](Student& a, Student& b) {
				return a.getRecordBookStudent().GetExamIndex(index).getRating() > b.getRecordBookStudent().GetExamIndex(index).getRating();
				});
			for (auto st : newStud)
			{
				cout << st.GetStudent();
			}
		}
		else
			throw runtime_error("\nСтудента не знайдено !");

	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}


void Menu::AddratingExamStudent(int index)
{
	try {
		if (!stud.empty() && index != -1)
		{
			int x = 0;
			string str;
			cout << "Ведіть назву екзамену: ";
			cin >> str;

			RecordBook rec = stud[index].getRecordBookStudent();
			Iterator begin(rec.begin(), rec.end());
			Iterator end(rec.end(), rec.end());
			for (Iterator it = begin; it != end; ++it) {
				if ((*it).getNameExam() == str)
				{
					int newRating;
					cout << "\nВведіть оцінку\n";
					cin >> newRating;
					(*it).Evaluation((*it), newRating);
					stud[index].SetRecordBookStudent((*it));
					stud[index].deleteExam(x);
					break;
				}
				x++;


			}


		}
		else
			throw runtime_error("\nСтудента не знайдено !");

	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}

void Menu::setListStudents(vector<Student>& st)
{
	try
	{
		if (!st.empty())
		{
			for (auto s:st)
			{
				if (find(stud.begin(), stud.end(), s) == stud.end()) {
					stud.push_back(s);
				}
			}
		}
		else
			throw runtime_error("\nСтудентів не знайдено !");

	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}
}

void Menu::WriteFileStudens(File& f)
{


	try
	{
		if (!stud.empty())
		{
			
			f.WriteFile(stud);

		}
		else
			throw runtime_error("\nСтудентів не знайдено !");

	}
	catch (const runtime_error& e)
	{
		cout << e.what();
	}

}
