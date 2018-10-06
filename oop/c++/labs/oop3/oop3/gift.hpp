//
//  gift.hpp
//  oop3
//
//  Created by MacBook Air on 06.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#ifndef gift_hpp
#define gift_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

enum typeOfGift {card, thing, giftVoucher};
enum typeOfSign {BirthDay, NewYear};

class Gift {
public:
    typeOfGift giftType;
    typeOfSign occasion;
    double budget;
    double coast;
    int discount;
    string sign;
    string recipientName;
    
    Gift(typeOfGift giftType, double coast);
    ~ Gift();
    
    void setSign(typeOfSign occasion, string recipientName);
    friend ostream& operator<<(ostream &os, const Gift &obj);
    void calculateBudget(double budget, double coast);
    void calculateBudget(double budget, double coast, int discount);
    
};

#endif /* gift_hpp */
