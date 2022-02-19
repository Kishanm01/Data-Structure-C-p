// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  8

#include <iostream>
#include <iomanip>  // Provides format function for output
#include <limits>
#include <cmath>    // Provides power function

/*
 * 	This program implement 4 Hash functions to store keys into a Table containing the key and number of probes.
 *  HF1 -> Division method with linear probing
 *  HF2 -> Division method with quadratic probing
 *  HF3 -> Double Hashing 
 */
 
using namespace std;

// Keys given by professor.
int keys[] = {1234, 8234, 7867, 1009, 5438, 4312, 3420, 9487, 5418, 5299,
			  5078, 8239, 1208, 5098, 5195, 5329, 4543, 3344, 7698, 5412,
			  5567, 5672, 7934, 1254, 6091, 8732, 3095, 1975, 3843, 5589,
			  5439, 8907, 4097, 3096, 4310, 5298, 9156, 3895, 6673, 7871,
			  5787, 9289, 4553, 7822, 8755, 3398, 6774, 8289, 7665, 5523};
					 
// Display menu
void display_menu() {
	cout << endl << "-----MAIN MENU-----" << endl;
	cout << "1 - Run HF1 (Division method with Linear Probing)" << endl;
	cout << "2 - Run HF2 (Division method with Quadratic Probing)" << endl;
	cout << "3 - Run HF3 (Division method with Double Hashing)" << endl;
	cout << "4 - Run HF4 (Student Designed HF)" << endl;
	cout << "5 - Exit Program" << endl;
	cout << "-------------------" << endl;
}

// POSTCONDITION: The user has been prompted for a integer value.
int get_command() {
	int command;
	cout << endl << "Enter Option Number: ";
	cin >> command;
	if (cin.fail()) {                                          // Check if user entered value other than int
		cin.clear();										   // Clear cin errors
		cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Move the cin cursor to the next line by ignoring the rest of input on the line
	}
	return command;
}

// Displays the hash table using given sample format.
// Pre condition: Table is declared and initialized to zeros.
template <size_t rows, size_t cols>
void printTable(string hFunc, int (&Table)[rows][cols]) {
	cout << endl << "Hash table resulted from " << hFunc << ":" << endl << endl;
	cout << setw(5) << "Index" << "   " << setw(4) << left << "Key" << "   " << setw(6) << "Probes" << endl;
	cout << "------------------------" << endl;
	// Loop for retrieving index, key and # of probes from the Table.
	for(int i = 0; i < rows; i++) {
	cout << " " << setw(2) << right << i << "     " << setw(4) << Table[i][0] << "    " << setw(2) << Table[i][1] << endl;
	}
	cout << "------------------------" << endl;
}

// Return the sum of all probes in the table.
// Pre condition: Table is declared and initialized to zeros.
template <size_t rows, size_t cols>
int sumProbes(int (&Table)[rows][cols]) {
	int numProbes = 0;
	// For loop to retrieve second column of the table containing # of probes and adding to numProbes.
	for(int i = 0; i < rows; i++) {
		numProbes += Table[i][1];
	}
	return numProbes;
}

// Hash Function 1: Returns valid index using linear probing.
// Pre Condtion: Table is declared and initialized to zeros.
template <size_t rows, size_t cols>
int HF1(int key, int &probe, int (&Table)[rows][cols], size_t tSize) {
	// The Division method
	int index = key % tSize;
	// Linear Probing: Search next index until blank space is found
	while(Table[index][0] != 0) {
		index++;
		// If index goes over 50 use (index % tSize) to start from 0 index. 
		if(index >= tSize)
			index %= tSize;
		// increment probe for each search
		probe++;
	}
	// Return the valid index
	return index;
}

// Testing first Hash Function.
void test_HF1() {
	// Set the Table size.
	const int tSize = 50;
	// Declare 2-d array Table with 50 rows and 2 column
	int Table[tSize][2] = { };
	// For loop for entering keys into the hash table.
	for(int i = 0; i < tSize; i++) {
		int probe = 0;
		int key = HF1(keys[i], probe, Table, tSize); // Pass key, intial probe (0), the hash Table and its size to HF1 function.
		// If the returned index is -1 than that means function could not found index.
		if (key != -1) {
			Table[key][0] = keys[i]; // Add the key into the returned index.
			Table[key][1] = probe;   // Add # of probes into corresponding row.
		}
	} 
	// Print the hash Table using given sample format.
	printTable("HF1", Table);
	// Display total number of probes used to initialize table with the keys.
	cout << endl << "Sum of probe values = " << sumProbes(Table) << " probes" << endl;
}

// Hash function 2: Returns valid index using quadratic probing
// Pre condition: Table is declared and initialized with zeros.
template <size_t rows, size_t cols>
int HF2(int key, int &probe, int (&Table)[rows][cols], size_t tSize) {
	// The Division method
	int index = key % tSize;
	// Quadratic Probing: Search for next index using (key + i * i) until blank space is found
	int i = 1;
	while(Table[index][0] != 0) {
		int increment = (pow(i,2));
		index = (index + increment) % tSize;    // If index goes over 50 use (index % tSize) to start from 0 index.
		// increment probe and i for each search
		probe++;
		i++;
	}
	// Return the valid index
	return index;
}

