// Name:        Kishan MistryclTabCtrl
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  6

// File removeDuplicates.cpp

#include "bst.h"
#include <iostream> // Provides Input/Output Stream
#include <iomanip>  // Provides Input/Output Manipulation
#include <limits>   // Provides max() function
#include <string>   // Provides string

using namespace std;

static binary_search_tree<string> tree;

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
	cout << "---------------MAIN MENU---------------" << endl;
	cout << "1. Remove duplicates using Binary Tree"  << endl;
	cout << "2. Exit program"                         << endl;
	cout << "---------------------------------------" << endl;
}

// Parameter function used in Tree traversal in bintree.template
// printTree prints each element in the tree on one line
void printTree(string data)
{
	cout << data << " ";
}

// POST CONDITION: the function will read user input and insert into the tree and use inorder traversal function to display on console
void removeDuplicates()
{
	string token;
	string strLine = "";
	// Read user input until new line character
	cout << "Enter a text that will remove duplicates:" << endl;
	while (true)
	{
		cin >> token;
		strLine = strLine + token + " ";
		// Search if token is already in the tree, if not then insert into the tree
		if (tree.search(token) == NULL)
			tree.insert(token);
		// BASE CASE for breaking out of the while loop, if there is new line character next
		if (cin.peek() == '\n')
			break;
	}
	cout << endl << "Original text:" << endl;
	cout << strLine << endl << endl;
	// Display inorder travarsal of tree on one line using printTree function.
	cout << "Processed text:" << endl;
	inorder(printTree, tree.get_root());
}

int main()
{
	int command;
	do {
		tree.~binary_search_tree();
		display_menu();
		command = get_command();
		switch(command) {
			case 1:
				removeDuplicates();
				
				break;
			case 2:
				break; // Nothing happens and finish do-while loop
			default:
				// Prompt error message if command is invalid
				cout << "Command invalid! Please try again" << endl;
				break;
		}
	} while(command != 2);
	return EXIT_SUCCESS;
}