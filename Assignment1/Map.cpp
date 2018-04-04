//
//  Map.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-27.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Map.hpp"

Map::Map(){
    for (int i=0; i<22; i++){
        for (int j=0; j<22; j++){
            adjMap[i][j] = false;
        }
    }
    
    adjMap[1][2] = true;
    adjMap[1][4] = true;
    adjMap[1][5] = true;
    adjMap[2][3] = true;
    adjMap[2][4] = true;
    adjMap[4][5] = true;
    adjMap[5][7] = true;
    
    for (int i=0; i<22; i++){
        for (int j=0; j<22; j++){
            if (adjMap[i][j] == true)
                adjMap[j][i] = true;
        }
    }
}
Map::~Map(){
    
}
void Map::conquer(int n, Player* p, Region* r){
    //Look through map to find all regions owned by p
    
    if (p->getTokens() > r->getPower()){
        int soldiers;
        cout << "How many soldiers would you like to move?" << endl;
        cin >> soldiers;
        while (soldiers < 2||soldiers > p->getTokens()){
            cout << "Inelligible choice, please choose again." << endl;
            cin >> soldiers;
        }
        p->setTokens(soldiers);
        r->setOwner(++n, soldiers);
        cout << "You have " << p->getTokens() << " tokens remaining." << endl;
    }
}

//Shows all adjacent regions to a region i
void Map::showAdj(int i){
    for (int j=0; j<22; j++) {
        if (adjMap[i][j] == true)
            cout << j << "   " << endl;
    }
}

void Map::generateRegions(){
    regionWell.push_back(Region("1", 2));
    regionWell.push_back(Region("2", 1));
    regionWell.push_back(Region("3"));
    regionWell.push_back(Region("4", 3));
    regionWell.push_back(Region("5"));
    regionWell.push_back(Region("6"));
    regionWell.push_back(Region("7", 2));
    regionWell.push_back(Region("8"));
    regionWell.push_back(Region("9"));
    regionWell.push_back(Region("10"));
}

