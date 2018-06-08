//
//  lab.cpp
//  oop1
//
//  Created by MacBook Air on 09.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include "libraries.h"
#include "room.hpp"

int main() {
    
    // MARK: Create animals
    Animal Cat;
    Cat.animalType = preditor;
    Cat.animalName = "Murka the Cat";
    
    Animal Mouse;
    Mouse.animalType = behavior;
    Mouse.animalName = "Miki the Mouse";
    
    Animal Humster;
    Humster.animalType = behavior;
    Humster.animalName = "Grizly the Humster";
    
    Animal Snake;
    Snake.animalType = preditor;
    Snake.animalName = "Lorry the Snake";
    
    // MARK: Create room
    room Room("test");
    Room.addAnimalInRoom(Cat);
    Room.addAnimalInRoom(Mouse);
    Room.addAnimalInRoom(Humster);
    Room.addAnimalInRoom(Snake);
    
    // MARK: test programm
    
    Room.hunt();
    
    return 0;
}










