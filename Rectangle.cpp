// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  1 - Exercise 1

#include "Rectangle.hpp"

using namespace std;
namespace exercise_one{
	
	// Rectangle Constructor with default values.
	Rectangle::Rectangle(double this_width, double this_height)
	{
		width = this_width;
		height = this_height;
	}
	
	// Returns the area of the Rectangle object.
	double Rectangle::getArea() const
	{
		return (getWidth() * getHeight());
	}
	
	// Returns the perimeter of the Rectangle object.
	double Rectangle::getPerimeter() const
	{
		return ((2 * getWidth()) + (2 * getHeight())); 
	}
}
