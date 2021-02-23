#include "Clinic.h"
#define _CRT_SECURE_NO_WARNIGS
#pragma warning(disable : 4700)
#pragma warning(disable : 4996)
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <random>

using namespace std;

/* Function which generate random 3 digit number which is used as an employee ID. Generates it
until it is unique*/
int Clinic::GenerateID()
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> ran(100, 1000);
	int generatedID;
	int whetherFound;
	do
	{
		generatedID = ran(rng);
		whetherFound = SearchDoctor(generatedID);
	} while (whetherFound >= 0);
	return generatedID;
}


// Function gets employee data, create the object of the Doctor class and add it to the doctor list 
int Clinic::AddDoctor()
{
	string fn; string ln; string pn; string tn; int id; string spec; int earn;
	cout << "Enter first name: ";
	cin >> fn;
	cout << "Enter last name: ";
	cin >> ln;
	cout << "Enter pesel number: ";
	cin >> pn;
	cout << "Enter telephone number: ";
	cin >> tn;
	cout << "Enter specialization: ";
	cin >> spec;
	cout << "Enter earnings: ";
	cin >> earn;
	id = GenerateID();

	Doctor doctor(fn, ln, pn, tn, id, spec, earn);
	
	doctorList.push_back(doctor);

	return id;
}

// Function create the object of the Doctor class and add it to the doctor list 
int Clinic::AddDoctor(string fn, string ln, string pn, string tn, int id, string spec, int earn)
{
	Doctor doctor(fn, ln, pn, tn, id, spec, earn);
	doctorList.push_back(doctor);
	return id;
}

// Funkction used to display all employees from doctor list
void Clinic::DisplayDoctorList()
{
	cout << left;
	cout << setw(7) << "ID";
	cout << setw(15) << "First Name";
	cout << setw(17) << "Last Name";
	cout << setw(17) << "Specialization";
	cout << setw(18) << "Telephone Number";
	cout << setw(15) << "Pesel Number";
	cout << setw(6) << "Earnings" << endl;
	cout << "________________________________________________________________________________________________" << endl;

	for (int i = 0; i < doctorList.size(); i++)
	{
		cout << left;
		cout << setw(7) << doctorList[i].ID();
		cout << setw(15) << doctorList[i].FirstName();
		cout << setw(17) << doctorList[i].LastName();
		cout << setw(17) << doctorList[i].Specialization();
		cout << setw(18) << doctorList[i].TelephoneNumber();
		cout << setw(15) << doctorList[i].PeselNumber();
		cout << setw(6) << doctorList[i].Earnings() << endl;

		cout << endl;
	}
}

/*Function which get employee ID and when it found employee with this ID then it allows you
to edit its data*/
void Clinic::EditDoctor()
{
	int editedID; string newFirstName; string newLastName; int newEarning; string newTelephoneNumber;
	cout << "Enter ID: ";
	cin >> editedID;
	int i = SearchDoctor(editedID);
	if (i >= 0)
	{
		cout << "Enter first name: ";
		cin >> newFirstName;
		doctorList[i].SetFirstName(newFirstName);
		cout << "Enter last name: ";
		cin >> newLastName;
		doctorList[i].SetLastName(newLastName);
		cout << "Enter earnings: ";
		cin >> newEarning;
		doctorList[i].SetEarnings(newEarning);
		cout << "Enter telephone number: ";
		cin >> newTelephoneNumber;
		doctorList[i].SetTelephoneNumber(newTelephoneNumber);
		cout << "Doctor details have been changed" << endl;
	}
	else if (i < 0)
	{
		cout << "There is no doctor with this ID" << endl;
	}
}

// Function get ID and search employee with this ID, when it finds, it return position in list of this employee's 
int Clinic::SearchDoctor()
{
	int searchedID;
	cout << "Enter ID: ";
	cin >> searchedID;
	for (int i = 0; i < doctorList.size(); i++)
	{
		if (doctorList[i].ID() == searchedID)
		{
			cout << "Found docotr with ID: " << searchedID << endl;
			cout << doctorList[i].FirstName() << " " << doctorList[i].LastName() << " " << doctorList[i].Specialization() << endl;
			return i;
		}
	}
	cout << "There is no doctor with this ID";
	return -1;
}

