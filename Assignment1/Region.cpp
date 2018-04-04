//
//  Region.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-27.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Region.hpp"

Region::Region(){
    tokens = 0;
    name = "Hell";
    lostTokens = 0;
    owner = 0;
}
Region::Region(string n){
    name = n;
    tokens = 0;
    lostTokens = 0;
    owner = 0;
}
Region::Region(string n, int lt){
    name = n;
    tokens = 0;
    lostTokens = lt;
    owner = 0;
}
Region::Region(Region* r){
    name = r->getName();
    owner = 0;
}
Region::Region(int t, string n, int lt, bool m){
    tokens = t;
    name = n;
    lostTokens = lt;
    mount = m;
    owner = 0;
}
Region::~Region(){
    
}
int Region::getPower(){
    int temp = tokens + lostTokens;
    return temp;
}
void Region::setOwner(int o, int n){
    owner = o;
    lostTokens = 0;
    tokens = n;
}
