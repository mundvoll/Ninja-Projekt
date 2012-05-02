//
//  ESPCharacter.cpp
//  Ninja-Projekt
//
//  Created by Manuel Burghard on 25.04.12.
//  Copyright (c) 2012 ESP 2011/12/13. All rights reserved.
//

#include "ESPCharacter.h"


ESPCharacter::ESPCharacter(IAnimatedMeshSceneNode *aNode, ESPFrameTable *aFrameTable) {
    node = aNode;
    frameTable = aFrameTable;
}

ESPCharacter::~ESPCharacter() {
    node->remove();
}

IAnimatedMeshSceneNode * ESPCharacter::getNode() {
    return  node;
}

void ESPCharacter::idle() {
    ESPFrameLoop loop = frameTable->getFrame("idle");
    node->setFrameLoop(loop.start, loop.end);
}

void ESPCharacter::OnAnimationEnd(IAnimatedMeshSceneNode *aNode) {
    idle();
}