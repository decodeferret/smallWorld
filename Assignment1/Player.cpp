//
//  Player.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Player.hpp"

Player::Player(){
    coins.setValue(5);
    tokens.setRace("Default");
    currToken = 0;
    save = false;
    decorator[0] = 1;
    decorator[1] = 1;
    decorator[2] = 1;
}

Player::~Player(){
    
}
void Player::setRace(Race r){
    currRace = r;
    loadTokens();
}
void Player::setupDecor(){
    if (save == false){
        char temp;
        cout << "Edit decorator settings." << endl;
        cout << "Would you like to display percentage of regions owned by each player? (y/n)" << endl;
        cin >> temp;
        while (temp != 'y' && temp != 'n'){
            cout << "Only 'y' and 'n' are accepted." << endl;
            cin >> temp;
        }
        if (temp == 'y')
            decorator[0] = 1;
        else
            decorator[0] = 0;
        
        cout << "Would you like to display hands? (y/n)" << endl;
        cin >> temp;
        while (temp != 'y' && temp != 'n'){
            cout << "Only 'y' and 'n' are accepted." << endl;
            cin >> temp;
        }
        if (temp == 'y')
            decorator[1] = 1;
        else
            decorator[1] = 0;
        
        cout << "Would you like to display each players coins? (y/n)" << endl;
        cin >> temp;
        while (temp != 'y' && temp != 'n'){
            cout << "Only 'y' and 'n' are accepted." << endl;
            cin >> temp;
        }
        if (temp == 'y')
            decorator[2] = 1;
        else
            decorator[2] = 0;
        
        cout << "Would you like to save these settings? Saved settings can never be changed. (y/n)" << endl;
        cin >> temp;
        while (temp != 'y' && temp != 'n'){
            cout << "Only 'y' and 'n' are accepted." << endl;
            cin >> temp;
        }
        if (temp == 'y')
            save = true;
        else
            save = false;
    }
}
