//
//  Player.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Coins.hpp"
#include "Tokens.hpp"
#include "Race.hpp"
#include "Dice.hpp"

using namespace std;

class Player{
private:
    Coins coins;
    Tokens tokens;
    Race currRace;
    Dice dice;
    int currToken; //CURRENTLY Available tokens
    int tokenMax;   //Maximum num tokens race started with
    int decorator[3];
    bool save;
    //vector<Region*> regions;
public:
    Player();
    ~Player();
    
    Player(int c);
    
    void addCoins(int c) {coins.addCoins(c);}
    int getCoins(){return coins.getValue();}
    
    string getRace(){return currRace.getName();}
    void setRace(Race r);
    
    string getSkill(){return currRace.getSkill();}
    string getPower(){return currRace.getPower();}
    
    //Player keeps track of how many available tokens they have.
    void loadTokens() {currToken = currRace.getTokens(); tokenMax = currToken;}
    int getTokens() {return currToken;}
    void setTokens(int t){currToken-=t;}
    void addTokens(int t){currToken+=t;}
    
    void setActive() {currRace.switchActive();}
    bool getActive() {return currRace.checkActive();}
    
    void rollDice() {dice.requestDice();}
    void allRolls() {dice.allRolls();}
    
    void setupDecor();
    int getDecor(int i){return decorator[i];}
    
    
//    void setRegion(int i, Region* r) {regions[i] = r;}
//    Region* getRegion(int i) {return regions[i];}
    
    //To be added
    /*
        score
        decline
    */
};

#endif /* Player_hpp */




//This mess needs to be redone, don't store as strings. Store as pointers? to banners and badges
//    void setRace(string r);
//    string getRace();
//
//    void setSkill(string s) {rb.setSkill(s);}
//    string getSkill(){return rb.getSkill();}
//
//    void setType(string t) {badges.setName(t);}
//    string getType() {return badges.getName();}
//
//    void setPower(string p) {badges.setPower(p);}
//    string getPower() {return badges.getPower();}
