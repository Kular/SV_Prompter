//
//  DistanceBar.cpp
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#include "DistanceBar.h"

DistanceBar::DistanceBar()
{
    
}

void DistanceBar::setDistanceBar(HeightOrWidth heightBarOrWidthBar, int x, int y, float distance)
{
    posCenter.x = x;
    posCenter.y = y;
    
    heightOrWidth = heightBarOrWidthBar;
    
    switch (heightBarOrWidthBar) {
            
        case isHeightBar: {
            
            posAlfa.x = x;
            posBeta.x = x;
            
            posAlfa.y = y - distance/2;
            posBeta.y = y + distance/2;
            
        } break;
            
        case isWidthBar: {
            
            posAlfa.y = y;
            posBeta.y = y;
            
            posAlfa.x = x - distance/2;
            posBeta.x = x + distance/2;
            
        } break;
            
        default:
            break;
    }
}

DistanceBar::~DistanceBar()
{
    //    std::cout<<"DistanceBar destructed."<<std::endl;
}

void DistanceBar::drawBar()
{
    switch (heightOrWidth) {
            
        case isHeightBar: {
            
            ofSetColor(0, 204, 102);
            
        } break;
            
        case isWidthBar: {
            
            ofSetColor(51, 102, 204);
            
        } break;
        default:
            break;
    }
    
    ofCircle(posAlfa, 3);
    ofCircle(posBeta, 3);
    
    ofLine(posAlfa, posBeta);
}

void DistanceBar::update(float distance)
{
    switch (heightOrWidth) {
        case isHeightBar: {
            posAlfa.y = posCenter.y - distance/2;
            posBeta.y = posCenter.y + distance/2;
        } break;
        case isWidthBar: {
            posAlfa.x = posCenter.x - distance/2;
            posBeta.x = posCenter.x + distance/2;
        }
        default:
            break;
    }
    
}

ofVec2f DistanceBar::getPosAlfa()
{
    return posAlfa;
}

ofVec2f DistanceBar::getPosBeta()
{
    return posBeta;
}
