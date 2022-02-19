// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  1 - Exercise 2

#ifndef DAILYTEMPS_HPP
#define DAILYTEMPS_HPP

#include <string> // Provides string

class DailyTemps
{
public:
    // CONSTRUCTOR
    DailyTemps();

    // MEMBER FUNCTIONS
    void setTemps(char day_char, double new_temp); // Change given day's char value and new temperature value.
	int Freezing() const; // Returns the number of days with temperature below freezing level ( < 32).
	std::string Warmest(); // Returns the first day from Monday with the Highest temperature value,
	void printTemps() const; // Prints the temperature for the week.
	
	// Setters Function
    void setMonTemp(double mon_temp)
    {
	this->mon_temp = mon_temp;
    }
    void setTueTemp(double tue_temp)
    {
	this->tue_temp = tue_temp;
    }
    void setWedTemp(double wed_temp)
    {
	this->wed_temp = wed_temp;
    }
    void setThuTemp(double thu_temp)
    {
	this->thu_temp = thu_temp;
    }
    void setFriTemp(double fri_temp)
    {
	this->fri_temp = fri_temp;
    }
	void setSatTemp(double sat_temp)
    {
	this->sat_temp = sat_temp;
    }
    void setSunTemp(double sun_temp)
    {
	this->sun_temp = sun_temp;
    }
    
	// Getters Functions
    double getMonTemp() const { return mon_temp; }
    double getTueTemp() const {	return tue_temp; }
    double getWedTemp() const {	return wed_temp; }
    double getThuTemp() const {	return thu_temp; }
    double getFriTemp() const { return fri_temp; }
	double getSatTemp() const {	return sat_temp; }
    double getSunTemp() const {	return sun_temp; }
	
private:
    double mon_temp = 0; // Monday temperature, default value 0.
    double tue_temp = 0; // Tuesday temperature, default value 0.
    double wed_temp = 0; // Wednesday temperature, default value 0.
    double thu_temp = 0; // Thursday temperature, default value 0.
    double fri_temp = 0; // Friday temperature, default value 0.
    double sat_temp = 0; // Saturday temperature, default value 0.
    double sun_temp = 0; // Sunday temperature, default value 0.
};

#endif // DAILYTEMPS_HPP
