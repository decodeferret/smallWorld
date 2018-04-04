//
//  Node.hpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-27.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Region.hpp"
#include <string>
#include <iostream>

using namespace std;

class Node {
private:
    string region;
    Node* next = NULL;
    bool hasNext = false;
public:
    Node();
    Node(string r);
    ~Node();
    Node* getNext() {return next;}
    void setNext(Node* n){next = n; hasNext = true;}
    
    string getRegion() {return region;}
    void setRegion(string r) {region = r;}
    
    void print();
};

#endif /* Node_hpp */
