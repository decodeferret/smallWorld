//
//  main.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-21.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include <iostream>
#include "RaceBanners.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "GameStart.hpp"
#include "MapLoader.hpp"
#include "Race.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
//    RaceBanners *rb;
//    rb->setRace("Ogres");
//    Badges b;
//    b.setName("Bloody");
//
//    Race r1;
//
//    r1.newRace(b, rb);
//
//    Player p1;
//
//    p1.setRace(r1);
//
//    cout << p1.getRace() << endl;
//    cout << p1.getCoins() << endl;
//
//    p1.addCoins(24);
//    p1.loadTokens();
//    p1.setActive();
//
//    cout << p1.getRace() << endl;
//    cout << p1.getCoins() << endl;
//    cout << p1.getSkill() << endl;
//    cout << p1.getTokens() << endl;
//    cout << p1.getActive() << endl;

//    DICE TEST
//    p1.rollDice();
//    p1.rollDice();
//    p1.rollDice();
//    p1.rollDice();
//    p1.rollDice();
//    p1.rollDice();
//    p1.rollDice();
//    p1.rollDice();
//    p1.rollDice();
//    p1.rollDice();
//
//    p1.allRolls();
    
    Node n1;
    
    cout << n1.getRegion() << endl;
    
    Map m1;
    
    MapLoader test;
    
    //test.readFile("h");
    
    GameStart g1;
    
    return 0;
}
