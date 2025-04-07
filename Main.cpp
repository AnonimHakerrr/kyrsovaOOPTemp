#include <iostream>
#include <locale>
#include <windows.h>
#include "Menu.h"
#include <conio.h> 
#include "File.h"
using namespace  std;
 
void showMenu(int selected) {
    system("cls"); // Очищення консолі
    string menuItems[] = {
/*0*/		"Додавання Студента",
/*1*/	    "Видалення студента",
/*2*/       "Видалення екзамену студента",
/*3*/		"Додавання екзамену для студента",
/*4*/		"Зміна оцінки студента за екзамен",
/*5*/		"Вивід списку студентів ",
/*6*/		"Вивід струдентів по екзамену ",
/*7*/		"Вивід екзаменів студента",
/*8*/		"Вивід середній бал студента",
/*9*/		"Сортування по сердньому балу",
/*10*/		"Сортування студентів по оцінці екзамену",
/*11*/       "Читання з файлу",
/*12*/       "Запис у файл",
/*13*/       "Вихід"};

    cout << "Виберіть пункт меню:\n";
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
                menu.deleteStudent(menu.sheachStudent());
                break;
            case 2:
                menu.deleteStudentExam(menu.sheachStudent());
                break;
            case 3:
                menu.setStudentExam(menu.sheachStudent());
                break;
            case 4:
                menu.addratingExamStudent(menu.sheachStudent());
                break;
            case 5:
                menu.showListStud();
                break;
            case 6:
                menu.seachExam();
                break;
            case 7:
                menu.showStud(menu.sheachStudents());
                break;
            case 8:
                menu.showMiddelRating(menu.sheachStudent());
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
                vector<Student> s = f.readFile();
                menu.setListStudents(s);
                cout << "Файл прочитаний" << endl;
                break;
            }
            case 12:
            {
                File f("ListStudentAndExam.txt");
                 menu.writeFileStudens(f);
                 cout << "Файл записаний" << endl;

                 break;
            }
            default:
                break;
            }
            
            
            if (selected == 13) {
                cout << "Вихід...\n";
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
