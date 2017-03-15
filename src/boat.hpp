//
//  boat.hpp
//  Midterm
//
//  Created by Zhao Hanyu on 13/03/2017.
//
//

#ifndef boat_hpp
#define boat_hpp

#include <stdio.h>
#include "ofMain.h"

class boat {
    
public:
    
    boat();
    
    void	draw();
    void	zenoToPoint(float catchX, float catchY);
    
    ofPoint		pos;
    float		catchUpSpeed;
    
    ofImage boat1;
};

#endif /* boat_hpp */
