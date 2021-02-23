#include<ctime>
#include<iostream>
#pragma warning(disable : 4996)
using namespace std;

struct date {
	int dayOfTheWeek;
	int day;
	int month;
	int year;
};

class Date
{
public:
	int CurrentDay();
	int CurrentMonth();
	int CurrentYear();
	int CurrentDayOfTheWeek();
	void DisplayNextWeek();
	date DateCorrection(int, int, int, int);
};


