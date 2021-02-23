#pragma once
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Person
{
private:
	string firstName;
	string lastName;
	string peselNumber;
	string telephoneNumber;
public:
	Person();
	Person(string, string, string, string);
	~Person();

	string FirstName() const;
	string LastName() const;
	string PeselNumber() const;
	string TelephoneNumber() const;

	void SetFirstName(string);
	void SetLastName(string);
	void SetPeselNumber(string);
	void SetTelephoneNumber(string);
};

