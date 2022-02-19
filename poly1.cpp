// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  2

#include <climits>
#include <cmath>
#include "poly1.h"

polynomial::polynomial()
{
	coef = new double[1];
	coef[0] = 0.00;
	current_array_size = 1;
}

polynomial::polynomial(double a0)
{
	coef = new double[1];
	coef[0] = a0;
	current_array_size = 1;
}

polynomial::polynomial(const polynomial& source)
{
	coef = new double[source.current_array_size];
	current_array_size = source.current_array_size;
	std::copy(source.coef, source.coef + degree() + 1, coef);
}

polynomial::~polynomial()
{
	delete [] coef;
}

void polynomial::reserve(size_t number)
{
	double *larger_poly;
	
	if (number == current_array_size)
		return;
	if (number < degree())
		number = degree();
	
	larger_poly = new double[number];
	std::copy(coef, coef + degree() + 1, larger_poly);
	delete [] coef;
	coef = larger_poly;
	current_array_size = number;
}

polynomial& polynomial::operator=(const polynomial& source)
{
	double *new_coef;
	
	if (this == &source)
		return *this;
	
	if (current_array_size != source.current_array_size)
	{
		new_coef = new double[source.current_array_size];
		delete [] coef;
		coef = new_coef;
		current_array_size = source.current_array_size;
	}
	
	std::copy(source.coef, source.coef + degree() + 1, coef);
	return *this;
}

void polynomial::add_to_coef(double amount, unsigned int k)
{
	if (k > degree())
		reserve(k + 1);
	coef[k] += amount;
}

void polynomial::assign_coef(double coefficient, unsigned int k)
{
	if (k > degree())
		reserve(k + 1);
	coef[k] = coefficient;
}

void polynomial::clear()
{	
	for(int i = 0; i < current_array_size; i++)
	{
		coef[i] = 0.00;
	}
}

double polynomial::coefficient(unsigned int k) const
{
	return coef[k];
}

unsigned int polynomial::degree() const
{
	int i = current_array_size - 1; // Highest Term including zero in the polynomial.
	
	while(i >= 0 && coef[i] == 0.00)
	{
		i--;
	}
	if (i == -1)
		return 0;
	else
		return i;
}

unsigned int polynomial::next_term(unsigned int k) const
{
	for(int i = k + 1; i <= degree(); i++)
	{
		if (coef[i] != 0.00)
			return i;
	}
	return UINT_MAX;
}

double polynomial::eval(double x) const
{
	double total = 0;
	
	for (int i = 0; i < current_array_size; i++)
	{
		total += (coef[i] * pow(x, i));
	}
	return total;
}

polynomial operator+(const polynomial& p1, const polynomial& p2)
{
	int highest_degree;
	if (p1.degree() < p2.degree())
		highest_degree = p2.degree();
	else
		highest_degree = p1.degree();
	
	polynomial new_poly;
	new_poly.reserve(highest_degree);
	for(int i = 0; i <= highest_degree; i++)
	{
		//new_poly[i] = (p1.coefficient(i) + p2.coefficient(i));
		new_poly.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
	}
	
	return new_poly;
}
polynomial operator-(const polynomial& p1, const polynomial& p2)
{
	int highest_degree;
	if (p1.degree() < p2.degree())
		highest_degree = p2.degree();
	else
		highest_degree = p1.degree();
	
	polynomial new_poly;
	new_poly.reserve(highest_degree);
	for(int i = 0; i <= highest_degree; i++)
	{
		//new_poly[i] = (p1.coefficient(i) + p2.coefficient(i));
		new_poly.assign_coef(p1.coefficient(i) - p2.coefficient(i), i);
	}
	
	return new_poly;
}
