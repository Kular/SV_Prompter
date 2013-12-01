#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	//If you want a landscape oreintation
	iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
	
	ofBackground(0 ,0, 0);
    
    ofEnableAlphaBlending();
    
    receiver.setup(PORT);
    
    okLabel.loadFont("kagami-pgoth-h.ttf", 30);
    waitLabel.loadFont("kagami-pgoth-h.ttf", 60);

    waveImg.loadImage("wave.png");
    
    bisReady = true;
    bDetected = false;
    
    reader.readTXT("sheldonScript.txt");
    vector<string> tmpSentencs;
    tmpSentencs = reader.getContents();
    for (int i = 0; i < tmpSentencs.size(); i++) {
        OnePair tmpPair;
        tmpPair.setFont("kagami-pgoth-h.ttf");
        tmpPair.setScriptAndTranslation(tmpSentencs.at(i), tmpSentencs.at(i));
        sentencesReceived.push_back(tmpPair);
    }
    
    count = 0;
    
    position = 1024;
    
}

//--------------------------------------------------------------
void testApp::update(){

    if (scriptToShow.size() < 4) {
        if (sentencesReceived.size() > 0) {
            scriptToShow.push_back(sentencesReceived.at(0));
            sentencesReceived.pop_front();
        } else {
            for (int i = 0; i < scriptToShow.size(); i++) {
                scriptToShow.at(i).setStatus(i);
            }
        }
    } else {
        for (int i = 0; i < scriptToShow.size(); i++) {
            scriptToShow.at(i).setStatus(i);
        }
    }
    
    if (count > 0) {
        
        for (int i = 0; i < scriptToShow.size(); i++) {
            scriptToShow.at(i).update(4);
        }
        count--;

    }
    
    // when detected, show mouth width & height
    mouthPattern.update(wDis, hDis);
    
    // pink bar
    pinkBar.updateByTouch(position);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofCircle(0, IPAD_WIDTH, 100);

    if (!bisReady) {
        waitLabel.drawString("中信通", 400, 400);
    } else {
        
        for (int i = 0; i < scriptToShow.size(); i++) {
            scriptToShow.at(i).draw();
        }
        
        // wave form
        waveImg.draw(0, (IPAD_WIDTH - WAVE_WIDTH)/2, IPAD_HEIGHT, WAVE_WIDTH);
        
        // pink bar
        pinkBar.draw();
        
        // mouth
        if (bDetected) {
            mouthPattern.draw();
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    position = touch.x;
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
    if (scriptToShow.size() > 2 && count == 0) {
        scriptToShow.pop_front();
        count = 4;
    }
    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){
//    bisReady = !bisReady;
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}

