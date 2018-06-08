//
//  main.cpp
//  oop4
//
//  Created by MacBook Air on 06.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include "gradeBook.hpp"
using namespace std;

int main() {

    GradeBook test("Arina");
    test.passExam("Math", 5);
    test.passExam("Physic", 4);
    test.passExam("OOP", 5);
    test.displayGradeBook();
    
    return 0;
}
