// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  4

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void display_menu()
{
	cout << endl;
	cout << "-----MAIN MENU-----" << endl;
	cout << "1. Test function character-by-character palindrome" << endl;
	cout << "2. Test function word-by-word palindrome" << endl;
	cout << "3. Exit program" << endl;
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

void char_palindrome()
{
	queue<char> q;
	stack<char> s;
	char letter;
	queue<char>::size_type mismatches = 0; // Mismatches between queue and stack
	cout << "Enter a line and I will see if it's a palindrome:" << endl;
	while (true)
	{
		cin >> letter;
		if (cin.peek() == '\n')
			break;
		if (isalpha(letter))
		{
			q.push(toupper(letter));
			s.push(toupper(letter));
		}
	}
	while ((!q.empty( )) && (!s.empty( )))
	{
		if (q.front( ) != s.top( ))
			++mismatches;
		q.pop( );
		s.pop( );
	}
	if (mismatches == 0)
		cout << "That is a palindrome." << endl;
	else
		cout << "That is not a palindrome." << endl;
}

void word_palindrome()
{
	queue<string> q;
	stack<string> s;
	string strWord = "";
	queue<string>::size_type mismatches = 0; // Mismatches between queue and stack
	cout << "Enter a line and I will see if it's a palindrome:" << endl;
	while (true)
	{
		cin >> strWord;
		string alphaWord = "";
		for(int i = 0; i < strWord.size(); ++i)
			{
				strWord[i] = toupper(strWord[i]);
				if (isalpha(strWord[i]) || strWord[i] == '\'')
				{
					alphaWord += strWord[i];
				}
			}
		q.push(alphaWord);
		s.push(alphaWord);
		if (cin.peek() == '\n')
			break;
	}
	while ((!q.empty( )) && (!s.empty( )))
	{
		if (q.front( ) != s.top( ))
			++mismatches;
		q.pop( );
		s.pop( );
	}
	if (mismatches == 0)
		cout << "That is a palindrome." << endl;
	else
		cout << "That is not a palindrome." << endl;
}

int main()
{
	int command;
	
	do {
		display_menu();
		command = get_command();
		if (!cin) {
			cin.clear();
			break;
		}
		switch(command) {
        case 1:
			char_palindrome();
            break;
        case 2:
            word_palindrome();
            break;
        case 3:
            break;
		default:
			cout << "Invalid Command! Please enter correct command." << endl;
			break;
		}
	} while (command != 3);
	
	return EXIT_SUCCESS;
}