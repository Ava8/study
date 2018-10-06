//
//  main.cpp
//  practiceOOP
//
//  Created by MacBook Air on 04.04.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Display {
protected:
    string screen_resolution;
    double screen_diagonal;
    
    void display_parameters() {
        cout << "Display parameters: resolution - " << screen_resolution << ", diagonal - " << screen_diagonal << endl;
    }
};

class KeyBoard {
protected:
    int keys;
    string language;
    
    void keyboard_parameters() {
        cout << "Keyboard parameters: keys count - " << keys << ", main keyboard language - " << language << endl;
    }
};

class Notebook: protected Display, protected KeyBoard {
private:
    string processor;
    int RAM;
public:
    Notebook(string processor, int ram, string screen_resolution, double screen_diagonal, int keyboard_keys, string keyboard_language) {
        this->processor = processor;
        RAM = ram;
        this->screen_resolution = screen_resolution;
        this->screen_diagonal = screen_diagonal;
        keys = keyboard_keys;
        language = keyboard_language;
    }
    
    void display_information() {
        cout << "Notebook technical parameters: processor - " << processor << ", RAM - " << RAM << " GB" << endl;
        display_parameters();
        keyboard_parameters();
        cout << endl;
    }
};

class Smartphone: protected Display, protected KeyBoard {
private:
    string OS_version;
    int camera_parameters;
public:
    Smartphone(string OS_version, int camera_parameters, string screen_resolution, double screen_diagonal, int keyboard_keys, string keyboard_language) {
        this->OS_version = OS_version;
        this->camera_parameters = camera_parameters;
        this->screen_resolution = screen_resolution;
        this->screen_diagonal = screen_diagonal;
        keys = keyboard_keys;
        language = keyboard_language;
    }
    
    void display_information() {
        cout << "Smartphone technical parameters: OS version - " << OS_version << ", camera - " << camera_parameters << " MP" << endl;
        display_parameters();
        keyboard_parameters();
        cout << endl;
    }
};

class Computer: protected Display, protected KeyBoard {
private:
    string OS;
    double weight;
public:
    Computer(string OS, double weight, string screen_resolution, double screen_diagonal, int keyboard_keys, string keyboard_language) {
        this->OS = OS;
        this->weight = weight;
        this->screen_resolution = screen_resolution;
        this->screen_diagonal = screen_diagonal;
        keys = keyboard_keys;
        language = keyboard_language;
    }
    
    void display_information() {
        cout << "Computer technical parameters: OS - " << OS << ", weight - " << weight << " kg" << endl;
        display_parameters();
        keyboard_parameters();
        cout << endl;
    }
};

int main() {
    
    Notebook notebook("Intel Core i7", 32, "1920x1080", 13, 73, "english");
    notebook.display_information();
    
    Smartphone iphone("iOS 11", 12, "1920x1080", 5.5, 38, "russian");
    iphone.display_information();
    
    Computer iMac("Mac OS X Yosemite", 1.3, "5120x2880", 27, 73, "english");
    iMac.display_information();
    
    return 0;
}











