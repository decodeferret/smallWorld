//
//  RaceBanners.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef RaceBanners_hpp
#define RaceBanners_hpp

#include <stdio.h>
#include <string>

using namespace std;

class RaceBanners{
private:
    string race;
    string skill;
    int tokens;
public:
    RaceBanners();
    ~RaceBanners();
    
    RaceBanners(string r, string s, int t);
    
    string getRace(){return race;}
    void setRace(string r){race = r;}
    
    string getSkill(){return skill;}
    void setSkill(string s){skill = s;}
    
    int getTokens(){return tokens;}
    void setTokens(int t){tokens = t;}
    
};

#endif /* RaceBanners_hpp */
