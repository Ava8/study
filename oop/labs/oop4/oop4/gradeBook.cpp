//
//  gradeBook.cpp
//  oop4
//
//  Created by MacBook Air on 06.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include "gradeBook.hpp"

GradeBook::GradeBook(string studentName) {
    this->studentName = studentName;
}
GradeBook::~GradeBook() {}

void GradeBook::passExam(string subject,int mark) {
    gradeBook.insert(pair<string, int>(subject,mark));
}

void GradeBook::displayGradeBook() {
    if (!gradeBook.empty()) {
        cout << studentName << "'s GRADE BOOK" << "\n";
        cout << "SUBJECT : MARK" << "\n";
        for (auto i = gradeBook.begin();
             i != gradeBook.end();
             i++) {
            cout << (*i).first << " : " << (*i).second << endl;
        }
    } else {
        cout << studentName << "'s grade book is empty" << endl;
    }
}
