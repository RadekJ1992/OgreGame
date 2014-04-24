#pragma once
#pragma message ("MetalCube object is defined")
#include "Cube.h"
class MetalCube :
	public Cube
{
public:
	MetalCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~MetalCube(void);
	void accept(CubeVisitor& cV);
};

