//
//  boat.cpp
//  Midterm
//
//  Created by Zhao Hanyu on 13/03/2017.
//
//

#include "boat.hpp"
boat::boat(){
    catchUpSpeed = 0.01f;
}

//------------------------------------------------------------------
void boat::draw() {
    
    ofSetBackgroundAuto(false);

    boat1.load("image/boat.png");
    boat1.draw(pos.x, pos.y);
}

//------------------------------------------------------------------
void boat::zenoToPoint(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = 700;
}

