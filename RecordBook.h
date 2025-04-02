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
	RecordBook(const RecordBook& other);
	RecordBook(int maxSize);
	~RecordBook();
	int getSize();
	Exam& getExamIndex(int index);
	void add(Exam exam);
	void deleteExam(int index);
	RecordBook& operator=(const RecordBook& other);
	RecordBook& operator=(RecordBook&& other) noexcept;
	Exam* begin() const;
	Exam* end() const;
};

