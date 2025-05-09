#include "Menu.h"
#include <Windows.h>
 

void Menu::setStudent() {
	Student studTemp;
	cin >> studTemp;
	stud.push_back(studTemp);
	cout << "\n�������� ������" << endl;
}
void  Menu::setStudentExam(int index) {
	if (index != -1) {
		Exam x;
		cin >> x;
		stud[index].setRecordBookStudent(x);

		cout << "\n������� ������ � ������� ������ ��������" << endl;
	}
}
void Menu::deleteStudent(int index)
{
	if (index != -1) {
		stud.erase(stud.begin() + index);
		cout << "\n�������� ��������" << endl;
	}
}

void Menu::deleteStudentExam(int index)
{
	if (index != -1) {
		int x = 0;
		string str;
		cout << "����� ����� ��������: ";
		cin >> str;
		RecordBook rec = stud[index].getRecordBookStudent();
		Iterator begin(rec.begin(), rec.end());
		Iterator end(rec.end(), rec.end());
		for (Iterator it = begin; it != end; ++it) {
			if ((*it).getNameExam() == str) {
				stud[index].deleteExam(x);
				cout << "\n������ �������� �� ������� ������ ��������" << endl;
				break;
			}
			x++;
		}
		if (x == rec.getSize()) {
			throw runtime_error("\n�������� �� �������� !");
		}
	}
}

void  Menu::showStud(vector<int> index) {
	if (index.size() != 0) {
		for (int i : index) {
			stud[i].show();
		}
	}

}

void  Menu::showListStud()
{
	try {
		if (stud.empty()) {
			throw runtime_error("\n�������� �� �������� !");
		}
		for (auto& st : stud) {
			cout << st.getStudent();
		}
	}
	catch (const runtime_error& e) {
		cout << e.what();

	}
}
int  Menu::sheachStudent()
{
	try {
		if (stud.empty()) {
			throw runtime_error("\n�������� �� �������� !");
		}
		Student seachStud;
		cin >> seachStud;
		auto it = find(stud.begin(), stud.end(), seachStud);
		if (it != stud.end()) {
			int index = distance(stud.begin(), it);
			return index;
		}
		throw runtime_error("\n�������� �� �������� !");


	}
	catch (const runtime_error& e) {
		cout << e.what();
		return -1;
	}
}
vector<int> Menu::sheachStudents() {
	
	vector<int> indexs;
	try {
		if (stud.empty()) {
			throw runtime_error("\n�������� �� ��������!");
		}
		string input;
		cout << "������ �������� ����� ��������: ";
		cin.clear(); 
		do {
			getline(cin, input);
		} while (input == "");
		vector<string> words;
		istringstream iss(input);
		string word;
		while (iss >> word) {
			words.push_back(word);
		}
		for (size_t i = 0; i < stud.size(); ++i) {
			string studentDescription = stud[i].getStudent();
			bool allWordsFound = true;
			for (const auto& w : words) {
				if (studentDescription.find(w) == string::npos) {
					allWordsFound = false;
					break;
				}
			}
			if (allWordsFound) {
				indexs.push_back(i);
			}
		}
		if (indexs.empty()) {
			throw runtime_error("\n�������� �� ��������!");
		}
		return indexs;
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
		return {};
	}
}

void Menu::seachExam()
{
	try {
		if (stud.empty()) {
			throw runtime_error("\n�������� �� �������� !");
		}
		string str;
		cout << "����� ����� ��������: ";
		cin >> str;
		for (auto& st : stud) {
			RecordBook rec = st.getRecordBookStudent();
			Iterator begin(rec.begin(), rec.end());
			Iterator end(rec.end(), rec.end());
			for (Iterator it = begin; it != end; ++it) {
				if ((*it).getNameExam() == str)
					cout << st.getStudent();
			}
		}
	}
	catch (runtime_error e) {
		cout << e.what() << endl;
	}
}
int Menu::showMiddelRating(int index)
{
	if (index != -1) {
		float averageScore = 0;
		int count = 0;
		RecordBook rec = stud[index].getRecordBookStudent();
		if (rec.getSize() != 0) {
			Iterator begin(rec.begin(), rec.end());
			Iterator end(rec.end(), rec.end());
			for (Iterator it = begin; it != end; ++it) {
				averageScore += (*it).getRating();
				count++;
			}
			averageScore /= count;
			cout << "\n�������� ��� ��������� -> " << averageScore << endl;
			return averageScore;
		}
	}
	return 0;

}

