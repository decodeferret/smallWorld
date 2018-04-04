//
//  Race.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-03-29.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Race.hpp"

Race::Race(){
//    startTokens = banner.getTokens() + badge.getTokens();
//    currTokens = startTokens;
}
Race::Race(Race *r){
    banner = r->banner;
    badge = r->badge;
    startTokens = banner->getTokens() + badge->getTokens();
    currTokens = startTokens;
}
Race::Race(Badges *b, RaceBanners *rb){
    banner = rb;
    badge = b;
    startTokens = banner->getTokens() + badge->getTokens();
    currTokens = startTokens;
}
Race::~Race(){
//    delete badge;
//    badge = nullptr;
//    delete banner;
//    banner = nullptr;
}
string Race::getName(){
    return badge->getName() + " " + banner->getRace();
}

void Race::switchActive(){
    if (active == true)
        active = false;
    else
        active = true;
}

string Race::getSkill(){
    return "SKILL";
}
string Race::getPower(){
    return "POWER";
}
