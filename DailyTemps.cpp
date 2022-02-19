// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  1 - Exercise 2

#include "DailyTemps.hpp" // Provides DailyTemps.hpp file's class Definitions.
#include <iostream> // Provides input and output stream.
#include <iomanip> // Provides output/input manipulations

using namespace std;

// Reads the input from the user for the temperature for each day of the week and initializes the private variables of the object,
DailyTemps::DailyTemps()
{
	cout << "Enter the temperature for each day:" << endl;
	cout << "Monday (M): ";
	cin >> mon_temp;
	cout << "Tuesday (T): ";
	cin >> tue_temp;
	cout << "Wednesday (W): ";
	cin >> wed_temp;
	cout << "Thursday (R): ";
	cin >> thu_temp;
	cout << "Friday (F): ";
	cin >> fri_temp;
	cout << "Saturday (S): ";
	cin >> sat_temp;
	cout << "Sunday (U): ";
	cin >> sun_temp;
}

// Sets the temperature of the day from provided day and the new temperature to set.
void DailyTemps::setTemps(char day_char, double new_temp)
{ 
	// Toggle through each case statement that matches the switch statement and execute setter function for that day.
	switch (day_char)
	{
		case 'M':
			setMonTemp(new_temp);
			break;
		case 'T':
			setTueTemp(new_temp);
			break;
		case 'W':
			setWedTemp(new_temp);
			break;
		case 'R':
			setThuTemp(new_temp);
			break;
		case 'F':
			setFriTemp(new_temp);
			break;
		case 'S':
			setSatTemp(new_temp);
			break;
		case 'U':
			setSunTemp(new_temp);
			break;
		default:
			cout << "Invalid Day Name Char" << endl; // If the given input does not match return with error statement.
	}
	printTemps();
}

// Returns the first day with warmest temperature value.
string DailyTemps::Warmest()
{
	// Change the temperature value of each day to array to find maximum temperature.
	double array_temp[7] = {getMonTemp(), getTueTemp(), getWedTemp(), getThuTemp(), getFriTemp(), getSatTemp(), getSunTemp()};
	int max_temp_index = 0;
	double max_temp = array_temp[0];
	
	// Finding max value for loop.
	for (int i = 1; i < 7; i++)
    {
        if (array_temp[i] > max_temp)
        {
            max_temp = array_temp[i];
            max_temp_index = i;
        }
    }
	
	// Switch-Case statement to return the day name for the max temp index found.
	switch (max_temp_index)
	{
		case 0:
			return "Monday";
		case 1:
			return "Tuesday";
		case 2:
			return "Wednesday";
		case 3:
			return "Thursday";
		case 4:
			return "Friday";
		case 5:
			return "Saturday";
		case 6:
			return "Sunday";
		default:
			return "Error Finding Warmest Temperature!"; // Returs error message if there is error.
	}
}

// Returns numbers of days with temperature less than or equal to 32.
int DailyTemps::Freezing() const
{
	double array_temp[7] = {getMonTemp(), getTueTemp(), getWedTemp(), getThuTemp(), getFriTemp(), getSatTemp(), getSunTemp()};
	int below_freezing = 0;
	for (int i = 0; i < 7; i++)
    {
        if (array_temp[i] <= 32)
        {
            below_freezing += 1;
        }
    }
	return below_freezing;
}

// prints the days of the week and its temperature with well formatted.
void DailyTemps::printTemps() const
{
	cout << "  Day Names"   << "     " << "Temperature" << endl;
	cout << "=============   ===========" << endl;
	cout << setw(13) << right << "Monday (M)"    << "    " << setw(9) << right << getMonTemp() << endl;
	cout << setw(13) << right << "Tuesday (T)"   << "    " << setw(9) << right << getTueTemp() << endl;
	cout << setw(13) << right << "Wednesday (W)" << "    " << setw(9) << right << getWedTemp() << endl;
	cout << setw(13) << right << "Thursday (R)"  << "    " << setw(9) << right << getThuTemp() << endl;
	cout << setw(13) << right << "Friday (F)"    << "    " << setw(9) << right << getFriTemp() << endl;
	cout << setw(13) << right << "Saturday (S)"  << "    " << setw(9) << right << getSatTemp() << endl;
	cout << setw(13) << right << "Sunday (U)"    << "    " << setw(9) << right << getSunTemp() << endl;	
}

