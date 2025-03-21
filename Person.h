#pragma once
#include <string>
using namespace std;
class Person
{
private:
	string lastname, firstname;
public:
	Person(string lastname, string firstname);
	Person(const Person& person) = default;
	Person(Person&& other)noexcept = default;
	Person();
	virtual ~Person();
	void SetPerson(string lastname, string firstname);
	string GetPerson();
	virtual	void Show();


	Person& operator=(const Person& other) = default;
	Person& operator=(Person&& other) noexcept = default;

	friend ostream& operator<<(ostream& os, const Person& person);

	friend istream& operator>>(istream& is, Person& person);


};

