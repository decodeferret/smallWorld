//
//  GameTurn.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-03-25.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef GameTurn_hpp
#define GameTurn_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class GameTurn {
private:
    int turn;
    int limit;
public:
    GameTurn();
    ~GameTurn();
    
    int getTurn(){return turn;}
    bool nextTurn();
    
    int getLimit(){return limit;}
    void setLimit(int l);
};

#endif /* GameTurn_hpp */
