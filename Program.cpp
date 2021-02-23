#include<iostream>
#include<Windows.h>
#include "Clinic.h"
#define _CRT_SECURE_NO_WARNIGS
#pragma warning(disable : 4996)
#pragma warning(disable : 4700)

using namespace std;

Clinic clinic;

// Function displaying the main menu 
void MainMenu() 
{
	HANDLE hKonsola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hKonsola, 15);
	cout << "____________ MAIN MENU ____________" << endl;
	cout << endl;
	SetConsoleTextAttribute(hKonsola, 8);
	cout << "1 - Patients management" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "2 - Employee management" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "3 - Exit program" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "Enter your choice: ";
}

// Function displaying the patient management menu
void PatientMenu() 
{
	HANDLE hKonsola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hKonsola, 15);
	cout << "___________ PATIENT MENU ___________" << endl;
	cout << endl;
	SetConsoleTextAttribute(hKonsola, 8);
	cout << "1 - Add patient" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "2 - Delete patient" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "3 - Search patient" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "4 - Edit patient" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "5 - Display patients list" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "0 - Back to main menu" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "Enter your choice: ";
}

// Funkcja sluzaca do wyswietlania menu do zarzadzania pracownikami
void EmployeeMenu() 
{
	HANDLE hKonsola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hKonsola, 15);
	cout << "___________ EMPLOYEE MENU ___________" << endl;
	cout << endl;
	SetConsoleTextAttribute(hKonsola, 8);
	cout << "1 - Add new doctor" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "2 - Display doctor list" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "3 - Edit doctor" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "4 - Search doctor by ID" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "5 - Delete doctor" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "6 - Total doctors salaries" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "0 - Back to main menu" << endl;
	cout << "_____________________________________" << endl;
	cout << endl;
	cout << "Enter your choice: ";
}

void main() 
{
	clinic.AddDoctor("Adam", "Nowak", "88120756465", "333444555", 123, "psycholog", 5433);
	clinic.AddDoctor("Tomasz", "Kowalski", "93121209876", "111333555", 322, "psycholog", 7567);
	clinic.AddDoctor("Elzbieta", "Pieczarka", "77060634212", "222444555", 545, "chirurg", 5766);
	clinic.AddDoctor("Ala", "Grzyb", "88040934212", "999888222", 883, "chirurg", 6755);
	clinic.AddDoctor("Witold", "Polak", "89011512312", "777888555", 638, "kardiolog", 6344);
	clinic.AddDoctor("Ryszard", "Wiec", "79091798712", "222000999", 399, "pediatra", 11223);
	clinic.AddDoctor("Karol", "Nowak", "66121854345", "666888111", 349, "kardiolog", 6755);

	clinic.AddPatient("Witold", "Prosty", "76121245365", "555666777", 44);
	clinic.AddPatient("Czeslaw", "Lampa", "95091577766", "777555333", 25);
	clinic.AddPatient("Danuta", "Koparka", "87040412333", "123123123", 33);

	// Set title of console window
	HWND consolWindow = GetConsoleWindow();
	LPCWSTR title = L"Clinic";
	SetWindowText(consolWindow, title);

	// char variable used to navigate in MainMenu
	char mainMenuNavigate; 

	// do while() loop performs functions MainMenu() until an appropriate character is entered 
	do 
	{
		MainMenu();
		cin >> mainMenuNavigate;
		system("CLS");

		// Conditional statement if you choose 1 in main menu then in
		// nested loop do while the PatientMenu() function will be called 
		// until an appropriate character is entered
		if (mainMenuNavigate == '1')
		{
			// char variable used to navigate in PatientMenu
			char patientMenuNavigate;

			do 
			{
				PatientMenu();
				cin >> patientMenuNavigate;
				if (patientMenuNavigate == '1')
				{
					system("CLS");
					cout << "________ DODAWANIE PACJENTA _________" << endl;
					cout << endl;
					clinic.AddPatient();
					system("CLS");
				}
				else if (patientMenuNavigate == '2')
				{
					system("CLS");
					clinic.DisplayPatientList();
					clinic.DeletePatient();
					system("PAUSE");
					system("CLS");
				} 
				else if (patientMenuNavigate == '3')
				{
					system("CLS");
					cout << "________ SZUKANIE PACJENTA __________" << endl;
					cout << endl;
					clinic.SearchPatient();
					system("PAUSE");
					system("CLS");
				}
				else if (patientMenuNavigate == '4')
				{
					system("CLS");
					clinic.DisplayPatientList();
					clinic.EditPatient();
					system("PAUSE");
					system("CLS");
				} 
				else if (patientMenuNavigate == '5')
				{
					system("CLS");
					clinic.DisplayPatientList();
					system("PAUSE");
					system("CLS");
				}
				else if (patientMenuNavigate == '0')
				{
					system("CLS");
				}
				else 
				{
					system("CLS");
					cout << "Wrong choice. Try again." << endl;
				}
			} while (patientMenuNavigate != '0');
		} 

		// Obsluga
		else if (mainMenuNavigate == '2')
		{
			char employeeMenuNavigate; // zmienna sluzaca do obslugi menuPracownika
			// Pêtla do .. while() wykonuje funkcje MenuPracownika() dopóki nie zostanie wprowadzony odpowiedni znak
			do 
			{
				EmployeeMenu();
				cin >> employeeMenuNavigate;
				if (employeeMenuNavigate == '1')
				{
					clinic.AddDoctor();
				}
				else if (employeeMenuNavigate == '2')
				{
					system("CLS");
					clinic.DisplayDoctorList();
					system("PAUSE");
					system("CLS");
				}
				else if (employeeMenuNavigate == '3')
				{
					system("CLS");
					clinic.DisplayDoctorList();
					clinic.EditDoctor();
					system("PAUSE");
				}
				else if (employeeMenuNavigate == '4')
				{
					clinic.SearchDoctor();
					cout << endl;
					system("PAUSE");
				}
				else if (employeeMenuNavigate == '5')
				{
					system("CLS");
					clinic.DisplayDoctorList();
					clinic.DeleteDoctor();
					system("PAUSE");
				}
				else if (employeeMenuNavigate == '6')
				{
					system("CLS");
					clinic.AllEmployeesEarnings();
					system("PAUSE");
				}
				else if (employeeMenuNavigate == '0')
				{
					system("CLS");
				}
				else
				{
					cout << "Wrong choice!";
				}
				system("CLS");
			} while (employeeMenuNavigate != '0');
		} 

		else if (mainMenuNavigate == '3')
		{
			cout << "Goodbye.";
		}

		else
		{
			system("CLS");
			cout << "Nieprawidlowy wybor!!! Wybierz ponownie \n" << endl;
		}
	} while (mainMenuNavigate != '3');
}