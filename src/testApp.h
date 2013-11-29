#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

#include "ofxOsc.h"
#include "ofxTrueTypeFontUC.h"

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
    ofxOscReceiver *receiver;
    
    int count;
    
    bool bOpen, bShoudSpeak;
    int countDown;
    float countDownRate;
    
    bool bDetected;
    
    ofxTrueTypeFontUC okLabel, waitLabel;
    
    float wDis, hDis;
    
    bool bisReady;

    ofImage waveImg;
};


