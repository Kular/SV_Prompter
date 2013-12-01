//
//  ScriptReader.h
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#ifndef __SVPrompter__ScriptReader__
#define __SVPrompter__ScriptReader__

#include <iostream>

#include "ofMain.h"

#endif /* defined(__SmartVoicePrompter__ScriptReader__) */

class ScriptReader {
    
public:
    
    ScriptReader();
    virtual ~ScriptReader();
    
    void readTXT(string url);
    
    vector<string> getContents();
    
private:
    
    ofBuffer buffer;
    
    vector<string> lines;
};