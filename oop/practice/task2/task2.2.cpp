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
    
    float a = -0.6, b = 5.3,z,t;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    z = sqrt(abs(pow(a, 2)-pow(b, 2)));
    cout << "z = " << z << endl;
    if (z < b) {
        t = cbrt(z+pow(a, 2)*b);
    } else if (z == b) {
        t = 1-log10(z)+cos(pow(a, 2)*b);
    } else {
        t = 1/(cos(z*a));
    }
    
    cout << "t = " << t << endl;
    return 0;
}