// Testing second Hash Function.
void test_HF2() {
	// Set the Table size.
	const int tSize = 50;
	// Declare 2-d array Table with 50 rows and 2 column
	int Table[tSize][2] = {};
	// For loop for entering keys into the hash table.
	for(int i = 0; i < tSize; i++) {
		int probe = 0;
		int key = HF2(keys[i], probe, Table, tSize); // Pass key, intial probe (0), the hash Table and its size to HF1 function.
		// If the returned index is -1 than that means function could not found index.
		if (key != -1) {
			Table[key][0] = keys[i]; // Add the key into the returned index.
			Table[key][1] = probe;   // Add # of probes into corresponding row.
		}
	}
	// Print the hash Table using given sample format.
	printTable("HF2", Table);
	// Display total number of probes used to initialize table with the keys.
	cout << endl << "Sum of probe values = " << sumProbes(Table) << " probes" << endl;
}

// Second Hashing fucntion for HF3
// H'(key) = 30 - key % 25
int doubleHF3(int key) {
	return (30 - key % 25);
}

// Hash Function 3: Returns valid index using Double Hashing.
// Pre Condtion: Table is declared and initialized to zeros.
template <size_t rows, size_t cols>
int HF3(int key, int &probe, int (&Table)[rows][cols], size_t tSize) {
	// The Division method
	int index = key % tSize;
	int j = 1;
	// The second hashing function
	int increment = j * doubleHF3(key);
	// Double hashing: Search next index by using another hash function.
	
	while(Table[index][0] != 0) {
		// Increment next index
		index = (index + increment) % 50;    // If index + increment goes over 50 use  ( % tSize) to start from 0 index.
		// increment probe and j value .for each search
		probe++;
		j++;
		// If the # of probes reaches more than 50 for any key than display a message and break out of the loop
		if(probe > 50)
		{
			cout << "Unable to hash key " << key << " to the Table." << endl;
			index = -1;
			break;
		}
	}
	// Return the valid index
	return index;
}

// Testing third Hash Function.
void test_HF3() {
	// Set the Table size.
	const int tSize = 50;
	// Declare 2-d array Table with 50 rows and 2 column
	int Table[tSize][2] = { };
	// For loop for entering keys into the hash table.
	for(int i = 0; i < tSize; i++) {
		int probe = 0;
		int key = HF3(keys[i], probe, Table, tSize); // Pass key, intial probe (0), the hash Table and its size to HF1 function.
		// If the returned index is -1 than that means function could not found index.
		if (key != -1) {
			Table[key][0] = keys[i]; // Add the key into the returned index.
			Table[key][1] = probe;   // Add # of probes into corresponding row.
		}
	}
	// Print the hash Table using given sample format.
	printTable("HF3", Table);
	// Display total number of probes used to initialize table with the keys.
	cout << endl << "Sum of probe values = " << sumProbes(Table) << " probes" << endl;
}

// Second Hashing fucntion for HF4
// H'(key) = 50 - key % 29
int doubleHF4(int key) {
	// Hash function that take remainder of key divded by a prime number 29.
	// A prime number is a rare number that gives unique number when being divded and getting the remainder.
	return (50 - key % 29);
}

// Hash Function 4: Returns valid index using self-made double hashing method.
// Pre Condtion: Table is declared and initialized to zeros.
template <size_t rows, size_t cols>
int HF4(int key, int &probe, int (&Table)[rows][cols], size_t tSize) {
	int j = 1;
	// The Division method
	int index = key % tSize;
	// The second hashing function call
	int HF2 = j * doubleHF4(key);
	// Double hashing: Search next index by using another hash function.
	while(Table[index][0] != 0) {
		/*
		 *  Incremental step is same as the one from the HF3 double hashing method.
		 * 	Increment index by: (key % 50) + j * HF2; where, HF2 = 50 - key % 29; for j = 1, 2, 3,...
		 */ 
		// Increment next index using: (key % 50) + j * HF2
		index = index + ((key % 50) + HF2);
		// If index goes over 50 use (index % tSize) to start from 0 index.
		if(index >= tSize)
			index %= tSize;
		// increment probe for each search
		probe++;
		// If the # of probes reaches more than 50 for any key than display a message and break out of the loop
		if(probe > 50)
		{
			cout << "Unable to hash key " << key << " to the Table." << endl;
			index = -1;
			break;
		}
	}
	// Return the valid index
	return index;
}

// Testing fourth Hash Function.
void test_HF4() {
	// Set the Table size.
	const int tSize = 50;
	// Declare 2-d array Table with 50 rows and 2 column
	int Table[tSize][2] = { };
	// For loop for entering keys into the hash table.
	for(int i = 0; i < tSize; i++) {
		int probe = 0;
		int key = HF4(keys[i], probe, Table, tSize); // Pass key, intial probe (0), the hash Table and its size to HF1 function.
		// If the returned index is -1 than that means function could not found index.
		if (key != -1) {
			Table[key][0] = keys[i]; // Add the key into the returned index.
			Table[key][1] = probe;   // Add # of probes into corresponding row.
		}
	}
	// Print the hash Table using given sample format.
	printTable("HF4", Table);
	// Display total number of probes used to initialize table with the keys.
	cout << endl << "Sum of probe values = " << sumProbes(Table) << " probes" << endl;
}

// Main Function
int main() {
	int command;
	
	// do-while loop: user's choice of when to exit the program by entering appropriate command.
	do {
		
		// Displays the menu with commands
		display_menu();
		// Get command from the user
		command = get_command();
		
		// Switch case statements based on user's command value
		switch(command) {
			case 1:
				test_HF1();		// Test first Hash function		
				break;
			case 2:
				test_HF2();		// Test second Hash function		
				break;
			case 3:
				test_HF3();		// Test third Hash function		
				break;
			case 4:
				test_HF4();		// Test fourth (self-made) Hash function		
				break;
			case 5: // Do noting...
				break;
		}
	} while(command != 5);
	
	return EXIT_SUCCESS;
}