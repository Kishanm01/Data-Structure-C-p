// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  1 - Exercise 1

#include "Rectangle.hpp" // Provides the definition of Rectangle.hpp file
#include <iostream> // Provides cout and cin
#include <iomanip> // Provides input/output format functions.
using namespace std;
using exercise_one::Rectangle;

int main()
{
	const int HEADING_WIDTH = 10;
	const int VALUE_WIDTH = 10;
	const int DECIMAL_VALUE = 2;
	
	cout.setf(ios::fixed, ios::floatfield); // Set output decimal place to fixed value.
	cout.precision(DECIMAL_VALUE); // Set decimal value to decimal_value.
	
	double set_width;
	double set_height;
	
	cout << "Enter Width and Height of the rectangle (Width Height): ";
	cin >> set_width >> set_height; // Initialize user given value to set_width and set_height
	
	Rectangle herRectangle(set_width, set_height); // Declare and Initialize herRectangle with given values.
	Rectangle myRectangle; // Declare and Initialize myRectangle with default values.
	
	// Output format
	cout << "myRectangle:\n===========" << endl;
	cout << setw(HEADING_WIDTH) << left << "Width:" << "  " << setw(VALUE_WIDTH) << right << myRectangle.getWidth() << endl;
	cout << setw(HEADING_WIDTH) << left << "Height:" << "  " << setw(VALUE_WIDTH) << right << myRectangle.getHeight() << endl;
	cout << setw(HEADING_WIDTH) << left << "Area:" << "  " << setw(VALUE_WIDTH) << right << myRectangle.getArea() << endl;
	cout << setw(HEADING_WIDTH) << left << "Perimeter:" << "  " << setw(VALUE_WIDTH) << right << myRectangle.getPerimeter() << endl;
	
	myRectangle.printRectangle("myRectangle"); // Prints Rectangle object's name and its values.
	
	cout << "herRectangle:\n==========" << endl;
	cout << setw(HEADING_WIDTH) << left << "Width:" << "  " << setw(VALUE_WIDTH) << right << herRectangle.getWidth() << endl;
	cout << setw(HEADING_WIDTH) << left << "Height:" << "  " << setw(VALUE_WIDTH) << right << herRectangle.getHeight() << endl;
	cout << setw(HEADING_WIDTH) << left << "Area:" << "  " << setw(VALUE_WIDTH) << right << herRectangle.getArea() << endl;
	cout << setw(HEADING_WIDTH) << left << "Perimeter:" << "  " << setw(VALUE_WIDTH) << right << herRectangle.getPerimeter() << endl;
	
	herRectangle.printRectangle("herRectangle"); // Prints Rectangle object's name and its values.
}
