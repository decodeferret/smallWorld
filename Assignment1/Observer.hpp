//
//  Observer.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-04-03.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include <stdio.h>
#include <ostream>
#include <iostream>
#include "Map.hpp"



using namespace std;

class Observer{
public:
    Observer();
    ~Observer();
    
    void clearScreen();
    void generateScreen(int t, int player, int c);
    void domination(Map* m, int p, int show);
};

#endif /* Observer_hpp */
