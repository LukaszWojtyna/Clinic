#include "Person.h"

Person::Person(){}

Person::Person(string fn, string ln, string pn, string tn)
{
	SetFirstName(fn);
	SetLastName(ln);
	SetPeselNumber(pn);
	SetTelephoneNumber(tn);
}

Person::~Person(){}

string Person::FirstName() const
{
	return firstName;
}

string Person::LastName() const
{
	return lastName;
}

string Person::PeselNumber() const
{
	return peselNumber;
}

string Person::TelephoneNumber() const
{
	return telephoneNumber;
}

void Person::SetFirstName(string fn)
{
	firstName = fn;
}

void Person::SetLastName(string ln)
{
	lastName = ln;
}

void Person::SetPeselNumber(string pn)
{
	peselNumber = pn;
}

void Person::SetTelephoneNumber(string tn)
{
	telephoneNumber = tn;
}