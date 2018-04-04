//
//  GameStart.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-03-21.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "GameStart.hpp"

GameStart::GameStart(){
    cout << "Which map will you play on?" << endl;
    cin >> mapName;
    
    //Checks if an appropriate filename was provided
    while(!m1.readFile(mapName)){
        cout << "This is not an appropriate map name. Please choose again." << endl;
        cin >> mapName;
    }
    
    cout << "How many players?" << endl;
    cin >> numPlayers;
    
    //Used to make sure that user picks between 2-5 players
    while (numPlayers > 5 || numPlayers < 2){
        cout << "This game is played with 2-5 players. Please choose again." << endl;
        cin >> numPlayers;
    }
    
    plyrs.push_back(p1);
    plyrs.push_back(p2);
    
    //Create the appropriate amount of players
    if (numPlayers >= 3){
        Player p3;
        plyrs.push_back(p3);
    }
    if (numPlayers >= 4){
        Player p4;
        plyrs.push_back(p4);
    }
    if (numPlayers == 5){
        Player p5;
        plyrs.push_back(p5);
    }
    
    //Let the user know that the number of players and map have been succesfully selected.
    cout << "Great job! So you'll play on " << mapName << ", with " << numPlayers << " players!" << endl;
    
    generateBadges();
    generateBanners();
    generateRaces();
    turnMarker.setLimit(numPlayers);
    
    Map map;
    //generateMap();
    map.generateRegions();

    //Startup phase
    o.clearScreen();
    turnMarker.nextTurn();
    for (int i=0; i<6; i++){
        visibRaces[i] = raceDeck.pop();
    }
    bool keepPlay = true;
    for (int i=0; i<plyrs.size(); i++){
//        Player* temp;
//        temp=&plyrs[i];
        o.clearScreen();
        
        cout << "\n-----Player " << i+1 << " turn start!-----" << endl;
        
        plyrs[i].setupDecor();
        o.clearScreen();
        
        cout << "Player " << i+1 << ": Chooses Race" << endl;
        
        pickRace(&plyrs[i]);
        
        o.generateScreen(turnMarker.getTurn(), i+1, 1);
        
        //Conquer first turn
        o.domination(&map, (int)plyrs.size(), plyrs[i].getDecor(0));
        if (plyrs[i].getDecor(2) == 1){
            for (int i=0; i<plyrs.size(); i++) {
                cout << "Player " << i+1 << " has " << plyrs[i].getCoins() << " coins." << endl;
            }
            cout << "---------------------------" << endl;
        }
        cout << "Which region would you like to conquer first?" << endl;
//        cout << "Regions available to attack:" << endl;
//        for (int i=0; i<10; i++) {
//            cout << "Region " << map.regionWell[i].getName() << " with " << map.regionWell[i].getPower() << " units.";
//            if (map.regionWell[i].getOwner() != 0)
//                cout << " Owner = [" << map.regionWell[i].getOwner() << "]";
//            cout << endl;
//        }
        cin >> defender;
        //While loop is now good
        while (defender<1||defender>10||plyrs[i].getTokens() < map.regionWell[defender-1].getPower()){
            cout << "Inelligible choice, please choose again." << endl;
            cin >> defender;
        }
            cout << "How many soldiers would you like to move?" << endl;
            cin >> soldiers;
            while (soldiers < map.regionWell[defender-1].getPower()||soldiers<2){
                cout << "Not enough soldiers! You need more than " << map.regionWell[defender].getPower() << endl;
                cin >> soldiers;
            }
//            while (soldiers<2||soldiers>plyrs[i].getTokens()){
//                cout << "Inelligible choice, please choose again." << endl;
//                cin >> soldiers;
//            }
            plyrs[i].setTokens(soldiers);
        
            i++;
            map.regionWell[--defender].setOwner(i, soldiers);
            cout << "Player " << i << " has " << plyrs[i-1].getTokens() << " tokens remaining." << endl;
            i--;
        
        //General Conquer
        cout << "Do you want to continue attacking? (y/n)" << endl;
        char t;
        cin >> t;
        if (t == 'n'){
            keepPlay = false;
        } else {
            keepPlay = true;
        }
        while (keepPlay){
            o.generateScreen(turnMarker.getTurn(), i+1, 1);
            o.domination(&map, (int)plyrs.size(), plyrs[i].getDecor(0));
            if (plyrs[i].getDecor(2) == 1){
                for (int i=0; i<plyrs.size(); i++) {
                    cout << "Player " << i+1 << " has " << plyrs[i].getCoins() << " coins." << endl;
                }
                cout << "---------------------------" << endl;
            }
            keepPlay = true;
            cout << "Which region would you like to attack from?" << endl;
//            cout << "Regions available to attack from:" << endl;
//            //Iterates through region well to see which regions are owned by player
//            for (int j=0; j<10; j++) {
//                if (map.regionWell[j].getOwner() == (i+1)){
//                    cout << "Region " << map.regionWell[j].getName() << " with " << map.regionWell[j].getPower() << " units." << endl;
//                }
//            }
            cin >> attacker;
            //Checks to make sure player entered a region they actually own
            while (attacker < 1 || attacker > 22|| map.regionWell[attacker-1].getOwner() != (i+1)){
                cout << "Inelligible choice, please choose again." << endl;
                cin >> attacker;
            }
            cout << "Adjacent regions to " << attacker << endl;
            
            //Show all adjacent regions for user
            map.showAdj(attacker);
            
            cout << "Which region would you like to attack?" << endl;
            
            cin >> defender;
            //While loop is now good
            while (defender<1||defender>10||plyrs[i].getTokens() < map.regionWell[defender-1].getPower()){
                cout << "Inelligible choice, please choose again." << endl;
                cin >> defender;
            }
            cout << "How many soldiers would you like to move?" << endl;
            cout << "You have " << plyrs[i].getTokens() << " tokens remaining." << endl;
            cin >> soldiers;
            while (soldiers < map.regionWell[defender-1].getPower()||soldiers<2){
                cout << "Not enough soldiers! You need more than " << map.regionWell[defender].getPower() << endl;
                cin >> soldiers;
            }
            plyrs[i].setTokens(soldiers);
            i++;
            map.regionWell[--defender].setOwner(i, soldiers);
            cout << "Player " << i << " has " << plyrs[i-1].getTokens() << " tokens remaining." << endl;
            i--;
            if(plyrs[i].getTokens() == 1){
                cout << "Do you want to continue attacking? (y/n)" << endl;
                char temp;
                cin >> temp;
                keepPlay = false;
                //Last chance roulette
                
            } else if(plyrs[i].getTokens() != 0){
                cout << "Do you want to continue attacking? (y/n)" << endl;
                char temp;
                cin >> temp;
                if (temp == 'n'){
                    keepPlay = false;
                }
            } else {
                keepPlay = false;
            }
        }
        
        //Player scores
        for (int j=0; j<10; j++) {
            int temp = 0;
            if (map.regionWell[j].getOwner() == (i+1)){
                temp++;
            }
            plyrs[i].addCoins(temp);
        }
        cout << "Player " << i+1 << " has " << plyrs[i].getCoins() << " coins." << endl;
        
        //map.conquer(i, &plyrs[i], &regionWell[i]);
    }
    
    //Game Starts now
    
    while(!turnMarker.nextTurn()){
        //Each turn:
        //Player can place race into decline and select a new one (maybe races in decline should be given number 6,7,8... to help with counting score)
        
        for (int i=0; i<plyrs.size(); i++){
            o.generateScreen(turnMarker.getTurn(), i+1, 0);
            //Edit decor setting
            plyrs[i].setupDecor();
            //Return all tokens to player except for 1 on each space
            for (int j=0; j<10; j++) {
                int temp = 0;
                if (map.regionWell[j].getOwner() == (i+1)){
                    temp--;
                    temp += map.regionWell[j].getTokens();
                    map.regionWell[j].setTokens(1);
                }
                plyrs[i].addTokens(temp);
            }
            keepPlay = true;
//            o.generateScreen(2, i+1, 0);
//            cout << "Reclaming tokens..." << endl;
//            cout << plyrs[i].getTokens() << " tokens available." << endl;
            while (keepPlay){
                o.generateScreen(turnMarker.getTurn(), i+1, 1);
                cout << plyrs[i].getTokens() << " tokens available." << endl;
                keepPlay = true;
                o.domination(&map, (int)plyrs.size(), plyrs[i].getDecor(0));
                if (plyrs[i].getDecor(2) == 1){
                    for (int i=0; i<plyrs.size(); i++) {
                        cout << "Player " << i+1 << " has " << plyrs[i].getCoins() << " coins." << endl;
                    }
                    cout << "---------------------------" << endl;
                }
                cout << "Which region would you like to attack from?" << endl;
                cin >> attacker;
                //Checks to make sure player entered a region they actually own
                while (attacker < 1 || attacker > 22|| map.regionWell[attacker-1].getOwner() != (i+1)){
                    cout << "Inelligible choice, please choose again." << endl;
                    cin >> attacker;
                }
                
                cout << "Adjacent regions to " << attacker << endl;
                
                //Show all adjacent regions for user
                map.showAdj(attacker);
                
                cout << "Which region would you like to attack?" << endl;
                
                cin >> defender;
                //While loop is now good
                while (defender<1||defender>10||plyrs[i].getTokens() < map.regionWell[defender-1].getPower()){
                    cout << "Inelligible choice, please choose again." << endl;
                    cin >> defender;
                }
                cout << "How many soldiers would you like to move?" << endl;
                cin >> soldiers;
                while (soldiers < map.regionWell[defender-1].getPower()||soldiers<2){
                    cout << "Not enough soldiers! You need more than " << map.regionWell[defender].getPower() << endl;
                    cin >> soldiers;
                }
                plyrs[i].setTokens(soldiers);
                i++;
                map.regionWell[--defender].setOwner(i, soldiers);
                //cout << "Player " << i << " has " << plyrs[i-1].getTokens() << " tokens remaining." << endl;
                i--;
                if(plyrs[i].getTokens() == 1){
                    cout << "Do you want to continue attacking? (y/n)" << endl;
                    char temp;
                    cin >> temp;
                    keepPlay = false;
                    //Last chance roulette
                    
                } else if(plyrs[i].getTokens() != 0){
                    cout << "Do you want to continue attacking? (y/n)" << endl;
                    char temp;
                    cin >> temp;
                    if (temp == 'n'){
                        keepPlay = false;
                    }
                } else {
                    keepPlay = false;
                }
            }
            
            //Player scores
            for (int j=0; j<10; j++) {
                int temp = 0;
                if (map.regionWell[j].getOwner() == (i+1)){
                    temp++;
                }
                plyrs[i].addCoins(temp);
            }
            cout << "Player " << i+1 << " has " << plyrs[i].getCoins() << " coins." << endl;
        }
    }
    //Show who wins
}
GameStart::~GameStart(){
    //Maybe wells should contain pointers?

    badgeWell.clear();
//    for(int i=0; i<bannerWell.size(); i++){
//        delete bannerWell[i];
//    }
    bannerWell.clear();
}

