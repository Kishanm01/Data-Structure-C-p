// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  3

// FILE: node1_New_Test.cpp

#include "node1_New.h"
#include <iostream> // Provides Input and Output Stream
#include <cstdlib>  // Provides NULL and size_t

using namespace std;

// PROTOTYPES for functions used by this test program:
// POSTCONDITION: The menu has been written to cout.
void display_menu()
{
	cout << endl;
	cout << "------------- MAIN MENU -------------------" << endl;
	cout << "1.  Test function std::size_list_length" << endl;
	cout << "2.  Test function void list_head_insert" << endl;
	cout << "3.  Test function void list_insert" << endl;
	cout << "4.  Test function node *list_search" << endl;
	cout << "5.  Test function const node *list_search" << endl;
	cout << "6.  Test function node *list_locate" << endl;
	cout << "7.  Test function const node *list_locate" << endl;
	cout << "8.  Test function void list_head_remove" << endl;
	cout << "9.  Test function void list_remove" << endl;
	cout << "10. Test function void list_clear" << endl;
	cout << "11. Test function void list_copy" << endl;
	cout << "12. Display List" << endl;
	cout << "13. Test function delete_reps" << endl;
	cout << "14. Test function sort_list" << endl;
	cout << "15. Test function split_list" << endl;
	cout << "16. Exit Program" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Enter option number: " << endl;
}

// POSTCONDITION: The user has been prompted for a integer value.
int get_command()
{
    int command;

    cout << ">";
    cin >> command;

    return command;
}

// POSTCONDITION:  The grade list passed has been sent to cout.
void display_list(const node* head_ptr)
{
	const node* cursor_ptr = head_ptr;
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty: [";
	}
	else
	{
		cout << "[";
		cout << cursor_ptr->data();
		cursor_ptr = cursor_ptr->link();
	}
	while(cursor_ptr != NULL)
	{
		cout << ", " << cursor_ptr->data();
		cursor_ptr = cursor_ptr->link();
	}
	cout << "]" << endl;
}

// The user has been prompted for grade value to be added to top of the List. Result is printed in cout.
void test_list_head_insert(node*& head_ptr)
{
	double grade;
	cout << "Enter the grade value to add to the top of the list: ";
	cin >> grade;
	list_head_insert(head_ptr, grade);
	cout << "Update grade list after insert: ";
	display_list(head_ptr);
}

// The user has been prompted for grade value to be added to end of the list. Result is printed in cout.
void test_list_insert(node*& head_ptr)
{
	double grade;
	node* prv_pointer = head_ptr;
	cout << "Enter the grade value to add to the end of the list: ";
	cin >> grade;
	while((*prv_pointer).link() != NULL)
	{
		prv_pointer = (*prv_pointer).link();
	}
	list_insert(prv_pointer, grade);
	cout << "Update grade list after insert: ";
	display_list(head_ptr);
}

// The user has been prompted to enter grade value to search in the list. Result is printed in cout.
void test_list_search(node*& head_ptr)
{
	double grade;
	node* located_node;
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty!" << endl;
		return;
	}
	cout << "Enter the grade value you want to search for (You will be able to modify returned grade value!): ";
	cin >> grade;
	located_node = list_search(head_ptr, grade);
	if (located_node == NULL)
		cout << "The grade value is not found in the list." << endl;
	else
		cout << "The grade value node is found in the list." << endl;
}

// The user has been prompted to enter grade value to search in the list. Result is printed in cout.
void test_const_list_search(const node* head_ptr)
{
	double grade;
	const node* located_node;
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty!" << endl;
		return;
	}
	cout << "Enter the grade value you want to search for (You would not able to modify returned grade value!): ";
	cin >> grade;
	list_search(head_ptr, grade);
	located_node = list_search(head_ptr, grade);
	if (located_node == NULL)
		cout << "The grade value is not found in the list." << endl;
	else
		cout << "The grade value node is found in the list." << endl;
}

// The user has been prompted to for a position in the given list that will return that
// specific node. If no node found, result will print in cout.
void test_list_locate(node*& head_ptr)
{
	size_t pos;
	double pos_grade;
	node* node_ptr;
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty!" << endl;
		return;
	}
	cout << "Enter the position to find the node (position > 0): ";
	cin >> pos;
	if (pos < 1 || pos > list_length(head_ptr))
	{
		cout << "Invalid position!" << endl;
		return;
	}
	node_ptr = list_locate(head_ptr, pos);
	pos_grade = node_ptr->data();
	if (node_ptr == NULL)
		cout << "There is no such a position in the list." << endl;
	else
		cout << "The grade found at this position: " << pos_grade << endl;
}

// The user has been prompted to for a position in the given list that will return that
// specific node. If no node found, result will print in cout.
void test_const_list_locate(const node* head_ptr)
{
	size_t pos;
	double pos_grade;
	const node* node_ptr;
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty!" << endl;
		return;
	}
	cout << "Enter the position to find the node (position > 0): ";
	cin >> pos;
	if (pos < 1 || pos > list_length(head_ptr))
	{
		cout << "Invalid position!" << endl;
		return;
	}
	node_ptr = list_locate(head_ptr, pos);
	pos_grade = node_ptr->data();
	if (node_ptr == NULL)
		cout << "There is no such a position in the list." << endl;
	else
		cout << "The grade found at this position: " << pos_grade << endl;
}

