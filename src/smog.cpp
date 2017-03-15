//
//  smog.cpp
//  Midterm
//
//  Created by Zhao Hanyu on 8/03/2017.
//
//

#include "smog.hpp"


smog::smog(){

}

void smog::setup(){
    
   dim = ofRandom(1, 2.5);
    
    x = ofRandom(0,ofGetWidth());
    y = ofRandom(0,ofGetHeight());
    
    speedX = ofRandom(-1.0f,1.0f);
    speedY = ofRandom(-1.0f,1.0f);
    

    
    color.set(125,125,125,ofRandom(30,80));
    color2.set(20,20,20,ofRandom(30,80));


}

void smog::update(){
  

    if(x<0){
        x = 0;
        speedX *= -1;
    } else if (x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    
    
    }
    
    if (y < 0) {
        y = 0;
        speedY += -1;
    } else if (y  > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x += speedX;
    y += speedY;


}

void smog::draw(){
    
    
  
    ofSetColor(color);
     ofDrawCircle(x,y,dim);
    ofSetColor(color2);
     ofDrawCircle(x,y,dim);
    
     



}
