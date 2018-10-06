//  practiceOOP
//
//  Created by MacBook Air on 23.03.2018.
//  Mamaeva Arina
//  IKBO-13-17

#include <iostream>
using namespace std;

int main() {
    
    float a,b;
    
    cout << "Enter first number:" << endl;
    cin >> a;
    cout << "Enter second number:" << endl;
    cin >> b;
    
    char op;
    cout << "Choose operation +,-,*,/:" << endl;
    cin >> op;
    
    switch (op) {
        case '+':
            cout << "a + b = " << a + b << endl;
            break;
        case '-':
            cout << "a - b = " << a - b << endl;
            break;
        case '*':
            cout << "a * b = " << a * b << endl;
            break;
        case '/':
            cout << "a / b = " << a / b << endl;
            break;
        default:
            cout << "Input error! Choose correct operation! " << endl;
            break;
    }
    
    return 0;
}
