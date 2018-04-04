//
//  GamePieces.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef GamePieces_hpp
#define GamePieces_hpp

#include <string>
#include <stdio.h>

using namespace std;

class GamePieces{
private:
    string type;
public:
    GamePieces();
    ~GamePieces();
    
    GamePieces(string s);
    
    string getType(){return type;}
    void setType(string t){type = t;}
};

#endif /* GamePieces_hpp */