void Menu::showStudentListAverage()
{
	try
	{
		if (stud.empty()) {
			throw runtime_error("\n�������� �� ��������  !");
		}
		vector<int> index(stud.size());
		for (int i = 0; i < index.size(); i++) {
			index[i] = i;
		}
		sort(index.begin(), index.end(), [this](const int a, const  int b) {
			return showMiddelRating(a) > showMiddelRating(b);
			});
		system("cls");

		for (int i : index) {
			cout << stud[i].getStudent();
			showMiddelRating(i);
		}
	}
	catch (const runtime_error& e) {
		cout << e.what();
	}
}


void Menu::showStudentRatingExam()
{
	try {
		if (stud.empty()) {
			throw runtime_error("\n�������� �� �������� !");
		}
		vector<Student> newStud;
		string str;
		int index = 0;
		cout << "����� ����� ��������: ";
		cin >> str;
		for (auto& st : stud) {
			RecordBook rec = st.getRecordBookStudent();
			if (rec.getSize() != 0) {
				Iterator begin(rec.begin(), rec.end());
				Iterator end(rec.end(), rec.end());
				for (Iterator it = begin; it != end; ++it) {
					if ((*it).getNameExam() == str) {
						newStud.push_back(st);
						break;
					}
					index++;
				}
			}

		}
		sort(newStud.begin(), newStud.end(), [this, index](auto& a, auto& b) {
			return a.getRecordBookStudent().getExamIndex(index).getRating() > b.getRecordBookStudent().getExamIndex(index).getRating();
			});
		for (auto& st : newStud) {
			cout << st.getStudent();
		}
	}
	catch (const runtime_error& e) {
		cout << e.what();
	}
}


void Menu::addratingExamStudent(int index)
{
	try {
		if (index != -1) {
			int x = 0;
			string str;
			cout << "����� ����� ��������: ";
			cin >> str;
			RecordBook rec = stud[index].getRecordBookStudent();
			if (rec.getSize() == 0) {
				throw runtime_error("\n�������� �� �������� ������a !");
			}
			Iterator begin(rec.begin(), rec.end());
			Iterator end(rec.end(), rec.end());
			for (Iterator it = begin; it != end; ++it) {
				if ((*it).getNameExam() == str) {
					int newRating;
					cout << "\n������ ������\n";
					cin >> newRating;
					(*it).evaluation((*it), newRating);
					stud[index].setRecordBookStudent((*it));
					stud[index].deleteExam(x);
					cout << "\n������ ������" << endl;
					break;
				}
				x++;
			}
			if (x == rec.getSize()) {
				cout << "\n�������� �� ��������" << endl;
			}
		}
	}
	catch (runtime_error e) {
		cout << e.what() << endl;
	}
}

void Menu::setListStudents(vector<Student>& st) {
	try {
		if (st.empty()) {
			throw runtime_error("\n�������� �� �������� !");
		}
		for (auto s : st) {
			if (find(stud.begin(), stud.end(), s) == stud.end()) {
				stud.push_back(s);
			}
		}
	}
	catch (const runtime_error& e) {
		cout << e.what();
	}
}

void Menu::writeFileStudens(File& f) {
	try {
		if (stud.empty()) {
			throw runtime_error("\n�������� �� �������� !");
		}
		f.writeFile(stud);
	}
	catch (const runtime_error& e) {
		cout << e.what();
	}

}
