//
//  main.cpp
//  oop7
//
//  Created by MacBook Air on 21.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int i = 0;

class Book {
public:
    string name;
    int release;
    int i = 0;
    
    Book () { }
    Book(string name, int release) {
        this->name = name;
        this->release  = release;
    }
};


void print(Book *ptr) {
    
    for (uint64_t j = 0; j < 3 ; ++j) {
            cout << "Book '" << ptr[j].name << "', release: " << ptr[j].release << endl;
    }
}


int release_cmp(const void *a, const void *b) {
    Book *ab = (Book *) a, *bb = (Book *) b;
    if (ab->release < bb->release) return -1;
    else if (ab->release == bb->release) return 0;
    else return 1;
}

int name_cmp(const void *a, const void *b) {
    Book *ab = (Book *) a, *bb = (Book *) b;
    
    return strcmp(ab->name.c_str(), bb->name.c_str());
}

Book *ptr = new Book[3];

void addBook(Book book) {
    ptr[i] = book;
    i++;
}


void sortByname (Book *S, int N)
{
    qsort(S, N, sizeof(Book), &name_cmp);
    print(S);
    
}

void sortByRelease(Book *S, int N) {
    qsort(S, N, sizeof(Book), &release_cmp);
    print(S);
}

int main() {
    
    Book book1("tmp1",9);
    Book book2("tmp2",5);
    Book book3("tmp3",3);
    
    addBook(book3);
    addBook(book2);
    addBook(book1);
    
    cout << "original array:" << endl;
    print(ptr);
    cout << endl;
    
    cout << "sort array by name of the Book:" << endl;
    sortByname(ptr, 3);
    cout << endl;
    
    cout << "sort array by release of the Book:" << endl;
    sortByRelease(ptr, 3);
    cout << endl;
    
    return 0;
}
