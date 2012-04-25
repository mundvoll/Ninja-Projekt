//
//  ESPModelImporter.cpp
//  Ninja-Projekt
//
//  Created by Manuel Burghard on 12.03.12.
//  Copyright (c) 2012 ESP 2011/12/13. All rights reserved.
//

#include "ESPModelImporter.h"
#include "ESPFrameTable.h"
#include "Definitions.h"

using namespace std;
using namespace io;

typedef struct _ESPRange {
    s32 location;
    s32 length;
} ESPRange;

ESPModelImporter::ESPModelImporter(ISceneManager *manager) {
    if (!manager) {
        return ;
    }
    sceneManager = manager;
}

stringw findValueForModelKey(stringw key, stringw content);
ESPFrameLoop parseStringForFrameLoop(stringw string);
s32 wcharTos32(const wchar_t* wc);
s32 wcharTos32(const wchar_t* wc) {
    return wcstol(wc, '\0', 10); 
}

stringw findValueForModelKey(stringw key, stringw content) {
    
    stringw searchstring = key;
    searchstring += " = \"";
    s32 start = content.find(searchstring.c_str());
    start += searchstring.size();
    s32 end = content.find("\";", start);
    
    return content.subString(start, end - start);
}

ESPFrameLoop parseStringForFrameLoop(stringw string) {
    
    ESPFrameLoop frameLoop = {0,0};
    s32 loopStart = 0, loopEnd = 0;
    
    s32 start = string.find(L"{") + 1;
    s32 end = string.find(L";");
    
    stringw loopStartString = string.subString(start, end-start);
    
    start = end + 1;
    end = string.find(L"}", start);
    
    stringw loopEndString = string.subString(start, end-start);
    
    loopStart = wcharTos32(loopStartString.c_str());
    loopEnd = wcharTos32(loopEndString.c_str());
    frameLoop = (ESPFrameLoop){loopStart, loopEnd};
    return frameLoop;
}

 


void ESPModelImporter::openAnimatedMeshSceneNode(const io::path& filename, s32 id) {
    stringw modelDescriptionPath = stringw(filename);
    IFileSystem *fileSystem = sceneManager->getFileSystem();
    modelDescriptionPath += L"/model.txt";
    if (modelDescriptionPath == NULL) {
        return;
    } else{
        cout << (&modelDescriptionPath)->c_str();
    }
    
    IReadFile *modelDescription = fileSystem->createAndOpenFile(path(modelDescriptionPath));
    const long filesize = modelDescription->getSize();
    c8* buf = new c8[filesize];
	memset(buf, 0, filesize);
	modelDescription->read((void*)buf, filesize);
    stringw filecontent = buf;
    
    stringw modelPath = filename;
    modelPath += L"/";
    modelPath += findValueForModelKey(L"model", filecontent); 
    cout << modelPath.c_str();
    
    stringw texturePath = filename;
    texturePath += L"/";
    
    texturePath += findValueForModelKey(L"texture", filecontent);
    
    ESPFrameTable *frameLoops = new ESPFrameTable();
   
    // Following lines only for test purpose. Without any use at the moment.
    stringw value = findValueForModelKey("animation:idle", filecontent);
    ESPFrameLoop loop = parseStringForFrameLoop(value);
    frameLoops->setFrame(loop, "idle");
    
    
    IAnimatedMeshSceneNode *node = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh(modelPath));
    node->setMaterialTexture(0, sceneManager->getVideoDriver()->getTexture(texturePath));
    node->setMaterialFlag(video::EMF_LIGHTING, false);
    node->setID(id);
    modelDescription->drop();
}

void ESPModelImporter::setSceneManager(ISceneManager *manager) {
    sceneManager = manager;
}

ISceneManager* ESPModelImporter::getSceneManager() {
    return sceneManager;
}

