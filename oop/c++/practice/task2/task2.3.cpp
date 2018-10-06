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
    
    float a = 4.6, b = 1.5,y,t;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    y = a + log(pow(b, 2));
    cout << "y = " << y << endl;
    if (y < b) {
        t = pow(sin(y), 2)+1/(tan(a-b));
    } else if (y == b) {
        t = (2*y+sqrt(pow(y, 2)-a))/(2*b-sqrt(pow(a, 2)-y));
    } else {
        t = cbrt(y*sin(a))+1/(sqrt(y*cos(b)));
    }
    
    cout << "t = " << t << endl;
    return 0;
}
