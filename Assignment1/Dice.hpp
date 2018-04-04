//
//  Dice.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-26.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Dice_hpp
#define Dice_hpp

#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Dice {
private:
    int totalRolls;
    int zeroRolls;
    int oneRolls;
    int twoRolls;
    int threeRolls;
public:
    Dice();
    ~Dice();
    int requestDice();
    void allRolls();
};

#endif /* Dice_hpp */
