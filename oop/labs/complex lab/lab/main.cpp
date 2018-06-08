//
//  main.cpp
//  lab
//
//  Created by MacBook Air on 13.02.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include "complex.hpp"
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
    
    double d1, d2, d3, d4;
    cin >> d1;
    cin >> d2;
    cin >> d3;
    cin >> d4;

    Complex c1(d1,d2), c2(d3,d4);


    char operation;
    cout << "Enter following operation: '+', '*', '-'\n";
    cin >> operation;
    switch (operation) {
        case '+':
            cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
            break;
        case '*':
            cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
            break;
        case '-':
            cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
            break;
        default:
            cout << "Operation input error\n";
            break;
    }
    
//    Complex *p;
//    int i, n, nmax;
//    double max;
//    FILE *f;
//    f=fopen ( "complex.txt", ios_base::in);
//    fread (&n, sizeof (int), 1, f );
//    p=new Complex [ n ];
//    fread ( p, sizeof ( Complex ), n, f );
//    //Поиск комплексного числа с максимальным модулем
//    max = sqrt(p[0].re*p[0].re+p[0].im*p[0].im);
//    for ( i =1,nmax=0; i<n; i++)
//        if (sqrt ( p[i].re*p[i].re+p[i].im*p[i].im)>max)
//        {
//            max=sqrt(p[i].re*p[i].re+p [i].im*p[i].im);
//            nmax= i;
//        }
//    cout<<" max = "<<max<<" \t nmax = "<<nmax<<endl;
//    fclose ( f );
//    return 0;
    
    
//    Complex c1(1.0, 2.0), c2(6.0, 4.0);
//    cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
//    cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
//    cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
//    cout << endl << endl;
}
