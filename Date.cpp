#include "Date.h"

int Date::CurrentDay() {
	time_t t = time(0);
	tm* now = localtime(&t);
	return now->tm_mday;
}

int Date::CurrentMonth() {
	time_t t = time(0);
	tm* now = localtime(&t);
	return now->tm_mon + 1;
}

int Date::CurrentYear() {
	time_t t = time(0);
	tm* now = localtime(&t);
	return now->tm_year + 1900;
}

int Date::CurrentDayOfTheWeek() {
	time_t t = time(0);
	tm* now = localtime(&t);
	return now->tm_wday;
}

void Date::DisplayNextWeek() {
	string day;

	date dateToDisplay;
	dateToDisplay.day = CurrentDay();
	dateToDisplay.month = CurrentMonth();
	dateToDisplay.year = CurrentYear();
	dateToDisplay.dayOfTheWeek = CurrentDayOfTheWeek();

	for (int i = 0; i < 7; i++) {
		if (dateToDisplay.dayOfTheWeek == 0) {
			day = "Sunday";
		}
		else if (dateToDisplay.dayOfTheWeek == 1) {
			day = "Monday";
		}
		else if (dateToDisplay.dayOfTheWeek == 2) {
			day = "Tuesday";
		}
		else if (dateToDisplay.dayOfTheWeek == 3) {
			day = "Wednesday";
		}
		else if (dateToDisplay.dayOfTheWeek == 4) {
			day = "Thursday";
		}
		else if (dateToDisplay.dayOfTheWeek == 5) {
			day = "Friday";
		}
		else if (dateToDisplay.dayOfTheWeek == 6) {
			day = "Saturday";
		}
		cout << "---------------------------------------------------------------------------------------------" << endl;
		dateToDisplay = DateCorrection(dateToDisplay.day, dateToDisplay.month, dateToDisplay.year, dateToDisplay.dayOfTheWeek);
		cout << day << " " << dateToDisplay.day << " " << dateToDisplay.month << " " << dateToDisplay.year << "\t|" << endl;
		dateToDisplay.day += 1;
		dateToDisplay.dayOfTheWeek += 1;
		if (dateToDisplay.dayOfTheWeek > 6) {
			dateToDisplay.dayOfTheWeek = 0;
		}
	}
	cout << "---------------------------------------------------------------------------------------------" << endl;
}

date Date::DateCorrection(int d, int m, int y, int dayWeek) {
	date correctedDate;

	if (d == 29)
	{
		if (m == 2)	//checking for february
		{
			if ((y % 400 == 0) || (y % 100 != 0 || y % 4 == 0))	//leap year check in case of feb
			{
				d = 29;
			}
			else
			{
				d = 1;
				m = 3;
			}
		}
		else	//when its not feb
			d += 1;
	}
	if (d == 29)	//last day check for feb
	{
		if (m == 2)
		{
			d = 1;
			m = 3;
		}
		else
			d += 1;
	}
	if (d == 30)	//last day check for april,june,September,November
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			d += 1;
		else
		{
			d = 1;
			m += 1;
		}
	}
	if (d == 31)	//last day of the month
	{
		d = 1;
		if (m == 12)	//checking for last day of the year
		{
			y += 1;
			m = 1;
		}
		else
			m += 1;
	}
	correctedDate.dayOfTheWeek = dayWeek;
	correctedDate.day = d;
	correctedDate.month = m;
	correctedDate.year = y;


	return correctedDate;
}