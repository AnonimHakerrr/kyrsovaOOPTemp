#include "RecordBook.h"



void RecordBook::resize()
{
	maxSize++;
	Exam* newExam = new Exam[maxSize];
	for (int  i = 0; i < size; i++)
	{
		newExam[i] = exam[i];
	}
	delete[] exam;
	exam = newExam;
}
RecordBook::RecordBook(int maxSize = 3) :maxSize(maxSize) { exam = new Exam[maxSize]; }
RecordBook::~RecordBook() { delete[] exam; }
int RecordBook::GetSize() {
    return size;
}

Exam& RecordBook::GetExamIndex(int index)
{
	if (index < 0 || index >= size) {
		throw out_of_range("За таким індексом нічого не знайдено");
	}
	return exam[index];
}
void RecordBook::Add(Exam exam)
{
	if(size==maxSize)
	{
		resize();
	}
	this->exam[size++] = exam;

}
void RecordBook::Delete(int index)
{
	Exam* newExam = new Exam[size - 1];
	for (int  i = 0; i < size; i++)
	{
		if((index-1)!=i)
		{
			newExam[i] = exam[i];
		}
	}
	delete[] exam;
	exam = newExam;
    --size;
 
}
Exam* RecordBook::begin() const { return exam; }
Exam* RecordBook::end() const { return exam + size; }