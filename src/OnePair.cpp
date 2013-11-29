//
//  OnePair.cpp
//  SV_Prompter
//
//  Created by Kular on 11/27/13.
//
//

#include "OnePair.h"
#include "ofxTrueTypeFontUC.h"

ofxTrueTypeFontUC font;

OnePair::OnePair()
{
    r = g = b = 255;
    alpha = 255;
    status = outOfScreen;
}

OnePair::~OnePair()
{
    
}

void OnePair::setFont(string fontName)
{
    font.loadFont(fontName, 40);
}

void OnePair::setScriptAndTranslation(string aSentence, string aTranslation)
{
    words1 = aSentence;
    rect1 = font.getStringBoundingBox(aSentence, 0, 0);
    pos1.x = (IPAD_HEIGHT - rect1.width) / 2.f;
    pos1.y = IPAD_WIDTH; // set for status: outOfScreen
    
    words2 = aTranslation;
    rect1 = font.getStringBoundingBox(aTranslation, 0, 0);
    pos1.x = (IPAD_HEIGHT - rect2.width) / 2.f;
    pos1.y = pos1.y + rect1.height; // set for status: outOfScreen
    
    
}

void OnePair::setStatus(int theStatus)
{
    switch (theStatus) {
        case 1:
            ;
            break;
            
        default:
            break;
    }
}