//Generate the well of badges
void GameStart::generateBadges(){
    Badges b1("Alchemist","Can flee from a fight",4);
    badgeWell.push_back(b1);
    Badges b2("Berserk","Can freeze enemies", 4);
    badgeWell.push_back(b2);
    Badges b3("Bivouacking","Noble and free", 5);
    badgeWell.push_back(b3);
    Badges b4("Commando","Can flee from a fight",4);
    badgeWell.push_back(b4);
    Badges b5("Diplomat","Can freeze enemies", 5);
    badgeWell.push_back(b5);
    Badges b6("Dragon Master","Noble and free", 5);
    badgeWell.push_back(b6);
    Badges b7("Flying","Can flee from a fight",5);
    badgeWell.push_back(b7);
    Badges b8("Forest","Can freeze enemies", 4);
    badgeWell.push_back(b8);
    Badges b9("Fortified","Noble and free", 3);
    badgeWell.push_back(b9);
    Badges b10("Heroic","Can flee from a fight",5);
    badgeWell.push_back(b10);
    Badges b11("Hill","Can freeze enemies", 4);
    badgeWell.push_back(b11);
    Badges b12("Merchant","Noble and free", 2);
    badgeWell.push_back(b12);
    Badges b13("Mounted","Can flee from a fight",5);
    badgeWell.push_back(b13);
    Badges b14("Pillaging","Can freeze enemies", 5);
    badgeWell.push_back(b14);
    Badges b15("Seafaring","Noble and free", 5);
    badgeWell.push_back(b15);
    Badges b16("Spirit","Can flee from a fight",5);
    badgeWell.push_back(b16);
    Badges b17("Stout","Can freeze enemies", 4);
    badgeWell.push_back(b17);
    Badges b18("Swamp","Noble and free", 4);
    badgeWell.push_back(b18);
    Badges b19("Underworld","Can freeze enemies", 5);
    badgeWell.push_back(b19);
    Badges b20("Wealthy","Noble and free", 4);
    badgeWell.push_back(b20);
}

