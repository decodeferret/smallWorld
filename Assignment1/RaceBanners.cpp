//
//  RaceBanners.cpp
//  Assignment1
//
//  Created by Marco Sassano on 2018-02-23.
//  Copyright © 2018 Marco Sassano. All rights reserved.
//

#include "RaceBanners.hpp"

RaceBanners::RaceBanners(){
    tokens = 7;
}

RaceBanners::RaceBanners(string r, string s, int t){
    race = r;
    skill = s;
    tokens = t;
}

RaceBanners::~RaceBanners(){
    
}
