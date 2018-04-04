//
//  Region.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-27.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Region_hpp
#define Region_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Region {
private:
    int tokens;
    int lostTokens;
    bool mount;
    string name;
    int owner;
public:
    Region();
    Region(string n);
    Region(string n, int lt);
    Region(Region* r);
    Region(int t, string n, int lt, bool m);
    ~Region();
    int getTokens(){return tokens;}
    void setTokens(int t){tokens = t;}
    
    string getName(){return name;}
    void setName(string n){name = n;}
    
    int getLost(){return lostTokens;}
    void setLost(int t){lostTokens = t;}
    
    bool getMount(){return mount;}
    void setMount(bool m){mount = m;}
    
    int getPower();      //Add mountains
    
    void setOwner(int o, int n);
    int getOwner(){return owner;}
    
    string print(){return "HEllo!";}
};

#endif /* Region_hpp */
