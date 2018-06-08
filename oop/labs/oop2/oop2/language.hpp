//
//  language.hpp
//  oop2
//
//  Created by MacBook Air on 20.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#ifndef language_hpp
#define language_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Language {
public:
    string name;

    Language();
    Language(string name);
    ~Language();
};


#endif /* language_hpp */
