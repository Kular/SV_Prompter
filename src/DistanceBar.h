//
//  DistanceBar.h
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#ifndef __SVPrompter__DistanceBar__
#define __SVPrompter__DistanceBar__

#include <iostream>
#include "ofMain.h"
#endif /* defined(__ofApp__HeightBar__) */

typedef enum{
    isHeightBar,
    isWidthBar
}HeightOrWidth;

class DistanceBar {
public:
    
    DistanceBar();
    virtual ~DistanceBar();
    
    void setDistanceBar(HeightOrWidth heightBarOrWidthBar, int x, int y, float distance);
    
    void update(float distance);
    void drawBar();
    
    ofVec2f getPosAlfa();
    ofVec2f getPosBeta();
    
private:
    
    ofVec2f posAlfa;
    ofVec2f posBeta;
    ofVec2f posCenter;
    
    HeightOrWidth heightOrWidth;
    
};