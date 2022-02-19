// Name:        Kishan Mistry
// Class:       CS 3305/Section 03clTabCtrl
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  6

// File testBST.cpp

#include <string>
#include "bst.h"

using namespace std;
int rnd() {
    return rand() % 100;
}

int main() {
	
	//==================== Test # 1 ==================
	cout << endl << "==================== Test # 1 ==================" << endl;
		
	//let's build simple BST of random integers
    binary_search_tree<int> intBST;
    for(int i = 0; i < 8; i++ ) {
        int x = rnd();
		cout << "Insert value:  " << x << endl;
		intBST.insert(x);
    }

	//let's print the tree
	cout << endl << intBST << endl << endl;
	
	//let's see the tree shape
    print(intBST.get_root(), 0);
	
	//let's check if tree is balanced or not
    cout << endl << "balanced? " << intBST.is_balanced() << endl;
    
	
	//================ Test # 2 ======================
	cout << endl << "==================== Test # 2 ==================" << endl;
	
    binary_search_tree<string> bst;
    cout << bst << endl;
    bst.insert("baker");
    cout << bst << endl;

    // making sure the output operator was working properly.
    bst.get_root()->set_left(new binary_tree_node<string>("able"));
    cout << bst << endl;
    bst.get_root()->set_right(new binary_tree_node<string>("charlie"));
    cout << bst << endl << endl;
    
    bst.insert("arthur");
	
	//let's see the tree shape
    print(bst.get_root(), 0);
    cout<<endl;
	
  	//let's check if tree is balanced or not
    cout << "balanced? " << bst.is_balanced() << endl;
	
	
	//================ Test # 3 ======================
	cout << endl << "==================== Test # 3 ==================" << endl;
	
    string data[] = {"able", "baker", "charlie", "dog", "easy", "fox", "george"};
    int size = 7;
    binary_search_tree<string> bst1;
    for (int i = 0; i < size; ++i) {
        bst1.insert(data[i]);
        cout << bst1 << endl;
    }
	
	//let's see the tree shape
	print(bst1.get_root(), 0);
	
  	//let's check if tree is balanced or not
    cout << endl << "balanced? " << bst1.is_balanced() << endl;

	
	//================ Test # 4 ======================
	cout << endl << "==================== Test # 4 ==================" << endl;
	
    int size2 = 7;
    string data2[] = {"dog", "baker", "able", "fox", "charlie",  "george", "easy"};
    binary_search_tree<string> bst2;
    for (int i = 0; i < size2; ++i) {
        bst2.insert(data2[i]);
        cout << bst2 << endl;
    }
	
    //let's see the tree shape
    print(bst2.get_root(), 0);
	
	//let's check if tree is balanced or not
    cout << endl << "balanced? " << bst2.is_balanced() << endl;
	
	//================ Test remove function on bst2 ======================

	cout << endl << "Test Remove Function" << endl << endl;
	
    cout << "remove 'able': " << bst2.remove("able") << endl;
    //let's see the tree shape
    print(bst2.get_root(), 0);
	cout << endl;

    cout << "remove 'baker': " << bst2.remove("baker") << endl;
	//let's see the tree shape
    print(bst2.get_root(), 0);
	cout << endl;

    cout << "remove 'dog': " << bst2.remove("dog") << endl;
	//let's see the tree shape
    print(bst2.get_root(), 0);
	cout << endl;
	
    cout << "remove 'foxx': " << bst2.remove("foxx") << endl;   //test invalid value
   	//let's see the tree shape
    print(bst2.get_root(), 0);
	cout << endl;
	}