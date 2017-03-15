#include "ofApp.h"
#include "ofxJSON.h"

ofxJSONElement json;
ofxTextBlock        number;
ofxTextBlock        title;
ofFbo fbo;
//--------------------------------------------------------------


void ofApp::setup(){
    std::string url = "http://api.waqi.info/feed/shanghai/?token=8fa3befa510c5465dc1bf6f0ca69d33feecb1807";
    
    if (!response.open(url))
    {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON";
    }
    

        data = response["data"]["iaqi"]["pm25"]["v"].asInt();
        curLocation = response["data"]["city"]["name"].asString();
        smogdata = response["data"]["aqi"].asString();
        cout << "Set data epoch to : " << data << endl;
        cout << "Set curLocation epoch to: " << curLocation << endl;
        cout << "Set smog data epoch to: " << smogdata << endl;

        number.init("AvenirNext.ttc", 140);
        title.init("Avenir.ttc", 20);
    
    
    myboat.pos.x = ofRandom(0,ofGetWidth());
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetVerticalSync(true);
    
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
   
    for(int i=0; i<NSMOG02; i++){
        mySmog[i].setup();
        
    }

    for(int i=0; i<NSMOG01; i++){
        mySmog1[i].setup();
    
    }
    for(int i=0; i<NSMOG03; i++){
        mySmog3[i].setup();
    }
    
     //sound effect
    calm.load("neighborhood.aiff");
    noise.load("noise.wav");
    bird.load("bird.wav");
    
    if (150 > data && data > 101) {
        calm.setLoop(true);
        calm.setVolume(data*0.004f);
        noise.stop();
        bird.stop();
        calm.play();
        
    } else if ( data > 151) {
        noise.setLoop(true);
        noise.setVolume(data*0.006f);

        calm.stop();
        bird.stop();
        noise.play();
    }else if ( data < 100) {
        bird.setLoop(true);
        noise.stop();
        bird.setVolume(data*0.02f);

        calm.stop();
        bird.play();
    }

   
}


   



//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    
    for(int i=0; i<NSMOG02; i++){
        mySmog[i].update();
    }

    for(int i=0; i<NSMOG01; i++){
        mySmog1[i].update();
    }

    for(int i=0; i<NSMOG03; i++){
        mySmog3[i].update();
    }
    
    myboat.zenoToPoint(mouseX, mouseY);
    
    number.setText(smogdata);//
    title.setText(curLocation + " | PM 2.5");//

    
  

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int x_pos = (ofGetWidth() - niceB.getWidth())/2.0;//shanghai bad pm2.5
    int y_pos = (ofGetHeight() - niceB.getHeight())/2.0 - 17;
    
    int x_pos2 = (ofGetWidth() - niceS.getWidth())/2.0;
    int y_pos2 = (ofGetHeight() - niceS.getHeight())/2.0- 17;
    
    int x_pos3 = (ofGetWidth() - river.getWidth())/2.0;//river
    int y_pos3 = (ofGetHeight() - river.getHeight())/2.0;
    
    if( 150 > data && data > 101){
        glBegin(GL_QUADS);//background gradient
        glColor3f( 0.807f, 0.935f, 0.902f);
        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( ofGetWidth(), 0.0f, 0.0f );
        glColor3f( 0.757f, 0.778f, 1.0f );
        glVertex3f( ofGetWidth(), ofGetHeight(), 0.0f );
        glVertex3f( 0.0f, ofGetHeight(), 0.0f );
        glEnd();
        
       
        ofSetCircleResolution(60);//sun
        ofSetColor(250, 238, 210,255);
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2 - 70, 250);
        
        ofSetColor(255, 255, 255,255);
        niceB.load("image/shanghaiS.png");//shanghai
        niceB.draw(x_pos, y_pos);
        
        
        
        
        
        
        for(int i=0; i<NSMOG02; i++){
            ofSetColor(255,255,255,200);
            mySmog[i].draw();
            
        }
       
        
        ofSetBackgroundAuto(false);
        river.load("image/river.png");
        river.setAnchorPoint(0.5f, 0.5f);
        int deltaX = ofMap(mouseX, 0, ofGetWidth(),180, 255);
        ofSetColor(180,180,180, deltaX);
        river.draw(x_pos3, y_pos3-130);
        
        fbo.begin();
        ofSetColor(200,200,200,100);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

        
        ofSetColor(200,200,200);
        myboat.draw();
        
        fbo.end();
        
        ofSetColor(255,255,255);
        fbo.draw(0,0);
        
        

        
        number.setColor(255, 246, 16,255);
        title.setColor(160, 160, 160,255);
        number.drawCenter(ofGetWidth()/2,120);
        title.drawCenter(ofGetWidth()/2,170);

        
    
      
        
    }
    else if(data < 100){

        glBegin(GL_QUADS);//background gradient
        glColor3f( 0.357f, 0.749f, 1.0f);
        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( ofGetWidth(), 0.0f, 0.0f );
        glColor3f( 0.518f, 0.886f, 0.965f );
        glVertex3f( ofGetWidth(), ofGetHeight(), 0.0f );
        glVertex3f( 0.0f, ofGetHeight(), 0.0f );
        glEnd();
        
        ofSetCircleResolution(60);//sun
        ofSetColor(250, 255, 118,255);
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2 - 70, 250);
        
        
        ofSetColor(255, 255, 255,255);
        niceS.load("image/ShanghaiM.png");//shanghai
        niceS.draw(x_pos2, y_pos2);
        
        
        ofSetBackgroundAuto(false);
        river.load("image/river.png");
        river.setAnchorPoint(0.5f, 0.5f);
        int deltaX = ofMap(mouseX, 0, ofGetWidth(), 150, 250);
        ofSetColor(255,255,255, deltaX);
        river.draw(x_pos3, y_pos3-130);
        
        
        
        fbo.begin();
        ofSetColor(255,255,255,100);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        

        ofSetColor(255,255,255);
        myboat.draw();
        
        fbo.end();
        
        ofSetColor(255,255,255);
        fbo.draw(0,0);
        
        

        
        number.setColor(0, 162, 212,255);
        title.setColor(0, 162, 255,255);
        number.drawCenter(ofGetWidth()/2,120);
        title.drawCenter(ofGetWidth()/2,170);

        
        for(int i=0; i<NSMOG01; i++){
            mySmog1[i].draw();
            
            
            }
