#ifndef __Cube_h_
#define __Cube_h_
#pragma once
#pragma message ("Cube object is defined")
#include <OgreEntity.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgrePrerequisites.h>
#include "CubeVisitor.h"

class Cube
{
public:
	Cube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	virtual ~Cube(void);
	Ogre::SceneNode* getCubeNode(void);
	Ogre::Entity* getCubeEntity(void);
	Ogre::AxisAlignedBox getBoundingBox(void);
	virtual void accept(CubeVisitor& cV) = 0;
protected:
	Ogre::SceneNode* _cubeNode;
	Ogre::Entity* _cubeEntity;
private:
};

#endif
