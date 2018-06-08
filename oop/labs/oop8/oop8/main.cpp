//
//  main.cpp
//  oop8
//
//  Created by MacBook Air on 22.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class City {
public:
    string name;
    string country;
    
    size_t population;
    size_t average_salary;
    double square;

    City() { name = "anon"; country = "anon"; population = average_salary = square = 0; }
    
    City(string name, string country, size_t population, size_t average_salary, double square) {
        this->name = name;
        this->country = country;
        this->square = square;
        this->population = population;
        this->average_salary = average_salary;
    }
};

bool operator<(City &a, City &b) {
    if (a.square < b.square)
        if (a.population < b.population)
            if (a.average_salary < b.average_salary)
                return true;
    return false;
}

bool operator>(City &a, City &b) {
    if (a.square > b.square)
        if (a.population > b.population)
            if (a.average_salary > b.average_salary)
                return true;
    return false;
}


void sortCityMethod1(vector<City> &v) {
    sort(v.begin(), v.end(), [](City a, City b) { return a < b; });
    for (uint64_t j = 0; j < v.size() ; ++j) {
        if (!v[j].name.empty())
        cout << "City: " << v[j].name << endl;
    }
}

void sortCityMethod2(vector<City> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[i] < v[j]) {
                City tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
    
    for (uint64_t j = 0; j < v.size() ; ++j) {
        if (!v[j].name.empty())
            cout << "City: " << v[j].name << endl;
    }
}

void sortCityMethod3(vector<City> &v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        for (auto j = v.begin(); j != v.end(); j++) {
            if (*i < *j) {
                auto tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
    for (uint64_t j = 0; j < v.size() ; ++j) {
        if (!v[j].name.empty())
            cout << "City: " << v[j].name << endl;
    }
}

int main() {
    
    vector<City> v1{{"Moscow", "Russia", 10, 60, 2.5},
        {"Tokyo", "Japan", 6, 40, 1},
        {"Paris", "France", 9, 50, 0.9}
    };
    vector<City> v2 = v1, v3 = v1;
    
    // print original vector
    cout << "original vector:" << endl;
    for (uint64_t j = 0; j < v1.size() ; ++j) {
        if (!v1[j].name.empty())
            cout << "City: " << v1[j].name << endl;
    }
    cout << endl;
    
    cout << "different implementation of sort vector type City by average salary" << endl;
    cout << endl;
    
    cout << "sort vector by STL library method 'sort'" << endl;
    sortCityMethod1(v1);
    
    cout << endl;
    
    cout << "sort vector without iterators" << endl;
    sortCityMethod2(v2);
    
    cout << endl;
    
    cout << "sort vector with iterators" << endl;
    sortCityMethod3(v3);
    
    cout << endl;
    
    return 0;
}
