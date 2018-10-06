//  practiceOOP
//
//  Created by MacBook Air on 23.03.2018.
//  Mamaeva Arina
//  IKBO-13-17

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "enter your name: ";
    // полчуаем строку от cin и записываем в переменную name
    getline(cin, name);
    if (name.length() != 0)
        cout << "Hi " << name << "!" << endl;
    else
        cout << "Input error" << endl;
    
    
    return 0;
}