//
    
    }else if( data > 151){
        
        
        glBegin(GL_QUADS);//background gradient
        glColor3f( 0.284f, 0.284f, 0.284f);
        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( ofGetWidth(), 0.0f, 0.0f );
        glColor3f( 0.9f, 0.9f, 0.9f );
        glVertex3f( ofGetWidth(), ofGetHeight(), 0.0f );
        glVertex3f( 0.0f, ofGetHeight(), 0.0f );
        glEnd();
        
        ofSetCircleResolution(60);//sun
        ofSetColor(194, 194, 194,255);
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2 - 70, 250);
        
        
        ofSetColor(255, 255, 255,255);
        niceS.load("image/ShanghaiB.png");//shanghai
        niceS.draw(x_pos2, y_pos2);
        
        
        ofSetBackgroundAuto(false);
        river.load("image/river.png");
        river.setAnchorPoint(0.5f, 0.5f);
        int deltaX = ofMap(mouseX, 0, ofGetWidth(), 100, 200);
        ofSetColor(60,60,60, deltaX);
        river.draw(x_pos3, y_pos3-130);
        
        
        fbo.begin();
        ofSetColor(150,150,150,200);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        

        ofSetColor(100,100,100);
        myboat.draw();
        
        fbo.end();
        
        ofSetColor(255,255,255);
        fbo.draw(0,0);
        

        number.setColor(207, 52, 55,255);
        title.setColor(10, 10, 10,255);
        number.drawCenter(ofGetWidth()/2,120);
        title.drawCenter(ofGetWidth()/2,170);
        
        
        for(int i=0; i<NSMOG03; i++){
            mySmog3[i].draw();
            
        }
        
    
        
        
    }
    
    


    
   
    
    


    }




//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == '1'){
        data = 50;
        
        smogdata = "50";
        
        noise.stop();
        calm.stop();
        bird.play();
        bird.setVolume(data*0.02f);

        
        
        

        
        cout << "Current somg data is: " << smogdata << endl;}
    
    
    if (key == '2'){

        data = 120;

        smogdata = "120";
        
        noise.stop();
        bird.stop();
        calm.play();
        calm.setVolume(data*0.004f);

        cout << "Current somg data is: " << smogdata << endl;}

    
    if (key == '3'){
        data = 152;
        smogdata = "152";
        
        noise.setLoop(true);
        calm.stop();
        bird.stop();
        noise.setVolume(data*0.006f);
        noise.play();

        cout << "Current somg data is: " << smogdata << endl;}
   
    if (key == '4'){
        data = response["data"]["iaqi"]["pm25"]["v"].asInt();
        smogdata = response["data"]["aqi"].asString();
        
        if (150 > data && data > 101) {
            calm.setLoop(true);
            calm.setVolume(data*0.004f);
            noise.stop();
            bird.stop();
            calm.play();
            
        } else if ( data > 151) {
            noise.setLoop(true);
            calm.stop();
            bird.stop();
            noise.setVolume(data*0.006f);
            noise.play();
            
        }else if ( data < 100) {
            bird.setLoop(true);
            bird.setVolume(data*0.02f);
            noise.stop();
            calm.stop();
            bird.play();
            
            
        }

        cout << "Current somg data is: " << smogdata << endl;}


    }





//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