// Funkcja do szukania lekarza w liœcie, jako argument przyjmuje ID, u¿ywana wewnatrz innych funkcji zwraca indeks 
// znalezionego lekarza (-1 gdy nie znajdzie)
int Clinic::SearchDoctor(int searchedID)
{
	for (int i = 0; i < doctorList.size(); i++)
	{
		if (doctorList[i].ID() == searchedID)
		{
			return i;
		}
	}
	return -1;
}

// Funkcja wyszukuje indeks lekarza o podanym ID a nastêpnie usuwa go z listy
void Clinic::DeleteDoctor()
{
	int deleteID;
	cout << "Enter ID: ";
	cin >> deleteID;
	int del = SearchDoctor(deleteID);
	if (del < 0)
	{
		cout << "There is no doctor with this ID";
	}
	else
	{
		doctorList[del].~Doctor();
		doctorList.erase(doctorList.begin() + del);
		cout << "The doctor was successfully removed";
		cout << endl;
	}
}

// Funkcja oblicza sume zarobków wszystkich pracowników, po czym j¹ wypisuje
void Clinic::AllEmployeesEarnings()
{
	int sum = 0;
	for (int i = 0; i < doctorList.size(); i++)
	{
		sum = sum + doctorList[i].Earnings();
	}
	cout << "The sum of the earnings of all employees: " << sum << endl;

	int avg = sum / doctorList.size();
	cout << "Average earnings of employees : " << avg << endl;

	int min = doctorList[0].Earnings();
	int	max = doctorList[0].Earnings();
	for (int i = 0; i < doctorList.size(); i++)
	{
		if (doctorList[i].Earnings() < min)
		{
			min = doctorList[i].Earnings();
		}
		else if (doctorList[i].Earnings() > max)
		{
			max = doctorList[i].Earnings();
		}
	}
	cout << "Minimum earnings: " << min << endl;
	cout << "Maximum earnings: " << max << endl;
}

// Funkcja s³u¿aca do stworzenia nowego objektu klasy Pacjent i dodania do listy pacjentów
void Clinic::AddPatient()
{
	string fn; string ln; string pn; string tn; int age;
	cout << "Enter first name: ";
	cin >> fn;
	cout << "Enter last name: ";
	cin >> ln;
	pn = InputPeselNumber();
	cout << "Enter age: ";
	cin >> age;
	tn = InputTelephoneNumber();

	Patient	patient(fn, ln, pn, tn, age);
	patientList.push_back(patient);
}

// Funkcja s³u¿aca do stworzenia nowego objektu klasy Pacjent i dodania do listy pacjentów
void Clinic::AddPatient(string fn, string ln, string pn, string tn, int age)
{
	Patient patient(fn, ln, pn, tn, age);
	patientList.push_back(patient);
}

// Funkcja ktora pyta o pesel pacjenta po czym wyszukuje który to element z listy po czym pozwala na edytowanie niektorych danych 
// znalezionego pacjenta 
void Clinic::EditPatient()
{
	string editedPeselNumber; string newFirstName; string newLastName; string newPeselNumber; string newtelephoneNumber;
	cout << "Enter pesel number: ";
	cin >> editedPeselNumber;
	int i = SearchPatient(editedPeselNumber);
	if (i >= 0)
	{
		system("CLS");
		cout << "__________ EDYCJA PACJENTA __________" << endl;
		cout << endl;
		cout << "Enter first name: ";
		cin >> newFirstName;
		patientList[i].SetFirstName(newFirstName);
		cout << "Enter last name: ";
		cin >> newLastName;
		patientList[i].SetLastName(newLastName);
		cout << "Enter pesel number: ";
		cin >> newPeselNumber;
		patientList[i].SetPeselNumber(newPeselNumber);
		cout << "Enter telephone Number: ";
		cin >> newtelephoneNumber;
		patientList[i].SetTelephoneNumber(newtelephoneNumber);
		cout << "Patient details have been changed" << endl;
	}
	else if (i < 0)
	{
		cout << "There is no patient with this pesel" << endl;
	}
}

