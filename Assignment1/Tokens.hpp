//
//  Tokens.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Tokens_hpp
#define Tokens_hpp

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Tokens {
private:
    string race;
public:
    Tokens();
    Tokens(string r);
    ~Tokens();
    string getRace(){return race;}
    void setRace(string r){race = r;}
};

#endif /* Tokens_hpp */
