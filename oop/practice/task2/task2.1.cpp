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
    
    float a = 4.8, b = -7.9,n,m;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    n = cbrt(a-b);
    cout << "n = " << n << endl;
    if (n < b) {
        m = ((n+a)/-b) + sqrt(pow(sin(a), 2)-cos(n));
    } else if (n == b) {
        m = pow(b, 2) + tan(n*a);
    } else {
        m = pow(b, 3) + n*pow(a, 2);
    }
    
    cout << "m = " << m << endl;
    return 0;
}
