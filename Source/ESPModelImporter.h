//
//  ESPModelImporter.h
//  Ninja-Projekt
//
//  Created by Manuel Burghard on 12.03.12.
//  Copyright (c) 2012 ESP 2011/12/13. All rights reserved.
//
#include <iostream>
#include <irrlicht.h>


using namespace irr;
using namespace core;
using namespace scene;
using namespace io;

class ESPModelImporter {
    private:
        ISceneManager *sceneManager;
        IrrlichtDevice *device;
    
    public:
    
    ESPModelImporter(ISceneManager *manager);
    ~ESPModelImporter(void);
    void openAnimatedMeshSceneNode(const io::path& filename, s32 id);
    void setSceneManager(ISceneManager *manager);
    ISceneManager* getSceneManager();
};
