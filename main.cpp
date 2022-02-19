// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  7

/**
 * Insert a few elements into a heap and the remove them
 * one by one and see if we get them in the right.
 */

#include "heap.h"
#include <iostream>
#include <ctime>
#include <ctype.h>
#include <string>

using namespace std;

void inTest() {
	
    cout << endl << "=====  int Test ========" << endl;

    heap<int> hp;
    hp.insert(11);
    hp.insert(22);
    hp.insert(33);
    hp.insert(44);
    hp.insert(55);
	
	cout << endl;
    hp.check_heap();  //check if heap is correct
	cout << endl;
 
    int x = hp.remove();
    cout << "removed " << x << endl;
    x = hp.remove();
    cout << "removed " << x << endl;
    x = hp.remove();
    cout << "removed " << x << endl;
    x = hp.remove();
    cout << "removed " << x << endl;
    x = hp.remove();
    cout << "removed " << x << endl;
	
    cout << endl;
    cout << "empty? " << hp.is_empty() << endl;  //check if heep is empty
	cout << endl;
}

void charTest() {
	
	cout << endl << "=====  char Test  ========" << endl << endl;

    heap<char> hp2;
	
	char ch;
	
    for(int i = 0; i < 8; i++ ) {
        cout << "Enter a character: ";
		cin >> ch;
		hp2.insert(ch);
    }
	
	cout << endl;
    hp2.check_heap();  //check if heap is correct
	cout << endl;
	
	cout << endl;
	
    while(!hp2.is_empty()) {
        char ch = hp2.remove();
		cout << "removed value: " << ch << endl;
	}
}

int main() {
	
    inTest();
    charTest();
}