//
//  main.cpp
//  practiceOOP
//
//  Created by MacBook Air on 31.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

class Figure {
protected:
    double s;
    double p;
    double a;
    double b;
    double c;
    double d;

    Figure() {}
    ~ Figure() {}
    void setFigure(double side_a,double side_b, double side_c,double side_d) {
        a = side_a;
        b = side_b;
        c = side_c;
        d = side_d;
    }
    virtual void findSquare(){}
    void findPerimetr() {
        p = a + b + c + d;
    }
};

class Quadrangle: protected Figure {
public:
    Quadrangle(){}
    ~ Quadrangle() {}
   void findSquare() override {
       findPerimetr();
       s = sqrt((p/2-a)*(p/2-b)*(p/2-c)*(p/2-d));
       cout << "Square of Quadrangle is "<< s << endl;
   }
};

class Rhombus: protected Figure {
private:
    double h;
public:
    Rhombus(){}
    ~ Rhombus() {}
    void setFigure(double side_a, double h) {
        a = side_a;
        this->h = h;
    }
    void findSquare() override {
        s = a*h;
        cout << "Square of Rhombus is " << s << endl;
    }
};

class Rectangle: protected Figure {
public:
    Rectangle(){}
    ~ Rectangle() {}
    void setFigure(double side_a,double side_b)  {
        a = side_a;
        b = side_b;
    }
    void findSquare() override {
        s = a*b;
        cout << "Square of Rectangle is " << s << endl;
    }
};


int main() {
    
    Rectangle figure1;
    figure1.setFigure(4, 2);
    figure1.findSquare();
    
    return 0;
}











