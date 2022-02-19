// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  7

#include <iostream>
#include <limits>
#include <string>
#include "PQ_Heap.h"

using namespace std;

// Display menu
void display_menu() {
	cout << endl << "-----MAIN MENU-----" << endl;
	cout << "0. Enter Queue Type (Integer or string)" << endl;
	cout << "1. Enqueue Element" << endl;
	cout << "2. Dequeue Element" << endl;
	cout << "3. Check is_Full" << endl;
	cout << "4. Check is_Empty" << endl;
	cout << "5. Print Queue Size" << endl;
	cout << "6. Display Front Element" << endl;
	cout << "7. Print Queue Elements" << endl;
	cout << "8. Exit Program" << endl;
	cout << "-------------------" << endl;
}

bool check_cin() {
	if (cin.fail())                                            // Check if user entered value other than int
	{
		cin.clear();										   // Clear cin errors
		cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Move the cin cursor to the next line by ignoring the rest of input on the line
	}
}

// POSTCONDITION: The user has been prompted for a integer value.
int get_command() {
	int command;
	
	cout << endl << "Enter Option Number: ";
	cin >> command;
	
	check_cin();
	return command;
}

int main() {
	
	int command;
	
	bool flag = true;  // Flag until the user chooses Option 0 to set data type for queue
	bool intHeap;      // bool for assigning current queue object (int or string)
	
	// Two PQ heaps objects of int and string data types
	priority_queue_heap<int> int_pqHeap;
	priority_queue_heap<string> str_pqHeap;
	
	do {
		display_menu();
		command = get_command();
		if (command == 8)
			break;
		else if (flag && command != 0)
			cout << "Please select option 0 to unlock other options." << endl;
		else {
			switch(command) {
				case 0: {
					string heapType;
					cout << "Enter the queue type (int or string): ";
					cin >> heapType;
					if(heapType == "int")
						intHeap = true;
					else if(heapType == "string")
						intHeap = false;
					else
					{
						cout << "Invalid queue type entered!" << endl;
						break;
					}
					cout << "Heap type has chosen to be: " << heapType << endl;
					flag = false;
					break;
				}
				case 1: {
					// Inserts element into the priority queue
					if(intHeap)
					{
						// Checks for full heap
						if(int_pqHeap.is_full()) {
							cout << "The queue is full! Cannot add more elements." << endl;
							break;
						}
						
						// Retrieve int value from user
						cout << "Enter int value to be added to priority queue heap: ";
						int value;
						cin >> value;
						check_cin();
						int_pqHeap.enqueue(value);
						cout << "Value added: " << value;
					}
					else {
						// Checks for full heap
						if(str_pqHeap.is_full()) {
							cout << "The queue is full! Cannot add more elements." << endl;
							break;
						}
						
						// Retrieve int value from user
						cout << "Enter string value to be added to priority queue heap: ";
						string value;
						getline(cin, value);
						check_cin();
						str_pqHeap.enqueue(value);
						cout << "Value added: " << value;
					}
					break;
				}
				case 2: {
					// Removes the largest value from this priority queue
					if(intHeap)
					{
						// Checks for empty heap
						if(int_pqHeap.is_empty()) {
							cout << "The queue is empty! Cannot remove elements from an empty queue." << endl;
							break;
						}
						int value;
						value = int_pqHeap.dequeue();
						cout << endl << "Value removed: " << value;
					}
					else {
						// Checks for empty heap
						if(str_pqHeap.is_empty()) {
							cout << "The queue is empty! Cannot remove elements from an empty queue." << endl;
							break;
						}
						string value;
						value = str_pqHeap.dequeue();
						cout << endl << "Value removed: " << value;
					}
					break;
				}
				case 3: {
					if(intHeap)	{
						// Checks for full heap
						if(int_pqHeap.is_full())
							cout << "Int priority queue heap is full!" << endl;
						else
							cout << "Int priority queue heap is not full!" << endl;
					}
					else {
						// Checks for full heap
						if(str_pqHeap.is_full())
							cout << "String priority queue heap is full!" << endl;
						else
							cout << "String priority queue heap is not full!" << endl;
					}
					break;
				}
				case 4: {
					if(intHeap)
					{
						// Checks for empty heap
						if(int_pqHeap.is_empty())
							cout << "Int priority queue heap is empty!" << endl;
						else
							cout << "Int priority queue heap is not empty!" << endl;
					}
					else {
						// Checks for empty heap
						if(str_pqHeap.is_empty())
							cout << "String priority queue heap is empty!" << endl;
						else
							cout << "String priority queue heap is not empty!" << endl;
					}
					break;
				}
				case 5:{
					// Displays queue size
					int value;
					if(intHeap)
					{
						// Checks for empty heap
						if(int_pqHeap.is_empty())
							cout << "The queue is empty!" << endl;
						value = int_pqHeap.size();
						cout << "Int priority queue heap size: " << value;
					}
					else {
						// Checks for empty heap
						if(str_pqHeap.is_empty())
							cout << "The queue is empty!" << endl;
						value = str_pqHeap.size();
						cout << "String priority queue heap size: " << value;
					}
					break;
				}
				case 6:{
					// Retrieves front value in the queue heap.
					if(intHeap)
					{
						// Checks for empty heap
						if(int_pqHeap.is_empty()) {
							cout << "The queue is empty! Cannot retrieve element from an empty queue." << endl;
							break;
						}
						int value;
						value = int_pqHeap.front();
						cout << endl << "Front value: " << value;
					}
					else {
						// Checks for empty heap
						if(str_pqHeap.is_empty()) {
							cout << "The queue is empty! Cannot retrieve element from an empty queue." << endl;
							break;
						}
						string value;
						value = str_pqHeap.front();
						cout << endl << "Front value: " << value;
					}
					break;
				}
				case 7:{
					// Displays all the parent elements and its children elements.
					if(intHeap)
					{
						// Checks for empty heap
						if(int_pqHeap.is_empty()) {
							cout << "The queue is empty! Cannot retrieve element from an empty queue." << endl;
							break;
						}
						cout << "Printing queue elements:" << endl;
						int_pqHeap.display_heap();
					}
					else {
						// Checks for empty heap
						if(int_pqHeap.is_empty()) {
							cout << "The queue is empty! Cannot retrieve element from an empty queue." << endl;
							break;
						}
						cout << "Printing queue elements:" << endl;
						str_pqHeap.display_heap();
					}
					break;
				}
				case 8: // DO nothing...
					break;
				default:
					cout << "Command invalid! Please try again." << endl;
					break;
			}
		}
	} while (command != 8);
	
	return EXIT_SUCCESS;
}