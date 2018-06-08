//
//  main.cpp
//  practiceOOP
//
//  Created by MacBook Air on 31.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Transport {
protected:
    double speed;
    string color;
    // points
    int distance = 0;
    
    virtual void move(int meters_to_go) {
        unsigned int lastDistance = distance - meters_to_go;
        cout << "I drove " << lastDistance << "!" << endl;
        
        distance = distance + meters_to_go;
    }
};

class Car: protected Transport {
private:
    string mark;
public:
    Car(string color, double speed) {
        this->color = color;
        this->speed = speed;
    }
    ~ Car() {
        cout << "objects class Car no more work" << endl;
    }
    
    void setCarMark (string mark) {
        this->mark = mark;
        
        cout << "This is " << mark << "." << endl;
    }
    
    void displayCarSpeed() {
        cout << "The car speed is " << speed << " km/h." << endl;
    }
    void displayCarColor() {
        cout << "This car is " << color << " color." << endl;
    }
};

class Bus: protected Transport {
private:
    int passengers_count;
public:
    Bus(string color) {
        this->color = color;
    }
    ~ Bus() {
        cout << "objects class Bus no more work" << endl;
    }
    
    void addPassengers(int passengers) {
        passengers_count+= passengers;
    }
    void came_out_Passengers(int passengers) {
        passengers_count-=passengers;
    }
    void displayPassengersCount() {
        cout << "In a bus " << passengers_count << " passengers." << endl;
    }
    void displayBusColor() {
        cout << "This bus is " << color << " color." << endl;
    }
};

class Bike: protected Transport {
private:
    string things_in_buscket[10];
    int i = 0;
public:
    
    ~ Bike() {
        cout << "objects class Bike no more work" << endl;
    }
    
    void add_thing_to_buscket(string thing) {
        things_in_buscket[i] = thing;
        i++;
    }
    void display_things_in_busket() {
        cout << "Things in the bike busket:" << endl;
        for (int c = 0; c < 10; c++) {
            cout << c << "." << things_in_buscket[c] << endl;
        }
    }
};


int main() {
    
    Car mayCar("red",288.28);
    mayCar.setCarMark("Porsche");
    mayCar.displayCarColor();
    mayCar.displayCarSpeed();
    mayCar.~Car();
    
    cout << "\n";
    
    Bus number8_Bus("yellow");
    number8_Bus.displayBusColor();
    number8_Bus.addPassengers(8);
    number8_Bus.came_out_Passengers(2);
    number8_Bus.displayPassengersCount();
    number8_Bus.~Bus();
    
    cout << "\n";
    
    Bike myBike;
    myBike.add_thing_to_buscket("can of water");
    myBike.add_thing_to_buscket("my book");
    myBike.add_thing_to_buscket("sandwich");
    myBike.add_thing_to_buscket("ear pods");
    myBike.add_thing_to_buscket("nupkin");
    myBike.display_things_in_busket();
    
    cout << "\n";
    
    return 0;
}











