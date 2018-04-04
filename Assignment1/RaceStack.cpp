//
//  RaceStack.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-03-29.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "RaceStack.hpp"
#include <iostream>

using namespace std;

bool RaceStack::push(Race x)
{
    if (top >= 25)
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        raceStack[++top] = x;
        return true;
    }
}

//Must check if empty before calling
Race RaceStack::pop()
{
        Race x = raceStack[top--];
        return x;
}

bool RaceStack::isEmpty()
{
    return (top < 0);
}
