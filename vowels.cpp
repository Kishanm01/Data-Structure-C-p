// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  5

#include <iostream> // Provides Input/Output Stream
#include <iomanip>  // Provides Input/Output Manipulation
#include <limits>   // Provides max() function

using namespace std;

// PRE CONDITION: A menu is displayed to the user.
// POST CONDITION: Return user input value.
int get_command()
{
	int command;
	
	// Prompt user to enter menu number and Read input value
	cout << "Enter option number: ";
	cin >> command;
	if (cin.fail())                                            // Check if user entered value other than int
	{
		cin.clear();										   // Clear cin errors
		cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Move the cin cursor to the next line by ignoring the rest of input on the line
	}
	return command;
}

// POST CONDITION: A menu prompt is display.
void display_menu()
{
	cout << endl;
	cout << "---------MAIN MENU---------" << endl;
	cout << "1. Read input string"        << endl;
	cout << "2. Compute number of vowels" << endl;
	cout << "3. Exit program"             << endl;
	cout << "---------------------------" << endl;
}

// PRE CONDITION: inptStr is declared, initialized, and non-null
// POST CONDITION: counts vowels in the given string
size_t countVowels(string inptStr)
{	
	// Base case: if the string is empty, return zero.
	if (inptStr.empty())
		return 0;
	// Check uppercased first character of string with uppercased vowels (A, E, I, O, U)
	// return recursive function by adding 1 for vowels and recursive function with parameter of string starting with second character.
	if (toupper(inptStr[0]) == 'A' || toupper(inptStr[0]) == 'E' || toupper(inptStr[0]) == 'I' || toupper(inptStr[0]) == 'O' || toupper(inptStr[0]) == 'U')
		return 1 + countVowels(inptStr.substr(1));
	else
	// If no vowel found in the first character of string, return recursive function with string starting with second character.
		return countVowels(inptStr.substr(1));
}

// POST CONDITION: Returns user input of string.
string readString()
{
	string str;
	cout << "Enter the string to count the number of vowels in it: ";
	cin.ignore();      
	getline(cin, str); // Store line of user input to str
	return str;
}

int main()
{
	int command;
	string inptStr;
	do {
		display_menu();
		command = get_command();
		switch(command) {
			case 1:
				inptStr = readString();
				cout << "You entered string: " << inptStr << endl;
				break;
			case 2:
				cout << "Your entered string: " << inptStr << endl;
				cout << "Number of vowels:    " << countVowels(inptStr) << endl;
				break;
			case 3:
				break; // Nothing happens and finish do-while loop
			default:
				// Prompt error message if command is invalid
				cout << "Command invalid! Please try again" << endl;
				break;
		}
	} while(command != 3);
	return EXIT_SUCCESS;
}