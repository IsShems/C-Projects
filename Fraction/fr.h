#include <iostream>
using namespace std;

class Fraction {
public:

	double numerator{};
	double denaminator{};
	double fract{};

	Fraction(double numerator, double denaminator);

	double operator+(double other);

	double operator-(double other);

	double operator*(double other);

	double operator/(double other);


	void print_fractions() {
		cout << "\n\nfraction is " << fract << endl;

	}

};
