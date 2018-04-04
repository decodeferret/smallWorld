//
//  Node.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-27.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "Node.hpp"

Node::Node(){
    region = "";
}
Node::Node(string r){
    region = r;
    next = NULL;
}
Node::~Node(){
    
}
void Node::print(){
        //cout << "Damn son" << endl;
        cout << getRegion() << endl;
    if (hasNext) {
        cout << "Booya!" << endl;
        next->print();
    }
}
