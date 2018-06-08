//
//  complex.hpp
//  lab
//
//  Created by MacBook Air on 13.02.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>

using namespace std;

class Complex
{
public:
    
    double re, im;
    
    Complex();
    Complex(double real, double imaginary);
    
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    
    
    //перегрузка операции вывода
    friend ostream & operator<<(ostream &os, const Complex &c);
};

