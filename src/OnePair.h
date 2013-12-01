//
//  OnePair.h
//  SV_Prompter
//
//  Created by Kular on 11/27/13.
//
//

#ifndef __SV_Prompter__OnePair__
#define __SV_Prompter__OnePair__

#include <iostream>
#include "ofMain.h"
#endif /* defined(__SV_Prompter__OnePair__) */

typedef enum {
    outOfScreen,
    readyToShow,
    showing,
    afterShown
}statusType;

class OnePair {
    
public:
    
    OnePair();
    ~OnePair();
    
    void update(float x);
    void draw();
    
    void setScriptAndTranslation(string aSentence, string aTranslation);
    
    void setStatus(int theStatus);
    
    void setFont(string fontName);

    float getBaseY();
    
    void nextStatus();
    void setBaseY(float y);

private:

    int r, g, b, alpha;

    string script;
    string translation;
    
    float baseY;

    ofVec2f posOfScript;
    ofVec2f posOfTranslation;

    ofRectangle rectOfScript;
    ofRectangle rectOfTranslation;

    statusType status;

};