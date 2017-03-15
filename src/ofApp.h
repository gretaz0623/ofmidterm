#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxTextSuite.h"
#include "smog.hpp"
#include "boat.hpp"

#define NSMOG03 5000
#define NSMOG02 1000
#define NSMOG01 100

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxJSONElement response;
        ofSoundPlayer player;
		void urlResponse(ofHttpResponse & response);
        int data;
        string smogdata;
        string curLocation;
    
        ofSoundPlayer noise, calm, bird;

          
        ofImage niceB;
        ofImage river;
        ofImage niceS;
    
        smog mySmog[NSMOG02];
        smog mySmog1[NSMOG01];
        smog mySmog3[NSMOG03];
        boat myboat;
};
