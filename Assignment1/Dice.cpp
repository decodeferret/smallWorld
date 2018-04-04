//
//  Dice.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-26.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Dice.hpp"

Dice::Dice(){
    srand((unsigned)time(0));
}
Dice::~Dice(){
    
}
int Dice::requestDice(){
    int random;
    random = (rand()%6);
    if (random == 4 || random == 5)
        random = 0;
    cout << random << endl;
    totalRolls++;
    if (random == 0)
        zeroRolls++;
    if (random == 1)
        oneRolls++;
    if (random == 2)
        twoRolls++;
    if (random == 3)
        threeRolls++;
    return random;
}

void Dice::allRolls(){
    cout << "Zeros: " << (double)zeroRolls/totalRolls << endl;
    cout << "Ones: " << (double)oneRolls/totalRolls << endl;
    cout << "Twos: " << (double)twoRolls/totalRolls << endl;
    cout << "Threes: " << (double)threeRolls/totalRolls << endl;
}
