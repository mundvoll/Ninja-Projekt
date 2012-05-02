//
//  ESPCharacter.h
//  Ninja-Projekt
//
//  Created by Manuel Burghard on 25.04.12.
//  Copyright (c) 2012 ESP 2011/12/13. All rights reserved.
//

#include <iostream>
#include "irrlicht.h"
#include "ESPFrameTable.h"

#ifndef Ninja_Projekt_ESPCharacter_h
#define Ninja_Projekt_ESPCharacter_h

using namespace irr;
using namespace scene;

class ESPCharacter : public irr::scene::IAnimationEndCallBack {
    irr::scene::IAnimatedMeshSceneNode *node;
    ESPFrameTable *frameTable;
public:
    ESPCharacter(IAnimatedMeshSceneNode *node, ESPFrameTable *frameTable);
    ~ESPCharacter();
    
    IAnimatedMeshSceneNode * getNode();
    
    void idle();
    
    void OnAnimationEnd(IAnimatedMeshSceneNode* node);
};

#endif