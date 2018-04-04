//
//  Tokens.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Tokens.hpp"

Tokens::Tokens(){
    race = "Blank";
}
Tokens::Tokens(string r){
    race = r;
}
Tokens::~Tokens(){
    //cout << "tokens done" << endl;
}
