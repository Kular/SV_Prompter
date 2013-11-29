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
    
    void update();
    void setScriptAndTranslation(string aSentence, string aTranslation);
    
    void draw();
    void setStatus(int theStatus);
    
    void setFont(string fontName);

    ofVec2f getPos();

private:

    int r, g, b, alpha;

    string words1;
    string words2;

    ofVec2f pos1;
    ofVec2f pos2;

    ofRectangle rect1;
    ofRectangle rect2;

    statusType status;

};