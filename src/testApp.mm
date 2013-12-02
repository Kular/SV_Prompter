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

    waveImg1.loadImage("wave_sheldon.png");
    waveImg2.loadImage("wave_taki.png");
    
    bisReady = false;
    bDetected = false;
    
//    reader.readTXT("sheldonScript.txt");
//    vector<string> tmpSentencs;
//    tmpSentencs = reader.getNewContents();
//    for (int i = 0; i < tmpSentencs.size(); i++) {
//        OnePair tmpPair;
//        tmpPair.setFont("kagami-pgoth-h.ttf");
//        tmpPair.setScriptAndTranslation(tmpSentencs.at(i), tmpSentencs.at(i));
//        sentencesReceived.push_back(tmpPair);
//    }
    
    count = 0;
    
    position = 1024;
    
    waveNo = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    
    // OSC stuffs
    while(receiver.hasWaitingMessages()){
        
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if (m.getAddress() == "/go"){
            if (scriptToShow.size() > 2) {
                scriptToShow.pop_front();
                count = 4;
            }
        } else if (m.getAddress() == "/playOrPause" && bisReady){
            if (m.getArgAsInt32(0) == 1) {
                bShoudSpeak = true;
            } else {
                bShoudSpeak = false;
            }
            
        } else if (m.getAddress() == "/detected") {
            if (m.getArgAsInt32(0) == 1) {
                bDetected = true;
            } else {
                bDetected = false;
            }
        } else if (m.getAddress() == "/distance") {
            wDis = m.getArgAsFloat(0);
            hDis = m.getArgAsFloat(1);
            
        } else if (m.getAddress() == "/time") {
            countDownRate = m.getArgAsFloat(0);
            
            countDown *= countDownRate;
            
        } else if (m.getAddress() == "/sentences") {
            
            OnePair tmpPair;
            tmpPair.setFont("kagami-pgoth-h.ttf");
            tmpPair.setScriptAndTranslation(m.getArgAsString(0), m.getArgAsString(1));
             std::cout<<"m.getArgAsString(0): "<<m.getArgAsString(0)<<" m.getArgAsString(1)"<<m.getArgAsString(1)<<endl;
            sentencesReceived.push_back(tmpPair);
            
            if (scriptToShow.size() < 4) {
                scriptToShow.push_back(sentencesReceived.at(0));
                sentencesReceived.pop_front();
//            } else if (!bisReady){
//                for (int i = 0; i < scriptToShow.size(); i++) {
//                    scriptToShow.at(i).setStatus(i);
//                }
//                bisReady = true;
//            }
            } else {
                bisReady = true;
            }
            
        } else if (m.getAddress() == "/position") {
            position = m.getArgAsFloat(0);
        } else if (m.getAddress() == "/wave") {
            waveNo = m.getArgAsInt32(0);
        }
        
    }
    // end OSC
    
    if (bisReady) {
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
                scriptToShow.at(i).update(40.0);
            }
            count--;
            
        }
        
        // when detected, show mouth width & height
        mouthPattern.update(wDis, hDis);
        
        // pink bar
        pinkBar.update(position);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (!bisReady) {
        waitLabel.drawString("中信通", 400, 400);
    } else {
        ofSetColor(255, 255, 255);
        for (int i = 0; i < scriptToShow.size(); i++) {
            scriptToShow.at(i).draw();
        }
        
        // wave form
        switch (waveNo) {
            case 0:
                waveImg1.draw(0, (IPAD_WIDTH - WAVE_WIDTH)/2, IPAD_HEIGHT, WAVE_WIDTH);
                break;
            case 1:
                waveImg2.draw(0, (IPAD_WIDTH - WAVE_WIDTH)/2, IPAD_HEIGHT, WAVE_WIDTH);
                break;
                
            default:
                break;
        }
        
        
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
        count = 40;
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