//Generate the well of banners
void GameStart::generateBanners(){
    RaceBanners b1("Amazons","Ferocious",6);
    bannerWell.push_back(b1);
    RaceBanners b2("Dwarves","Common and disposable", 3);
    bannerWell.push_back(b2);
    RaceBanners b3("Elves","Graceful and wise", 6);
    bannerWell.push_back(b3);
    RaceBanners b4("Ghouls","Ferocious",5);
    bannerWell.push_back(b4);
    RaceBanners b5("Giants","Common and disposable", 6);
    bannerWell.push_back(b5);
    RaceBanners b6("Sorcerers","Graceful and wise", 5);
    bannerWell.push_back(b6);
    RaceBanners b7("Skeletons","Ferocious",6);
    bannerWell.push_back(b7);
    RaceBanners b8("Ratmen","Common and disposable", 8);
    bannerWell.push_back(b8);
    RaceBanners b9("Orcs","Graceful and wise", 5);
    bannerWell.push_back(b9);
    RaceBanners b10("Humans","Ferocious",5);
    bannerWell.push_back(b10);
    RaceBanners b11("Halflings","Common and disposable", 6);
    bannerWell.push_back(b11);
    RaceBanners b12("Tritons","Graceful and wise", 6);
    bannerWell.push_back(b12);
    RaceBanners b13("Trolls","Common and disposable", 5);
    bannerWell.push_back(b13);
    RaceBanners b14("Wizards","Graceful and wise", 5);
    bannerWell.push_back(b14);
}

