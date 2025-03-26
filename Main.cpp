#include <iostream>
#include <locale>
#include <windows.h>
#include "Menu.h"
#include <conio.h> 
#include "File.h"
using namespace  std;
 
void showMenu(int selected) {
    system("cls"); // �������� ������
    string menuItems[] = {
		"��������� ��������",
		"��������� ��������",
        "��������� �������� ��������",
		"��������� �������� ��� ��������",
		"���� ������ �������� �� �������",
		"���� ������ �������� ",
		"���� ��������� �� �������� ",
		"���� ��������� ��������",
		"���� �������� ��� ��������",
		"���������� �� ��������� ���",
		"���������� �������� �� ������ ��������",
        "������� � �����",
        "����� � ����",
        "�����"};

    cout << "������� ����� ����:\n";
    for (int i = 0; i < 14; ++i) {
        if (i == selected)
            cout << " -> ";
        else
            cout << "    ";

        cout << menuItems[i] << "\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);  
    Menu menu;
    int selected = 0;
    char key;

    do {
        showMenu(selected);
        key = _getch();

        switch (key) {
        case 72:
            if (selected > 0) selected--;
            break;
        case 80:
            if (selected < 13) selected++;
            break;
        case 13: 
        {
            switch (selected)
            {
            case 0:
                menu.setStudent();
                break;
            case 1:
                menu.deleteStudent(menu.SheachStudent());
                break;
            case 2:
                menu.deleteStudentExam(menu.SheachStudent());
                break;
            case 3:
                menu.setStudentExam(menu.SheachStudent());
                break;
            case 4:
                menu.AddratingExamStudent(menu.SheachStudent());
                break;
            case 5:
                menu.ShowListStud();
                break;
            case 6:
                menu.SeachExam();
                break;
            case 7:
                menu.ShowStud(menu.SheachStudent());
                break;
            case 8:
                menu.showMiddelRating(menu.SheachStudent());
                break;
            case 9 :
                menu.showStudentListAverage();
                break;
          
            case 10:
                menu.showStudentRatingExam();
                break;
            case 11:
            {
                File f("ListStudentAndExam.txt");
                vector<Student> s = f.ReadFile();
                menu.setListStudents(s);
                break;
            }
            case 12:
            {
                File f("ListStudentAndExam.txt");
                 menu.WriteFileStudens(f);
                 break;
            }
            default:
                break;
            }
            
            
            if (selected == 13) {
                cout << "�����...\n";
                return 0;
            }
            cout << endl;
            system("pause");
            break;
        }
        }

    } while (true);




	return 0;
}
