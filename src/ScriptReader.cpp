//
//  ScriptReader.cpp
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#include "ScriptReader.h"

ScriptReader::ScriptReader()
{
    
}

ScriptReader::~ScriptReader()
{
    std::cout<<"Read!"<<endl;
}

void ScriptReader::readTXT(string url)
{
    ofFile file;
    
    file.open(ofToDataPath(url), ofFile::ReadOnly, false);
    
    buffer = file.readToBuffer();
    
    while(!buffer.isLastLine()){
        
        lines.push_back(buffer.getNextLine());
        
    }
    
}


vector<string> ScriptReader::getContents()
{
    return lines;
}