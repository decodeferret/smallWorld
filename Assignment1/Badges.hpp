//
//  Badges.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Badges_hpp
#define Badges_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Badges{
private:
    string name;
    string power;
    int tokens;
public:
    Badges();
    ~Badges();
    Badges(string n, string s, int t);
    string getName(){return name;}
    void setName(string s){name = s;}
    string getPower(){return power;}
    void setPower(string p){power = p;}
    int getTokens(){return tokens;}
    void setToken(int t){tokens = t;}
};

#endif /* Badges_hpp */