void GameStart::generateRaces(){
    //Randomizer needs to be added here.
    
    Race r1(&badgeWell[0],&bannerWell[0]);
    raceDeck.push(r1);
    Race r2(&badgeWell[1],&bannerWell[1]);
    raceDeck.push(r2);
    Race r3(&badgeWell[2],&bannerWell[2]);
    raceDeck.push(r3);
    Race r4(&badgeWell[3],&bannerWell[3]);
    raceDeck.push(r4);
    Race r5(&badgeWell[4],&bannerWell[4]);
    raceDeck.push(r5);
    Race r6(&badgeWell[5],&bannerWell[5]);
    raceDeck.push(r6);
    Race r7(&badgeWell[6],&bannerWell[6]);
    raceDeck.push(r7);
    Race r8(&badgeWell[7],&bannerWell[7]);
    raceDeck.push(r8);
    Race r9(&badgeWell[8],&bannerWell[8]);
    raceDeck.push(r9);
    Race r10(&badgeWell[9],&bannerWell[9]);
    raceDeck.push(r10);
    Race r11(&badgeWell[10],&bannerWell[10]);
    raceDeck.push(r11);
    Race r12(&badgeWell[11],&bannerWell[11]);
    raceDeck.push(r12);
    Race r13(&badgeWell[12],&bannerWell[12]);
    raceDeck.push(r13);
    Race r14(&badgeWell[13],&bannerWell[13]);
    raceDeck.push(r14);
}

//Allows a player to pick a race/badge combo from 6 that are showing
void GameStart::pickRace(Player *p){
    cout << "\nAvailable Races" << endl;
    for (int i=0; i<6; i++){
        cout << i+1 << ". " << visibRaces[i].getName() << endl;
    }
    cout << "Which race do you choose? (1-6)" << endl;
    cin >> racePicker;
    while (racePicker > 6 || racePicker < 1){
        cout << "There are only 6 options. Please enter a number between 1 and 6." << endl;
        cin >> racePicker;
    }
    racePicker--;
    p->setRace(new Race(visibRaces[racePicker]));
    
    //Push back remaining races into deck and then draw 6.
    for (int i=5; i>racePicker; i--){
        raceDeck.push(visibRaces[i]);
    }
    for (int i=racePicker-1; i>-1; i--){
            raceDeck.push(visibRaces[i]);
    }
    for (int i=0; i<6; i++){
        visibRaces[i] = raceDeck.pop();
    }
}

//void GameStart::generateMap(){
////    Node n1("1");
////    Node n1a("2");
////    Node n1b("4");
////    n1.setNext(&n1a);
////    n1.getNext()->setNext(&n1b);
////    map.setNode(&n1);
//
//    Node n2("2");
//    Node n2a("1");
//    n2.setNext(&n2a);
//    //map.setNode(&n2);
//
//    Node n3("3");
//   // map.setNode(&n3);
//
//    Node n4("4");
//    Node n4a("1");
//    n4.setNext(&n4a);
//    //map.setNode(&n4);
//
////    Node n5(&regionWell[4]);
////    Node n6(&regionWell[5]);
////    Node n7(&regionWell[6]);
////    Node n8(&regionWell[7]);
////    Node n9(&regionWell[8]);
////    Node n10(&regionWell[9]);
//
//    regionWell[0].setLost(2);
//    regionWell[0].setMount(true);
//
//    regionWell[1].setLost(1);
//    regionWell[1].setMount(false);
//}

string GameStart::getName(){
    return mapName;
}

int GameStart::getPlayers(){
    return numPlayers;
}
