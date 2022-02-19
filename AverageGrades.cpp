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
	cout << "--------MAIN MENU--------" << endl;
	cout << "1. Read class size"        << endl;
	cout << "2. Read class grades"      << endl;
	cout << "3. Compute class average"  << endl;
	cout << "4. Exit program"           << endl;
	cout << "-------------------------" << endl;
}

// PRE CONDITION: gradeList and classSize are initialized and class size >= 0
// POST CONDITION: Recursively find average of given array and array size - classSize
template <class Item>
Item findAverage(Item gradeList[], int classSize)
{
	double sum, avg;
	
	// Check for empty array.
	if (classSize == 0)
		return 0;
		
	// BASE CASE
	if (classSize == 1)
		sum = gradeList[classSize - 1];
	else
		sum = gradeList[classSize - 1] + ((classSize - 1) * findAverage(gradeList, classSize - 1));
		
	// Compute avg by dividing sum of grade and class size
	avg = sum / classSize;
	
	return avg; // return computed average
}

// PRE CONDITION: gradeList and classSize are initialized and class size >= 0
// POST CONDITION: Read user input grade list of given class size
template <class Item>
void readGrades(Item gradeList[],const int classSize)
{
	cout << "Enter the grades of " << classSize << " students between 0 and 100 (separated by space ' '): ";
	int i = 0;
	
	// Loop through class size and add it to grade list
	while (i < classSize)
	{
		cin >> gradeList[i];
		i++;
	}
	cout << endl;
}

// PRE CONDITION: gradeList and classSize are initialized and class size >= 0
// POST CONDITION: Displays class size, grade list and the computed grade average
template <class Item>
void displayComputeAvg(Item gradeList[], const int classSize)
{
	// Display class size
	cout << "You entered class size: " << classSize << endl;
	// Loop through grade list and display
	cout << "You entered grades:     ";
	for(int i = 0; i < classSize; i++)
	{
		cout << setprecision(2) << gradeList[i] << " ";
	}
	// Compute average using recursive function display average value precise of 2 decimal places
	cout << "\nClass average:          " << setprecision(2) << findAverage(gradeList, classSize) << endl;
}

int main()
{
	int command;
	
	// Data type defining option: Integer (int) or Double/float
	typedef int grade_type;
	
	// Declare class size and classGrades array of given class size
	int classSize = 0;
	grade_type classGrades[classSize];
	
	// Set double value precision to fixed value
	cout << fixed << showpoint;
	
	do {
		display_menu();
		command = get_command();
		switch(command) {
			case 1:
				cout << "Enter the number of students: ";
				cin >> classSize;
				break;
			case 2:
				readGrades(classGrades, classSize);
				break;
			case 3:
				displayComputeAvg(classGrades, classSize);
				break;
			case 4:
				break; // Nothing happens and finish do-while loop
			default:
				// Prompt error message if command is invalid
				cout << "Command invalid! Please try again" << endl;
				break;
		}
	} while(command != 4);
	return EXIT_SUCCESS;
}