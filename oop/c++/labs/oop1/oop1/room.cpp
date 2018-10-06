//
//  room.hpp
//  oop1
//
//  Created by MacBook Air on 09.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include "libraries.h"
#include "room.hpp"

room::room(string name) {
    name = name;
}

void room::addAnimalInRoom(Animal animal) {
    ptrAnimals[i] = animal;
    i++;
}
void room::getAnimalInRoom() {
    for (int i = 0; i < 30; i++){
        cout << ptrAnimals[i].animalName << endl;
    }
}
void room::hunt() {
    int j = 0, k = 0;
    Animal *preditor = new Animal[10];
    Animal *behavior = new Animal[10];
    for (int i = 0; i < 10; i++) {
        if (ptrAnimals[i].animalType == ::preditor) {
            preditor[j] = ptrAnimals[i];
            j++;
        } else {
            behavior[k] = ptrAnimals[i];
            k++;
        }
    }
    for (int i = 0; i < j; i++){
        if (!preditor[i].animalName.empty() && !preditor[i+1].animalName.empty())
            cout << preditor[i].animalName << ", ";
        else
            cout << preditor[i].animalName;
    }
    cout << " can kill: - ";
    for (int i = 0; i < k; i++) {
        if (!behavior[i].animalName.empty() && !behavior[i+1].animalName.empty())
            cout << behavior[i].animalName << ", ";
        else
            cout << behavior[i].animalName;
    }
    cout << endl;
}

