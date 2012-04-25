//
//  ESPFrameTable.cpp
//  Ninja-Projekt
//
//  Created by Manuel Burghard on 18.04.12.
//  Copyright (c) 2012 ESP 2011/12/13. All rights reserved.
//

#include "ESPFrameTable.h"

using namespace std;

typedef ESPFrameLoopTable::value_type ValueType;

ESPFrameTable::ESPFrameTable(void) {
    
}

ESPFrameTable::~ESPFrameTable(void) {
    
}

void ESPFrameTable::setFrame(ESPFrameLoop frameLoop, string key) {
    
    frameLoopTable.insert(ValueType(key, frameLoop));
}

void ESPFrameTable::setFrame(int start, int end, string key) {
    ESPFrameLoop frameLoop = {start, end};
    setFrame(frameLoop, key);
}

ESPFrameLoop ESPFrameTable::getFrame(string key) {
    ESPFrameLoopTable::iterator iterator = frameLoopTable.find(key);
    if (iterator != frameLoopTable.end()) {
        return iterator->second;
    } else {
        printf("No frame loop found for key \"%s\"", key.c_str());
        ESPFrameLoop emptyFrameLoop = {0,0};
        return emptyFrameLoop;
    }
}