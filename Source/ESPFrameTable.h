//
//  ESPFrameTable.h
//  Ninja-Projekt
//
//  Created by Manuel Burghard on 18.04.12.
//  Copyright (c) 2012 ESP 2011/12/13. All rights reserved.
//

#ifndef Ninja_Projekt_ESPFrameTable_h
#define Ninja_Projekt_ESPFrameTable_h

#include <map>
#include <iostream>

#include <irrlicht.h>
using namespace irr;

typedef struct _ESPFrameLoop {
    s32 start;
    s32 end;
} ESPFrameLoop;

typedef std::map<std::string, ESPFrameLoop> ESPFrameLoopTable;

class ESPFrameTable {
    ESPFrameLoopTable frameLoopTable;
public:
    ESPFrameTable(void);
    ~ESPFrameTable(void); 
    
    void setFrame(ESPFrameLoop frameLoop, std::string key);
    void setFrame(s32 start, s32 end, std::string);
    ESPFrameLoop getFrame(std::string key);
    
};



#endif
