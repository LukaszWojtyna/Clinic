#include "Doctor.h"

Doctor::Doctor()
{}

Doctor::Doctor(string fn, string ln, string pn, string tn, int id, string spec, int earn)
{
	SetFirstName(fn);
	SetLastName(ln);
	SetPeselNumber(pn);
	SetTelephoneNumber(tn);
	idNumber = id;
	specialization = spec;
	earnings = earn;
}

Doctor::~Doctor()
{}

int Doctor::ID()
{
	return idNumber;
}

double Doctor::Earnings()
{
	return earnings;
}

string Doctor::Specialization()
{
	return specialization;
}

void Doctor::SetID(int id)
{
	idNumber = id;
}

void Doctor::SetEarnings(int earn)
{
	earnings = earn;
}