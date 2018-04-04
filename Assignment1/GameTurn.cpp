//
//  GameTurn.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-03-25.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "GameTurn.hpp"

GameTurn::GameTurn(){
    turn = 0;
}
GameTurn::~GameTurn(){
    
}

//Returns true if game is over, false otherwise.
bool GameTurn::nextTurn(){
    turn++;
    if (turn == limit) {
        cout << "\n-----Last turn complete, game is over!-----" << endl;
        return true;
    }
    cout << "\n-----Turn " << turn << "-----" << endl;
    return false;
}

//Sets the turn limit based on the number of players.
void GameTurn::setLimit(int l){
    if (l == 2){
        limit = 10;
    }
    if (l == 3 || l == 4){
        limit = 9;
    }
    if (l == 5){
        limit = 8;
    }
}
