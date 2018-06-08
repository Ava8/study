//
//  country.cpp
//  oop2
//
//  Created by MacBook Air on 20.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "country.hpp"
#include "language.hpp"

int main() {
    
    // MARK: Set base languages
    Language rus("Russian");
    Language eng("English");
    Language jpn("Japanese");
    Language fr("French");
    
    // MARK: Set country and test
    Country rf("Russia");
    rf.setMainLang(rus);
    rf.addLang(eng);
    rf.addLang(jpn);
    rf.displayInfo();
    
    
    Country c("Canada");
    c.setMainLang(eng);
    c.addLang(fr);
    c.displayInfo();
 
    return 0;
}
