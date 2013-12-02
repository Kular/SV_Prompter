#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

#include "ofxOsc.h"
#include "ofxTrueTypeFontUC.h"

#include "OnePair.h"
#include "ScriptReader.h"
#include "MouthPattern.h"
#include "PinkBar.h"

#define PORT 8000

class testApp : public ofxiPhoneApp{
	
public:
    void setup();
    void update();
    void draw();
    void exit();

    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch);
    void touchCancelled(ofTouchEventArgs & touch);

    void lostFocus();
    void gotFocus();
    void gotMemoryWarning();
    void deviceOrientationChanged(int newOrientation);
  
private:
    ofxOscReceiver receiver;
    
    int count;
    
    bool bOpen, bShoudSpeak;
    int countDown;
    float countDownRate;
    
    ofxTrueTypeFontUC okLabel, waitLabel;

    
    bool bisReady;

    ofImage waveImg1, waveImg2;
    int waveNo;
    
    
    deque<OnePair>scriptToShow;
    deque<OnePair>sentencesReceived;
    
    ScriptReader reader;
    
    MouthPattern mouthPattern;
    float wDis, hDis;
    bool bDetected;
    
    PinkBar pinkBar;
    float position;
};


