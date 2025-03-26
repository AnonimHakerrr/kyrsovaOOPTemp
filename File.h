#pragma once
#include <string>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Student.h"
#include "Exam.h"
using namespace std;
class File
{
private :
	string path;
public:
	File(string path);
	vector<Student> ReadFile();
	void WriteFile(vector<Student> stud);
	string cleanText(const string& text);
	vector<string> split(const string& str, char delimiter);
 };

