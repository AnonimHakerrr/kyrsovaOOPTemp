#pragma once

#include <string>
using namespace std;
enum class TeacherPosition
{
	Assistant,
	Lecturer,
	Director,
};

string positionToString(TeacherPosition techpos);

TeacherPosition positionToEnum(string techpos);