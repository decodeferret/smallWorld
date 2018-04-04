//
//  GameStart.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-03-21.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef GameStart_hpp
#define GameStart_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Player.hpp"
#include "MapLoader.hpp"
#include "GameTurn.hpp"
#include "RaceStack.hpp"
#include "Observer.hpp"

using namespace std;

class GameStart {
public:
    GameStart();
    ~GameStart();
    
    string getName();
    int getPlayers();
private:
    string mapName;
    int numPlayers;
    int attacker;
    int defender;
    int soldiers;
    Observer o;
    
    //Players stored as a vector
    vector<Player> plyrs;
    Player p1;
    Player p2;
    MapLoader m1;
    GameTurn turnMarker;
    
    //Create wells
    vector<RaceBanners> bannerWell;
    void generateBanners();
    vector<Badges> badgeWell;
    void generateBadges();
    
    //Race Stack to be added
    Race visibRaces[6];
    int racePicker;
    RaceStack raceDeck;
    void generateRaces();
    void pickRace(Player *p); //Full instructions for picking a new race
    
    //Generate Map to play on
    Map map;
    void generateMap();
};

#endif /* GameStart_hpp */
