//
//  MapLoader.cpp
//  SmallWorld
//
//  Created by Charles  Chan on 2018-02-16.
//  Copyright © 2018 Charles Chan. All rights reserved.
//

#include "MapLoader.hpp"
#include <vector>
#include <sstream>
#include <stdlib.h>


MapLoader::MapLoader(){
    map = new Map();
}
MapLoader::~MapLoader(){
    delete map;
    map = nullptr;
}
bool MapLoader::readFile(string s){
//    ofstream myfile (s);
//    if (myfile.is_open()){
//        myfile << "This is a world.\n";
//        myfile << "The world is " + s + ".\n";
//        myfile.close();
//    }
//    else cout << "Unable to open file";
    
    ifstream map (s);
    
    string line;
    
    if (map.is_open())
    {
        while ( getline (map,line) )
        {
            cout << line << '\n';
        }
        map.close();
        return true;
    }
    
    else {
        //cout << "Unable to open file. MapLoader error \n";
        return false;
    }
}