// The function will remove the first node of the list and print resulted list in cout.
void test_list_head_remove(node*& head_ptr)
{
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty!" << endl;
		return;
	}
	list_head_remove(head_ptr);
	cout << "The first grade value is removed." << endl;
	cout << "After head node removed: ";
	display_list(head_ptr);
}

// The user will be prompted to enter an position value that you want to remove from the list.
// Resulted list is printed in cout.
void test_list_remove(node*& head_ptr)
{
	size_t remove_pos;
	node* prv_node;
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty!" << endl;
		return;
	}
	cout << "Enter grade position in the list you want to remove from list (position > 0): ";
	cin >> remove_pos;
	if (remove_pos < 1 || remove_pos > list_length(head_ptr))
	{
		cout << "Invalid position!" << endl;
		return;
	}
	if (remove_pos == 1)
	{
		list_head_remove(head_ptr);
	}
	else {
		prv_node = list_locate(head_ptr, remove_pos - 1);
		list_remove(prv_node);
	}
	cout << "The list position " << remove_pos << " is removed from the list." << endl;
	cout << "After node is removed: ";
	display_list(head_ptr);
}

// The nodes are removed from the list.
void test_list_clear(node*& head_ptr)
{
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty!" << endl;
		return;
	}
	list_clear(head_ptr);
	cout << "The list is cleared." << endl;
	display_list(head_ptr);
}

// Given two header pointer of two list, the function copies from original list to new list.
void test_list_copy(node*& head_ptr, node*& copy_list)
{
	node* new_tail_ptr;
	if (head_ptr == NULL)
	{
		cout << "The grade list is empty!" << endl;
		return;
	}
	cout << "The list_copy function will copy the list to a new list." << endl;
	list_copy(head_ptr, copy_list, new_tail_ptr);
	
	// Display new list.
	cout << "Initial List: ";
	display_list(head_ptr);
	cout << "New List: ";
	display_list(copy_list);
}

// Given header pointer of list, all the duplicates value are removed and new list is returned.
// Both lists are printed to cout.
void test_delete_reps(const node* head_ptr, node*& non_dupl_list)
{
	cout << "Before removing repetitions: ";
	display_list(head_ptr);
	non_dupl_list = delete_reps(head_ptr);
	cout << "After removing repetitions: ";
	display_list(non_dupl_list);
}

// Given header pointer of list, the function prints sorted list from lowest grade value to highest.
void test_sort_list(node*& head_ptr)
{
	cout << "Before sorting list ascending order: ";
	display_list(head_ptr);
	sort_list(head_ptr);
	cout << "After sorting list ascending order: ";
	display_list(head_ptr);
}

// Given two header pointer of two lists and prompts user of split_value, the original list is trimmed and
// rest of nodes are added to List2.
void test_split_list(node*& head_ptr, node*& List2)
{
	double split_value;
	
	// Get input from user of split_value and call split_list(...) function
	cout << "Enter the grade value you want to split the list from: ";
	cin >> split_value;
	split_list(head_ptr, List2, split_value);
	
	// List2 will return null if no such split_value found in head_ptr.
	// If List2 is not null, display both lists.
	if (List2 != NULL)
	{
		cout << "Here are the List 1 and List 2 after spliting List 1 from grade value of " << split_value << endl;
		cout << "List 1 (head_ptr):";
		display_list(head_ptr);
		cout << "List 2:";
		display_list(List2);
	}
	else
	{
		// If no such value found
		display_list(head_ptr);
		test_split_list(head_ptr, List2);
	}
}

int main()
{
	int command;
	
	// Some of the List used in this test program
	node* head_ptr = NULL;       // Original Grade List
	node* copy_list = NULL;      // List after copying from original grade list
	node* non_dupl_list = NULL;  // List after removing duplicates grafe value
	node* List2 = NULL;          // List after spliting original grade list
	
	cout << "List Grades has been initialize and currently is empty." << endl;
	do {
		display_menu();
		command = get_command();
		
		switch(command) {
        case 1:
			cout << "Length of Grades list is: " << list_length(head_ptr) << endl;
            break;
        case 2:
            test_list_head_insert(head_ptr);
            break;
        case 3:
            test_list_insert(head_ptr);
            break;
        case 4:
            test_list_search(head_ptr);
            break;
        case 5:
            test_const_list_search(head_ptr);
            break;
        case 6:
            test_list_locate(head_ptr);
            break;
        case 7:
            test_const_list_locate(head_ptr);
            break;
        case 8:
            test_list_head_remove(head_ptr);
            break;
        case 9:
            test_list_remove(head_ptr);
            break;
        case 10:
            test_list_clear(head_ptr);            
            break;
        case 11:
            test_list_copy(head_ptr, copy_list);
            break;
		case 12:
			display_list(head_ptr);			
			break;
		case 13:
			test_delete_reps(head_ptr, non_dupl_list);
			break;
		case 14:
			test_sort_list(head_ptr);
			break;
		case 15:
			test_split_list(head_ptr, List2);
			break;
        case 16: // Do nothing..
            break;
        default:
            cout << "Invalid command." << endl;
            break;
        }
	} while (command != 16);
	
	return EXIT_SUCCESS;
}
