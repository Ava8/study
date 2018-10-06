//  practiceOOP
//
//  Created by MacBook Air on 23.03.2018.
//  Mamaeva Arina
//  IKBO-13-17

#include <iostream>
#include <cmath>
#include <tgmath.h>
using namespace std;

int main() {
    
    float a = 3.5, x = -0.7,y,t;
    cout << "a = " << a << endl;
    cout << "x = " << x << endl;
    
    y = sqrt(sin(a*x));
    cout << "y = " << y << endl;
    if (a < y) {
        t = tan(a*x)+cos(2*a*y);
    } else if (a == y) {
        t = (y/(a-x))+((a+x)/pow(y, 2));
    } else {
        t = y/(a-x);
    }
    
    cout << "t = " << t << endl;
    return 0;
}
