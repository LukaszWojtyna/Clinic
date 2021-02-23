#include "Patient.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNIGS
#pragma warning(disable : 4996)

Patient::Patient()
{}

Patient::Patient(string name, string lastName, string peselNumber, string telephoneNumber, int a)
{
	SetFirstName(name);
	SetLastName(lastName);
	SetPeselNumber(peselNumber);
	SetTelephoneNumber(telephoneNumber);
	age = a;
}

Patient::~Patient()
{}

int Patient::Age()
{
	return age;
}

void Patient::SetAge(int a)
{
	age = a;
}