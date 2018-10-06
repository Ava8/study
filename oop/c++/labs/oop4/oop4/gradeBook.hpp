//
//  gradeBook.hpp
//  oop4
//
//  Created by MacBook Air on 06.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#ifndef gradeBook_hpp
#define gradeBook_hpp

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

class GradeBook {
private:
    int i = 0;
    string studentName;
    map<string,int> gradeBook;
public:
    GradeBook(string studentName);
    ~ GradeBook();
    
    void passExam(string subject,int mark);
    void displayGradeBook();
};

#endif /* gradeBook_hpp */
