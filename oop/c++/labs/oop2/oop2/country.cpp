//
//  country.cpp
//  oop2
//
//  Created by MacBook Air on 20.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include "country.hpp"

Country:: Country(string name) {
    this -> name = name;
}

void Country::setMainLang(Language mainLang) {
    this -> mainLang = mainLang;
}

void Country::addLang(Language otherLang) {
    ptrLanguages[i] = otherLang;
    i++;
}

void Country::displayInfo() {
    cout << "Main language of " << name << " is: " << mainLang.name << endl;
    cout << "Other languages used: ";
    for (int i = 0; i < 5; i++) {
        if (!ptrLanguages[i].name.empty() && !ptrLanguages[i+1].name.empty())
            cout << ptrLanguages[i].name << ", ";
        else
            cout << ptrLanguages[i].name;
    }
    cout << endl;
}

Country:: ~Country() {
    delete [] ptrLanguages;
}
