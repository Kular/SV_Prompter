//
//  OnePair.cpp
//  SV_Prompter
//
//  Created by Kular on 11/27/13.
//
//

#include "OnePair.h"
#include "ofxTrueTypeFontUC.h"

#define COMMON_MARGIN 50
#define MARGIN_BETWEEN 15
#define WAVE_Y 300
#define PAIR_HEIGHT 200

#define Y_OUTOFSCREEN 768
#define Y_READYTOSHOW (IPAD_WIDTH - WAVE_WIDTH)/2 + WAVE_WIDTH
#define Y_SHOWING 0
#define Y_AFTERSHOWN -200



ofxTrueTypeFontUC fontForScript;
ofxTrueTypeFontUC fontForTranslation;

OnePair::OnePair()
{
    r = g = b = 255;
    alpha = 255;
    status = outOfScreen;
}

OnePair::~OnePair()
{
    
}

float OnePair::getBaseY()
{
    return baseY;
}

void OnePair::setFont(string fontName)
{
    fontForScript.loadFont(fontName, 40);
    fontForTranslation.loadFont(fontName, 30);
}

void OnePair::setScriptAndTranslation(string aSentence, string aTranslation)
{
    script = aSentence;
    rectOfScript = fontForScript.getStringBoundingBox(aSentence, 0, 0);
    posOfScript.x = (IPAD_HEIGHT - rectOfScript.width) / 2.f;
    
    
    translation = aTranslation;
    rectOfTranslation = fontForTranslation.getStringBoundingBox(aTranslation, 0, 0);
    posOfTranslation.x = (IPAD_HEIGHT - rectOfTranslation.width) / 2.f;
    
    
    setBaseY(IPAD_WIDTH);
}

void OnePair::setBaseY(float y)
{
    baseY = y;
    posOfScript.y = baseY + COMMON_MARGIN + rectOfScript.height; // set for status: outOfScreen
    posOfTranslation.y = posOfScript.y + MARGIN_BETWEEN +  rectOfTranslation.height; // set for status: outOfScreen
}


void OnePair::setStatus(int theStatus)
{
    switch (theStatus) {
            
        case 3: {
            status = outOfScreen;
            setBaseY(IPAD_HEIGHT);
        } break;
            
        case 2: {
            status = readyToShow;
            setBaseY((IPAD_WIDTH - WAVE_WIDTH)/2 + WAVE_WIDTH);
        } break;
            
        case 1: {
            status = showing;
            setBaseY(0);
        } break;
            
        case 0: {
            status = afterShown;
            setBaseY(0 - PAIR_HEIGHT);
        } break;
            
        default:
        break;
    }
}

void OnePair::nextStatus()
{
    switch (status) {
        case outOfScreen:
            status = readyToShow;
            break;
        case readyToShow:
            status = showing;
            break;
        case showing:
            status = afterShown;
            break;
            
        default:
            break;
    }
}

void OnePair::update(float x)
{
    float y;
    switch (status) {
        case outOfScreen:
            y = Y_OUTOFSCREEN;
            break;
        case readyToShow: {
            y = Y_READYTOSHOW;
        }
            break;
        case showing:
            y = Y_SHOWING;
            break;
            
        default:
            y = Y_AFTERSHOWN;
            break;
    }

//    switch (status) {
//        case outOfScreen: {
//            y -= (baseY - (IPAD_WIDTH - WAVE_WIDTH)/2 + WAVE_WIDTH) / x;
//            setBaseY(y);
//        } break;
//        case readyToShow: {
//            y -= (baseY - 0) / x;
//            std::cout<<"y: "<<y<<endl;
//            setBaseY(y);
//        } break;
//        case showing: {
//            y -= (baseY - (0 - PAIR_HEIGHT)) / x;
//            setBaseY(y);
//        } break;
//        default: {
//            // after shown
//        } break;
//    }

    switch (status) {
        case outOfScreen: {
            y -= (Y_OUTOFSCREEN - Y_READYTOSHOW) / x;
            setBaseY(y);
        } break;
        case readyToShow: {
            y -= (Y_READYTOSHOW - Y_SHOWING) / x;
            std::cout<<"=>"<<(Y_READYTOSHOW - Y_SHOWING) / x<<endl;
            std::cout<<"y: "<<y<<endl;
            setBaseY(y);
        } break;
        case showing: {
            y -= (Y_SHOWING - Y_AFTERSHOWN) / x;
            setBaseY(y);
        } break;
        default: {
            // after shown
        } break;
    }
    
    
}

void OnePair::draw()
{
    ofSetColor(r, g, b, alpha);
    fontForScript.drawString(script, posOfScript.x, posOfScript.y);
    fontForTranslation.drawString(translation, posOfTranslation.x, posOfTranslation.y);
}
