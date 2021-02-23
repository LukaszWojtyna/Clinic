#pragma once
#include "Doctor.h"
#include "Patient.h"
#include <iostream>
#include <vector>

class Clinic
{
private:
	vector<Doctor> doctorList;
	vector<Patient> patientList;

public:
	int GenerateID();
	int AddDoctor();
	int AddDoctor(string, string, string, string, int, string, int);
	void DisplayDoctorList();
	void EditDoctor();
	int SearchDoctor();
	int SearchDoctor(int ID);
	void DeleteDoctor();
	void AllEmployeesEarnings();

	void AddPatient();
	void AddPatient(string, string, string, string, int);
	void EditPatient();
	int SearchPatient();
	int SearchPatient(string);
	void DeletePatient();
	void DisplayPatientList();

	string InputPeselNumber();
	string InputTelephoneNumber();
};

