// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  1 - Exercise 2

#include "DailyTemps.hpp"
#include <iostream> // Provides input/output stream.

using namespace std;
int main()
{
	// Allows the user to interact with the application.
	char start_over = 'Y';
	
	while (start_over == 'Y')
	{
		DailyTemps temp_for_Weeks;
		temp_for_Weeks.printTemps();
		char day_char; // Variable for user input day name
		double new_temperature; // Variable for user input temperature value
		cout << "Enter the character and the temperature you wish to set to (Ex: For Monday -> M and Temperature -> 999):" << endl;
		cout << "Day Character -> ";
		cin >> day_char;
		cout << "Temperature -> ";
		cin >> new_temperature;
		cout << endl;
		temp_for_Weeks.setTemps(day_char, new_temperature); // Sets new temperature value for the day name given.
		cout << endl;
		cout << "Number of Freezing days (temp < 32) is: " << temp_for_Weeks.Freezing() << endl; // Returns freezing days.
		cout << "The Warmest Day of the Week is: " << temp_for_Weeks.Warmest() << endl; // Returns warmest days.
		cout << "Do you want to start over? (Y/N): ";
		cin >> start_over;
	}
	return EXIT_SUCCESS;
}

