#include "Iterator.h"

Iterator::Iterator(Exam* current, Exam* end) :current(current), end(end) {}

Exam& Iterator::operator*() const {
	if (current == end) {
		throw  out_of_range("Ітератор не в зоні");
	}
	return *current;
}

Iterator& Iterator::operator++() {
	if (current < end) {
		++current;
	}
	return *this;
}

bool Iterator::operator==(const Iterator& other) const {
	return current == other.current;
}

bool Iterator::operator!=(const Iterator& other) const {
	return current != other.current;
}
