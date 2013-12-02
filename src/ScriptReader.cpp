//
//  ScriptReader.cpp
//  SVPrompter
//
//  Created by Kular on 12/1/13.
//
//

#include "ScriptReader.h"
#include "string.h"

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

void ScriptReader::readTXTWithoutReturn(string url)
{
    ofFile file;
    
    file.open(ofToDataPath(url), ofFile::ReadWrite, false);
    
    buffer = file.readToBuffer();
    
    string theText = buffer.getText();
    
    std::cout<<"text: "<<theText<<endl;
    
    for (int i = 1; i < theText.size(); i++) {
        if (theText[i] == ' ') {
            if (theText[i-1] == ',' || theText[i-1] == '.') {
                theText[i] = '\n';
            }
        }
    }
    
    std::cout<<"text: "<<theText<<endl;
    
    ofBuffer newBuffer;
    
    newBuffer.set(theText.c_str(), theText.size());
    
    int k = 0;
    while(!newBuffer.isLastLine()){
        k++;
        std::cout<<"k = "<<k<<endl;
        newBuffer.getNextLine();
    }
    
    
    std::cout<<"ofToDataPath(url): "<<ofToDataPath(url)<<endl;
    bool filewritten = ofBufferToFile(ofToDataPath(url), newBuffer);
    std::cout<<"Written? "<<(filewritten?"Yes":"No")<<endl;
}

int SJISMultiCheck(unsigned char c){ //漢字にしか適用しない！
    if(((c>=0x81)&&(c<=0x9f))||((c>=0xe0)&&(c<=0xfc)))return 1;
    else return 0;
}

vector<string> ScriptReader::getNewContents()
{
    for (int i = 0; i < lines.size(); i++) {
        string aLine = lines.at(i);
        string reverseLine(aLine.size(), '|');
        
        for (int j = 0; j < aLine.size();) {
            char tmp;
            tmp = aLine.at(j);
            
            if (SJISMultiCheck(tmp)) { // 全角の最初の１バイトを見つけた場合
                /* SJISMultiCheck()は漢字にしか適用しないから、破棄
                if ((j + 2) < aLine.size()) {
                    std::cout<<"オーバーしていない"<<endl;
                    //　最低でも２バイトだから、３バイトのやつであるかどうかをチェック
                    if (SJISMultiCheck(aLine.at(j + 2))) {
                        std::cout<<"第1バイト: "<<aLine.at(j)<<endl;
                        std::cout<<"第2バイト: "<<aLine.at(j + 1)<<endl;
                        std::cout<<"第3バイト: "<<aLine.at(j + 2)<<endl;
                        reverseLine.at(aLine.size() - 1 - j - 2) = tmp;
                        reverseLine.at(aLine.size() - 1 - j - 1) = aLine.at(j + 1);
                        reverseLine.at(aLine.size() - 1 - j) = aLine.at(j + 2);
                        j += 3;
                        
                    } else { // ２バイトの全角の場合
                        std::cout<<"２バイトの全角の場合, aLine.at(j+2) = "<<aLine.at(j+2)<<endl;
                        std::cout<<(SJISMultiCheck(aLine.at(j+2))?"true":"false")<<endl;
                        reverseLine.at(aLine.size() - 1 - j - 1) = tmp;
                        reverseLine.at(aLine.size() - 1 - j) = aLine.at(j + 1);
                        j += 2;
                    }
                } else {
                    std::cout<<"オーバーの場合"<<endl;
                    std::cout<<"j="<<j<<endl;
                    std::cout<<"tmp: "<<tmp<<" aLine.at(j+1)"<<aLine.at(j+1)<<endl;
                    reverseLine.at(aLine.size() - 1 - j - 1) = tmp;
                    reverseLine.at(aLine.size() - 1 - j) = aLine.at(j + 1);
                    j += 2;
                }
                */
                reverseLine.at(aLine.size() - 1 - j - 2) = tmp;
                reverseLine.at(aLine.size() - 1 - j - 1) = aLine.at(j + 1);
                reverseLine.at(aLine.size() - 1 - j) = aLine.at(j + 2);
                j += 3;
                
            } else {
                reverseLine.at(aLine.size() - 1 - j) = tmp;
                j++;
            }
            
        }
        
        newLines.push_back(reverseLine);
    }
    return newLines;
}

vector<string> ScriptReader::getContents()
{
    return lines;
}