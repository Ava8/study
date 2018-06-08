//
//  complex.cpp
//  lab
//
//  Created by MacBook Air on 13.02.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include "complex.hpp"

using namespace std;

Complex::Complex()
{
    re = 0;
    im = 0;
}

Complex::Complex(double real, double imag)
{
    re = real;
    im = imag;
}

Complex Complex::operator+(const Complex& c)
{
    return Complex(re + c.re, im + c.im);
}

Complex Complex::operator-(const Complex& c)
{
    return Complex(re - c.re, im - c.im);
}

Complex Complex::operator*(const Complex& c)
{
    return Complex(re * c.re - im * c.im, im * c.re + re * c.im);
}

// вывод реальной и мнимой частей числа
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.re << "," << c.im << "i";
    return os;
}
