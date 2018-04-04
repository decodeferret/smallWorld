//
//  Observer.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-04-03.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Observer.hpp"

Observer::Observer(){
}

Observer::~Observer(){
    
}

void Observer::clearScreen(){
    for (int i=0;i<5;i++)
        cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
}


void Observer::generateScreen(int t, int player, int c){
    for (int i=0;i<5;i++)
        cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
    
    cout << "\n-----Turn " << t << "-----" << endl;
    if (c == 1)
        cout << "Player " << player << ": Conquer Phase" << endl;
    if (c == 2)
        cout << "Player " << player << ": Scores Coins" << endl;
    if (c == 0)
        cout << "Player " << player << ": Startup Phase" << endl;
    
}

//p is number of players
void Observer::domination(Map* m, int p, int show){
    //Iterates through region well to see which regions are owned by each player
    cout << "---------------------------" << endl;
    cout << "Small World Domination View" << endl;
    cout << "---------------------------" << endl;
    if (show == 1){
        for (int i=0; i<p; i++) {
            double temp = 0;
            for (int j=0; j<10; j++) {
                if (m->regionWell[j].getOwner() == (i+1)){
                    temp++;
                }
            }
            cout << "Player " << i+1 << " controls " << temp*10 << "% of board." << endl;
        }
        cout << "---------------------------" << endl;
    }
    for (int i=0; i<10; i++) {
        cout << "Region " << m->regionWell[i].getName() << " with " << m->regionWell[i].getPower() << " units.";
        if (m->regionWell[i].getOwner() != 0)
            cout << " Owner = [" << m->regionWell[i].getOwner() << "]";
        cout << endl;
    }
    cout << "---------------------------" << endl;
}
