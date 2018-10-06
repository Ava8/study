//
//  gift.cpp
//  oop3
//
//  Created by MacBook Air on 06.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include "gift.hpp"

Gift::Gift(typeOfGift giftType, double coast) {
    this->giftType = giftType;
    this->coast = coast;
}

Gift::~Gift() {
    
}

void Gift::setSign(typeOfSign occasion, string recipientName) {
        switch (occasion) {
            case BirthDay:
                cout << "Happy Birth Day to " << recipientName << "!" << endl;
                break;
            case NewYear:
                cout << recipientName << "! Happy New Year!" << endl;
                break;
            default:
                cout << "type error" << endl;
                break;
        }
}

void Gift::calculateBudget(double budget, double coast) {
    if (budget < coast) {
        cout << "your budget is not enough to buy this present" << endl;
    } else {
        cout << "perfect choice! budget balance: " << budget-coast << endl;
    }
}

void Gift::calculateBudget(double budget, double coast, int discount) {
    double totalCoast = coast*discount/100;
    if (budget < totalCoast) {
        cout << "your budget is not enough to buy this present" << endl;
    } else {
        cout << "perfect choice! budget balance: " << budget-totalCoast << endl;
    }
}

ostream& operator<<(ostream &os, const Gift &obj) {
    return os<<obj.occasion;
}

