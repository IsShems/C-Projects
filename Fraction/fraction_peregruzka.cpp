#include <iostream>
#include "fr.h"
using namespace std;

Fraction::Fraction(double numerator, double denaminator) { //konstruktor ne previshaet 3 znacheniya
	this->numerator = numerator;
	this->denaminator = denaminator;
	this->fract = numerator / denaminator;
}

double Fraction::operator + (double other) //peregruzki operatorov
{
	return this->fract + other;
}

double Fraction::operator - (double other)
{
	return this->fract - other;
}

double Fraction::operator * (double other)
{
	return this->fract * other;
}

double Fraction::operator / (double other)
{
	return this->fract / other;
}

