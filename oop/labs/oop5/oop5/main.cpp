//
//  main.cpp
//  oop5
//
//  Created by MacBook Air on 21.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
using namespace std;


class Store {
public:
    Store(string name);
    ~Store();
protected:
    void printName();
private:
    string name;
};

class GroceryStore: public Store {
public:
    GroceryStore(string name, string adress,string workHours);
    ~GroceryStore();
    
    void changeAdress(string newAdress);
    void changeWorkHours(string newWorkHours);
    void printInfo();
private:
    string adress;
    string workHours;
};

class CarStore: private Store {
public:
    CarStore(string name, string autoBrand);
    ~CarStore();
    
    void changeAutoBrand(string newAutoBrand);
    void printInfo();
private:
    string carBrand;
};

Store::Store(string name) {
    this->name = name;
}
Store::~Store() {
    cout << "class Store stop working here" << endl;
}
void Store::printName() {
    cout << "Store: " << name << endl;
}

GroceryStore::GroceryStore(string name, string adress,string workHours) : Store(name) {
    this->adress = adress;
    this->workHours = workHours;
}
GroceryStore::~GroceryStore() {
    cout << "class GroceryStore stop working here" << endl;
}
void GroceryStore::changeAdress(string newAdress) {
    adress = newAdress;
}
void GroceryStore::changeWorkHours(string newWorkHours) {
    workHours = newWorkHours;
}
void GroceryStore::printInfo() {
    printName();
    cout << "Adress: " << adress << endl;
    cout << "Work Hours: " << workHours << endl;
}

CarStore::CarStore(string name, string autoBrand) : Store(name) {
    this->carBrand = autoBrand;
}
CarStore::~CarStore() {
    cout << "class CarStore stop working here" << endl;
}
void CarStore::changeAutoBrand(string newAutoBrand) {
    carBrand = newAutoBrand;
}
void CarStore::printInfo() {
    printName();
    cout << "Brand of cars: " << carBrand << endl;
}

int main() {
    
    GroceryStore av("AzbukaVkusa", "Moscow, Leninsky Prospekt, 87", "24/7");
    av.changeAdress("Saint Petersburg, Liteiny Prospekt, 26");
    av.changeWorkHours("everyday 9 a.m - 23 p.m");
    av.printInfo();
    
    CarStore bc("Britain cars", "Bently");
    bc.changeAutoBrand("Roll Royce");
    bc.printInfo();
    
    return 0;
}
