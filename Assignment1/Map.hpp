//
//  Map.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-27.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <iostream>
#include "Node.hpp"
#include <vector>
#include "Player.hpp"

using namespace std;

class Map {
private:
    //Replace the AllComponents BS
    //vector<Node*> adjList;
    bool adjMap[22][22];
public:
    Map();
    Map(int i); //Map based off of number of players
    ~Map();
    
    vector<Region> regionWell;
    void generateRegions();
    
//    void setNode(Node* n1){adjList.push_back(n1);}
//    Node* getNode(int i){return adjList[i];}
//    
//    int size(){return (int)adjList.size();}
    
    //To be made
    void conquer(int n, Player* p, Region* r);
    void score();
    
    void showAdj(int i);
};

#endif /* Map_hpp */
