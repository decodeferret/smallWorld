//
//  Race.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-03-29.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Race_hpp
#define Race_hpp

#include <stdio.h>
#include <iostream>
#include "RaceBanners.hpp"
#include "Badges.hpp"
#include <string>

using namespace std;

class Race {
private:
    RaceBanners *banner;
    Badges *badge;
    bool active;
    int startTokens;
    int currTokens;
public:
    Race();
    Race(Race *r);
    Race(Badges *b, RaceBanners *rb);
    ~Race();
    
    string getName(); //Returns full name of race, combining badge and banner
    
    string getSkill(); //Returns skill associated with banner
    
    string getPower(); //Returns power associated with badge
    
    bool checkActive(){return active;}
    void switchActive();
    
    int getTokens(){return currTokens;}
    void setTokens(int t){currTokens = t;}
    
    void newRace(Badges *b, RaceBanners *rb){banner = rb; badge = b;}
};

#endif /* Race_hpp */
