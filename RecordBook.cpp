#include "RecordBook.h"



void RecordBook::resize() {
	maxSize++;
	Exam* newExam = new Exam[maxSize];
	for (int i = 0; i < size; i++) {
		newExam[i] = exam[i];
	}
	delete[] exam;
	exam = newExam;
}

RecordBook::RecordBook(const RecordBook& other) {
	size = other.size;
	maxSize = other.maxSize;
	exam = new Exam[maxSize];
	for (int i = 0; i < size; i++) {
		exam[i] = other.exam[i];
	}
}

RecordBook::RecordBook(int maxSize = 3) :maxSize(maxSize) {
	exam = new Exam[maxSize];
}

RecordBook::~RecordBook() {
	delete[] exam;
}

int RecordBook::getSize() {
	return size;
}

Exam& RecordBook::getExamIndex(int index) {
	try {
		if (index < 0 || index >= size) {
			throw out_of_range("За таким індексом нічого не знайдено");
		}
		return exam[index];
	}
	catch (out_of_range e) {
		cout << e.what();
	}
}

void RecordBook::add(Exam exam) {
	if (size == maxSize) {
		resize();
	}
	this->exam[size++] = exam;
}

void RecordBook::deleteExam(int index) {
	Exam* newExam = new Exam[size - 1];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (index != i) {
			newExam[j] = exam[i];
			j++;
		}
	}
	delete[] exam;
	this->exam = newExam;
	--this->size;
}
RecordBook& RecordBook::operator=(const RecordBook& other) {
	if (this != &other) {
		delete[] exam;
		size = other.size;
		maxSize = other.maxSize;
		exam = new Exam[maxSize];
		for (int i = 0; i < size; i++) {
			exam[i] = other.exam[i];
		}
	}
	return *this;
}
RecordBook& RecordBook::operator=(RecordBook&& other) noexcept {
	if (this != &other) {
		delete[] exam;
		size = other.size;
		maxSize = other.maxSize;
		exam = other.exam;
		other.exam = nullptr;
		other.size = 0;
		other.maxSize = 0;
	}
	return *this;
}

Exam* RecordBook::begin() const {
	return exam;
}

Exam* RecordBook::end() const {
	return exam + size;
}