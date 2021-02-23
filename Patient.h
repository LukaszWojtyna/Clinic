#pragma once
#include <sstream>
#include <vector>
#include "Person.h"
#include "Doctor.h"

class Patient : public Person
{
private:
	int age;
public:
	Patient();
	Patient(string, string, string, string, int);
	~Patient();
	int Age();
	void SetAge(int);
};

