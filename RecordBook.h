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
	int GetSize();
	Exam& GetExamIndex(int index);
	void Add(Exam exam);
	void Delete(int index);
	RecordBook& operator=(const RecordBook& other);
	RecordBook& operator=(RecordBook&& other) noexcept;
	Exam* begin() const;
	Exam* end() const;
};

