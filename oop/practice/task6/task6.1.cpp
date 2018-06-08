#include <iostream>

using namespace std;

class Property {
public:
    double worth;
    Property(double worth): worth{worth} {}
    virtual ~Property() {}
    virtual double process() = 0;
};

class Appartment: public Property {
public:
    Appartment(double worth): Property(worth) {}
    ~Appartment() {}
    double process() {
        return worth/1000;
    }
};

class Car: public Property {
public:
    Car(double worth): Property(worth) {}
    ~Car() {}
    double process() {
        return worth/200;
    }
};

class CountryHouse: public Property {
public:
    CountryHouse(double worth): Property(worth) {}
    ~CountryHouse() {}
    double process() {
        return worth/500;
    }
};

int main() {
    Property *properties[7] = {
        new Appartment(1780),
        new Appartment(2500),
        new Appartment(1200),
        new Car(5000),
        new Car(2000),
        new CountryHouse(1500),
        new CountryHouse(7000)
    };

    for (Property *property: properties) {
        cout << property->process() << endl;
    }

    for (Property *property: properties) {
        delete property;
    }

    return 0;
}
