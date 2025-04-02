#pragma once
#include <string>
using namespace std;
class Person{
private:
	string lastname, firstname;
public:
	Person(string lastname, string firstname);
	Person(const Person& person) = default;
	Person(Person&& other)noexcept = default;
	Person();
	virtual ~Person();
	void setPerson(string lastname, string firstname);
	string getPerson();
	virtual	void show();
	Person& operator=(const Person& other) = default;
	Person& operator=(Person&& other) noexcept = default;
	bool operator ==(const Person& other);
	friend ostream& operator<<(ostream& os, const Person& person);
	friend istream& operator>>(istream& is, Person& person);


};

