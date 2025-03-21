#pragma once
#include "Exam.h"

using namespace std;

class Iterator
{
private:
	Exam* current;
	Exam* end;
public:
	Iterator(Exam* current, Exam* end);
	Exam& operator*() const;
	Iterator& operator++();
	bool operator==(const Iterator& other) const;
	bool operator!=(const Iterator& other) const;

};

