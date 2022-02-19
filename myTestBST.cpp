// Name:        Kishan MistryclTabCtrl
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  6

// File myTestBST.cpp

#include "bst.h"
#include <string> // Provide string

using namespace std;
// Hard-coded words in alphabetical order.
static string keyWords[] = {
	"After", "Also" , "any", "back", "because", "come", "day"  , "even" ,
	"first", "give" , "how", "its" , "look"   , "most", "new"  , "now"  ,
	"only" , "other", "our", "over", "than"   , "then", "these", "think",
	"two"  , "us"   , "use", "want", "way"    , "well", "work"
	};

// Hard-coded int values to validate code
static int keyValues[] = { 3, 5, 2, 7, 1, 4, 6 };

// Static variable of Binary Search Tree object - tree.
static binary_search_tree<string> tree; // Change template 'string' to 'int' for testing keyValues.

// PRE CONDITION: array of item in sorted order with given min and max values of array.
// POST CONDITION: Recursive call to the function in order to fill BST tree with the item
template <class Item>
void buildTree(Item arr[], int min, int max) {
	int mid = (min + max) / 2;     // Calculation of mid value
	// BASE CALL
	if(min > max)
		return;
	tree.insert(arr[mid]);         // Insert the mid value as the root or sub-root of tree.
	buildTree(arr, min, mid - 1);  // Recursive call with sub array of the first half.
	buildTree(arr, mid + 1, max);  // Recursive call with sub array of the end half.
}

int main() {
	// Building and displaying BST tree.
	cout << "Display Binary Tree..." << endl;
	buildTree<string>(keyWords, 0, sizeof(keyWords)/sizeof(keyWords[0]));
	print(tree.get_root(), 0);
	// Printing the tree depth
	cout << "\nTree Depth: " << tree.is_balanced() << endl;
	
	cout << endl << "=======================" << endl;
	
	cout << endl << "Removed root node..." << endl;
	// Removed the root of the BST tree.
	tree.remove(tree.get_root()->data());
	// Displaying BST tree.
	print(tree.get_root(), 0);
	// Printing the tree depth
	cout << "Tree Depth: " << tree.is_balanced() << endl;
}