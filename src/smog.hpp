//
//  smog.hpp
//  Midterm
//
//  Created by Zhao Hanyu on 8/03/2017.
//
//

#ifndef smog_hpp
#define smog_hpp

#include <stdio.h>
#include "ofMain.h"
class smog{
    
   public:
    
    void setup();
    void update();
    void draw();
    float x;
    float y;
    float speedY;
    float speedX;
    float dim;
    ofColor color, color2;
    smog();
    
private:
    


};

#endif /* smog_hpp */
