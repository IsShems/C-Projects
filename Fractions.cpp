#include <iostream>    
#include "fr.h"
using namespace std;

int main()
{
    cout << "Enter numerator of first fraction: "; //vvod pervoy drobi
    double numer1;
    cin >> numer1;
    cout << "Enter denominator of first fraction: ";
    double denom1;
    cin >> denom1;

    auto* fr1 = new Fraction(numer1, denom1);
    fr1->print_fractions();

    cout << "\nEnter numerator of second fraction: "; //vvod vtoroy drobi
    double numer2;
    cin >> numer2;
    cout << "Enter denominator of second fraction: ";
    double denom2;
    cin >> denom2;

    auto* fr2 = new Fraction(numer2, denom2);
    fr2->print_fractions();
                                                                  //vivod rezultatov
    cout << "\nSum of fractions is " << fr1->fract + fr2->fract;
    cout << ",\nSubstraction of fractions is " << fr1->fract - fr2->fract;
    cout << ",\nMultiplication of fractions is " << fr1->fract * fr2->fract;
    cout << ",\nDivision of fractions is " << fr1->fract / fr2->fract;
    cout << endl;

    return 0;
}

