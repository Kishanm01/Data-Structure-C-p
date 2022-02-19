// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  1 - Exercise 1

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <cstring> // Provides string
#include <iostream> // Provides Input/Output
using namespace std;
namespace exercise_one
{
class Rectangle
{
public:
	// CONSTRUCTOR
    Rectangle(double initial_width = 10.00, double initial_height = 10.00); // Constructor with default values

	// CONSTANT MEMBER FUNCTION
	double getArea() const; // Returns the Area of the Rectangle object.
	double getPerimeter() const; // Returns the Perimeter of the Rectangle object.
	// Prints the Rectangle object with specified width and height.
	void printRectangle(string objectName) const { cout << "\nRectangle " << objectName << " is " << getWidth() << " units wide and " << getHeight() << " units high.\n" << endl; }
	
	// GETTERS FUNCTION
    double getHeight() const { return height; } // Returns the height
    double getWidth() const { return width; } // Returns the width
private:
    double width;
    double height;
};

}

#endif // RECTANGLE_HPP
