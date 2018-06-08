//
//  main.cpp
//  oop6
//
//  Created by MacBook Air on 21.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
using namespace std;

class Book {
public:
    
    void getBook(string Author, string Name) {
        this->Author = Author;
        this->Name = Name;
    }
    virtual void findBook() {
        cout << "you can buy this book in any store" << endl;
    }
    //pure :
    virtual void print() = 0;

    string Author;
    string Name;
};

class FictionBook: public Book {
public:
    void findBook() override {
        cout << "you can buy this one in book store" << endl;
    }
    void print() override {
        cout << "This is fiction book, named: '" << Name << "' by " << Author << endl;
    }
};

class TextBook: public Book {
public:
    void findBook() override {
        cout << "you can take this book from University library" << endl;
    }
    void print() override {
        cout << "This is text book for: '" << Name << "' by " << Author << endl;
    }
};


int main() {
    
    FictionBook fb;
    TextBook tb;
    
    fb.getBook("J.K.Rowling", "Harry Potter Books collection");
    fb.print();
    fb.findBook();

    tb.getBook("Polyakova", "English for students");
    tb.print();
    tb.findBook();
 
    return 0;
}
