#pragma once
#include <string>
#include <vector>

#include "Exam.h"
using namespace std;
class File
{
private :
	string path;
public:
	File(string path);
	vector<vector<string>> ReadFile();
	void WriteFile(Exam& e);
	 
};

