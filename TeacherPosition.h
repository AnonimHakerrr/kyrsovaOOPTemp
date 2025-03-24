#pragma once

#include <string>
using namespace std;
enum class TeacherPosition
{
	Assistant,
	Lecturer,
	SeniorLecturer,
	Docent,
	Professor,
}; 

string positionToString(TeacherPosition techpos);

TeacherPosition positionToEnum(string techpos);