// Funkcja u¿yta w Menu do wyszukiwania pacjenta w liœcie o podanym peselu i zwraca jego indeks z listy (-1 gdy nie znajdzie)
int Clinic::SearchPatient()
{
	string searchedPesel;
	cout << "Enter pesel number: ";
	cin >> searchedPesel;
	for (int i = 0; i < patientList.size(); i++)
	{
		if (patientList[i].PeselNumber() == searchedPesel)
		{
			cout << "Found patient with this pesel: " << searchedPesel << endl;
			cout << patientList[i].FirstName() << " " << patientList[i].LastName() << " " << patientList[i].PeselNumber() << endl;
			return i;
		}
	}
	cout << "There is no patient with this pesel\n";
	return -1;
}

// Funkcja do szukania pacjenta w liœcie, jako argument przyjmuje pesel, u¿ywana wewnatrz innych funkcji zwraca indeks 
// znalezionego pacjenta (-1 gdy nie znajdzie)
int Clinic::SearchPatient(string searchedPesel)
{
	for (int i = 0; i < patientList.size(); i++)
	{
		if (patientList[i].PeselNumber() == searchedPesel)
		{
			return i;
		}
	}
	return -1;
}

// Funkcja wyszukuje indeks pacjenta o podanym peselu a nastêpnie usuwa go z listy
void Clinic::DeletePatient()
{
	string deletePesel;
	cout << "Enter pesel number: ";
	cin >> deletePesel;
	int del = SearchPatient(deletePesel);
	if (del < 0)
	{
		cout << "There is no patient with this pesel";
	}
	else
	{
		patientList[del].~Patient();
		patientList.erase(patientList.begin() + del);
		cout << "The patient was successfully removed";
		cout << endl;
	}
}

void Clinic::DisplayPatientList()
{
	cout << left;
	cout << setw(15) << "Pesel number";
	cout << setw(15) << "First Name";
	cout << setw(17) << "Last Name";
	cout << setw(8) << "Age";
	cout << setw(18) << "Telephone number" << endl;
	cout << "________________________________________________________________________________________________" << endl;

	for (int i = 0; i < patientList.size(); i++)
	{
		cout << left;
		cout << setw(15) << patientList[i].PeselNumber();
		cout << setw(15) << patientList[i].FirstName();
		cout << setw(17) << patientList[i].LastName();
		cout << setw(8) << patientList[i].Age();
		cout << setw(18) << patientList[i].TelephoneNumber() << endl;

		cout << endl;
	}
}

// Funkcja zczytuje znaki z klawiatury do momentu gdy petla for osiagnie warunek koncowy 
// lub gdy uzytkownik wprowadzi znak ktory nie jest cyfra(dotyczy wszystkich klawiszy)
string Clinic::InputPeselNumber() {
	string pesel;
	char currentDigit;

	cout << "Enter pesel number: ";
	for (int i = 1; i <= 11; ++i)
	{
		currentDigit = getch();
		if (isdigit(currentDigit))
		{
			pesel += currentDigit;
			cout << currentDigit;
		}
		else
		{
			i = 0;
			pesel = "";
			cout << " Entered value is not a number.\nEnter pesel number: ";
		}
		cout << endl;
		return pesel;
	}
}

// Funkcja zczytuje znaki z klawiatury do momentu gdy petla for osiagnie warunek koncowy 
// lub gdy uzytkownik wprowadzi znak ktory nie jest cyfra(dotyczy wszystkich klawiszy)
string Clinic::InputTelephoneNumber() {
	string numerTelefonu;
	char currentDigit;

	cout << "Enter telephone number: ";
	for (int i = 1; i <= 9; ++i)
	{
		currentDigit = getch();
		if (isdigit(currentDigit))
		{
			numerTelefonu += currentDigit;
			cout << currentDigit;
		}
		else
		{
			i = 0;
			numerTelefonu = "";
			cout << " Entered value is not a number.\nEnter telephone number: ";
		}
		cout << endl;
		return numerTelefonu;
	}
}
