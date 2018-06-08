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

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: program filename" << endl;
        return 1;
    }

    ifstream f{argv[1]};
    if (!f) {
        cout << "error" << endl;
        return 1;
    }

    string text;
    while (f >> text) {
        cout << text << endl;
    }

    return 0;
}
