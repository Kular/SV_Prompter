//
//  PinkBar.h
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#ifndef __SVPrompter__PinkBar__
#define __SVPrompter__PinkBar__

#include <iostream>
#include "ofMain.h"
#endif /* defined(__SVPrompter__PinkBar__) */

class PinkBar {
    ofVec2f pos;
public:
    PinkBar();
    ~PinkBar();
    void update(float rate);
    void draw();
    void updateByTouch(float position);
    
};