//
//  country.hpp
//  oop2
//
//  Created by MacBook Air on 20.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#ifndef country_hpp
#define country_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "language.hpp"

using namespace std;

class Country {
private:
    string name;
    int i = 0;
    Language mainLang;
    Language *ptrLanguages = new Language[5];
public:
    Country(string name);

    void setMainLang(Language mainLang);
    void addLang(Language otherLang);
    void displayInfo();
    
    ~Country();
};

#endif /* country_hpp */
