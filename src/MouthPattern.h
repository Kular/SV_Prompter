//
//  MouthPattern.h
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#ifndef __SVPrompter__MouthPattern__
#define __SVPrompter__MouthPattern__

#include <iostream>
#include "ofMain.h"
#include "DistanceBar.h"

#endif /* defined(__SmartVoice__MouthPattern__) */

class MouthPattern {
    
public:
    MouthPattern();
    virtual ~MouthPattern();
    
    void draw();
    void update(float wDistance, float hDistance);
    
    
private:
    DistanceBar mouthHeightBar;
    DistanceBar mouthWidthBar;
    
};