//
//  RaceStack.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-03-29.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef RaceStack_hpp
#define RaceStack_hpp

#include <stdio.h>
#include "Race.hpp"

using namespace std;

class RaceStack
{
private:
    int top;
public:
    Race raceStack[25];    //Maximum size of Stack
    
    RaceStack()  { top = -1; }
    bool push(Race x);
    Race pop();
    bool isEmpty();
};

#endif /* RaceStack_hpp */
