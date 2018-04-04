//
//  Badges.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Badges.hpp"

Badges::Badges(string n,string p,int t){
    name = n;
    power = p;
    tokens = t;
}
Badges::Badges(){
    tokens = 3;
}
Badges::~Badges(){
    
}
