#include <iostream>
 #include <locale>
#include "Menu.h"
#include <conio.h> 
using namespace  std;
 
void showMenu(int selected) {
    system("cls"); // Очищення консолі
    string menuItems[] = {
        "Додавання Студента",
        "Вивід списку студентів ",
        "Вивід струдентів по екзамену ",
        "Вивід екзаменів студента",
        "Вивід середній бал студента",
        "Сортування по сердньому балі",
        "Додавання екзамену для студента",
        "Сортування студентів по оцінці екзамену",
        "Зміна оцінки студента за екзамен",
        "Вихід"};

    cout << "Виберіть пункт меню:\n";
    for (int i = 0; i < 10; ++i) {
        if (i == selected)
            cout << " -> ";
        else
            cout << "    ";

        cout << menuItems[i] << "\n";
    }
}

int main() {
	setlocale(LC_CTYPE, "ukr");
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
            if (selected < 9) selected++;
            break;
        case 13: 
        {
            switch (selected)
            {
            case 0:
                menu.setStudent();
                break;
            case 1:
                menu.ShowListStud();
                break;
            case 2:
                menu.SeachExam();
                break;
            case 3:
                menu.ShowStud(menu.SheachStudent());
                break;
            case 4:
                menu.showMiddelRating(menu.SheachStudent());
                break;
            case 5 :
                menu.showStudentListAverage();
                break;
            case 6:
                menu.setStudentExam(menu.SheachStudent());
                break;
            case 7:
                menu.showStudentRatingExam();
                break;
            case 8:
                menu.AddratingExamStudent(menu.SheachStudent());
                break;
            default:
                break;
            }
            
            
            if (selected == 9) {
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
