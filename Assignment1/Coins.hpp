//
//  Coins.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-21.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Coins_hpp
#define Coins_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Coins{
public:
    Coins();
    Coins(int i);
    ~Coins();
    int getValue(){return total;}
    void setValue(int v){total = v;}
    void addCoins(int c){total += c;}
private:
    int total;
};

#endif /* Coins_hpp */
