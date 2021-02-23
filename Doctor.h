#pragma once
#include "Person.h"

class Doctor : public Person
{
private:
	int idNumber;
	string specialization;
	int earnings;
public:
	Doctor();
	Doctor(string, string, string, string, int, string, int);
	~Doctor();

	int ID();
	double Earnings();
	string Specialization();

	void SetID(int);
	void SetEarnings(int);
};

