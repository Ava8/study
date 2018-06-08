//
//  main.cpp
//  practiceOOP
//
//  Created by MacBook Air on 23.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Book{
private:
    string name;
    string author;
    float price;
public:
    Book(string nameOfBook, string BookAuthor, float BookPrice) {
        name = nameOfBook;
        author = BookAuthor;
        price = BookPrice;
    }
    void getBook(){
        cout << "Book: " << name << " by " << author << ", coast: " << price << " rub" << endl;
    }
};

class GroupsOfStudents {
private:
    string name;
    int count;
public:
    GroupsOfStudents(string nameOfGroup, int countOfStudents){
        name = nameOfGroup;
        count = countOfStudents;
    }
    void getGroup(){
        cout << "Group: " << name << ", count of Student in group: " << count << endl;
    }
};

class Auto {
private:
    string mark;
    string model;
    int release;
public:
    Auto(string AutoMark, string AutoModel, int AutoRelease){
        mark = AutoMark;
        model = AutoModel;
        release = AutoRelease;
    }
    
    void getAuto() {
        cout << "Auto: " << mark << " " << model << ", release: " << release << " year" << endl;
    }
};


int main() {
    Book("C++", "Bjarne Stroustrup", 500).getBook();
    GroupsOfStudents("IKBO-13-17", 30).getGroup();
    Auto("BMW", "x6", 2016).getAuto();
}


