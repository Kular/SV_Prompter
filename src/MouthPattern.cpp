//
//  MouthPattern.cpp
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#include "MouthPattern.h"

MouthPattern::MouthPattern()
{
    mouthHeightBar.setDistanceBar(isHeightBar, 100, 500, 0);
    mouthWidthBar.setDistanceBar(isWidthBar, 100, 500, 0);
}

MouthPattern::~MouthPattern()
{
    
}


void MouthPattern::update(float wDistance, float hDistance)
{
    mouthWidthBar.update(wDistance);
    mouthHeightBar.update(hDistance);
}

void MouthPattern::draw()
{
    mouthHeightBar.drawBar();
    mouthWidthBar.drawBar();
    
    ofSetColor(255, 255, 255);
    ofLine(mouthWidthBar.getPosAlfa(), mouthHeightBar.getPosAlfa());
    ofLine(mouthHeightBar.getPosAlfa(), mouthWidthBar.getPosBeta());
    ofLine(mouthWidthBar.getPosBeta(), mouthHeightBar.getPosBeta());
    ofLine(mouthHeightBar.getPosBeta(), mouthWidthBar.getPosAlfa());
}

