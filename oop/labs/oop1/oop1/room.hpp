//
//  room.hpp
//  oop1
//
//  Created by MacBook Air on 09.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#ifndef room_hpp
#define room_hpp

#include "libraries.h"

enum typeOfAnimal {preditor, behavior};

// MARK: Animal class
class Animal {
public:
    typeOfAnimal animalType;
    string animalName;
};

// MARK: Room class
class room {
private:
    string name;
    Animal *ptrAnimals = new Animal[10];
    int i = 0;
public:
    room(string name);
    void addAnimalInRoom(Animal animal);
    void getAnimalInRoom();
    void hunt();
};
#endif /* room_hpp */

