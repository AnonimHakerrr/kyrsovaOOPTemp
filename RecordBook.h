#pragma once
#include "Exam.h"

class RecordBook
{
private:
	Exam* exam;
	int size;
	int maxSize;

	void resize();
public:
	RecordBook(int maxSize);
	~RecordBook();
	int GetSize();
	Exam& GetExamIndex(int index);
	void Add(Exam exam);
	void Delete(int index);
	Exam* begin() const;
	Exam* end() const;
};

