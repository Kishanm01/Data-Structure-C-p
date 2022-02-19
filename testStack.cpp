// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  4

#include <stack>
#include <iostream>
#include <iomanip>

using namespace std;

void display_menu()
{
	cout << endl;
	cout << "-----MAIN MENU-----" << endl;
	cout << "1. Test function topToBotoom with integer stack" << endl;
	cout << "2. Test function bottomToTop with double stack" << endl;
	cout << "3. Test function flipStack with string stack" << endl;
	cout << "4. Test function searchStack with integer stack" << endl;
	cout << "5. Exit program" << endl;
	cout << endl;
}

// POSTCONDITION: The user has been prompted for a integer value.
int get_command()
{
    int command;

    cout << "Enter option number: ";
    cin >> command;

    return command;
}

template <class Item>
void fillStack(stack<Item>& item_stack)
{
	cout << "Enter values to be added to the stack (-1 to finish):" << endl;
	Item content;
	cin >> content;
	while(content != -1)
	{
		item_stack.push(content);
		cin >> content;
	}
}

void fillStack(stack<string>& item_stack)
{
	cout << "Enter values to be added to the stack (Enter after you are done):" << endl;
	string content;
	cin >> content;
	while(true)
	{
		item_stack.push(content);
		if (cin.peek() == '\n')
			break;
		cin >> content;
	}
}

template <class Item>
void displayStack(stack<Item> item_stack)
{
	string result_str = "";
	while(!item_stack.empty())
	{
		result_str += to_string(item_stack.top()) + "   ";
		item_stack.pop();
	}
	cout << result_str << endl;
}

void displayStack(stack<string> item_stack)
{
	string result_str = "";
	while(!item_stack.empty())
	{
		result_str += item_stack.top() + "   ";
		item_stack.pop();
	}
	cout << result_str << endl;
}

void topToBottom(stack<int> int_stack)
{
	cout << left << setw(26) << "Stack Content Top-Bottom: ";
	displayStack(int_stack);
}

void bottomToTop(stack<double> double_stack)
{
	stack<double> reverse_stack;
	while(!double_stack.empty())
	{
		reverse_stack.push(double_stack.top());
		double_stack.pop();
	}
	cout << left << setw(24) << "Reversed stack content: ";
	displayStack(reverse_stack);
}

stack<string> flipStack(stack<string>& str_stack)
{
	stack<string> tempStack;
	while(!str_stack.empty())
	{
		tempStack.push(str_stack.top());
		str_stack.pop();
	}
	str_stack = tempStack;
	return str_stack;
}

bool searchStack(stack<int> int_stack, int target_value)
{
	while(!int_stack.empty())
	{
		if(int_stack.top() == target_value)
			return true;
		int_stack.pop();
	}
	return false;
}

void test_topToBottom()
{
	stack<int> int_stack;
	fillStack<int>(int_stack);
	cout << left << setw(26) << "Stack Content: ";
	displayStack(int_stack);
	topToBottom(int_stack);
}

void test_bottomToTop()
{
	stack<double> double_stack;
	fillStack<double>(double_stack);
	cout << left << setw(24) << "Stack Content: ";
	displayStack(double_stack);
	bottomToTop(double_stack);
}

void test_flipStack()
{
	stack<string> str_stack;
	fillStack(str_stack);
	cout << "Stack Content: ";
	displayStack(str_stack);
	cout << "Flipped Stack: ";
	displayStack(flipStack(str_stack));
}

void test_searchStack()
{
	stack<int> int_Stack;
	int target_value;
	fillStack(int_Stack);
	cout << left << setw(24) << "Stack Content: " << "\t";
	displayStack(int_Stack);
	cout << left << setw(24) << "Target Value: " << "\t";
	cin >> target_value;
	bool has_value = searchStack(int_Stack, target_value);
	if(has_value)
		cout << left << setw(24) << "Stack has Target Value?:" << "\t" << "true" << endl;
	else
		cout << left << setw(24) << "Stack has Target Value?:" << "\t"  << "false" << endl;
}

int main()
{
	int command;
	
	do {
		display_menu();
		command = get_command();
		
		switch(command) {
        case 1:
		{
			test_topToBottom();
            break;
		}
        case 2:
            test_bottomToTop();
            break;
        case 3:
            test_flipStack();
            break;
        case 4:
            test_searchStack();
            break;
        case 5:
            break;
		default:
			cout << "Invalid Command! Please enter correct command." << endl;
			break;
		}
	} while (command != 5);
	
	return EXIT_SUCCESS;
}