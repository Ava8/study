//
//  main.cpp
//  practiceOOP
//
//  Created by MacBook Air on 04.04.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream f{"tmp.txt"};

    string line = " ";
    while (line != "") {
        getline(cin, line);
        f << line << endl;
    }

    return 0;
}
