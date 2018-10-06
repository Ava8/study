//
//  main.cpp
//  oop3
//
//  Created by MacBook Air on 05.05.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include "gift.hpp"

using namespace std;

int main() {
    
    Gift gift(card, 50);
    gift.budget = 100;
    gift.calculateBudget(gift.budget, gift.coast);
    gift.calculateBudget(gift.budget, gift.coast, 20);
    gift.setSign(BirthDay, "Alice");
    cout << gift;
    
    return 0;
}
