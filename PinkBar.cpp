//
//  PinkBar.cpp
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#include "PinkBar.h"

PinkBar::PinkBar()
{
    pos.x = IPAD_HEIGHT;
    pos.y = (IPAD_WIDTH - WAVE_WIDTH)/2;
    
}

PinkBar::~PinkBar()
{
    
}

void PinkBar::update(float rate)
{
    if (rate == 0) {
        pos.x = IPAD_HEIGHT - 1;
    } else if (rate == 1){
        pos.x = 0;
    } else {
        pos.x = rate * IPAD_HEIGHT;
    }
}

void PinkBar::updateByTouch(float position)
{
    pos.x = position;
}

void PinkBar::draw()
{
    ofSetHexColor(0xff3287);
//    ofLine(pos.x, pos.y, pos.x, pos.y + WAVE_WIDTH);
    ofRect(pos.x, pos.y, 2, WAVE_WIDTH);
}