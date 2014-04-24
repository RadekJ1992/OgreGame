#pragma once
#pragma message ("WaterCube object is defined")
#include "Cube.h"
class WaterCube :
	public Cube
{
public:
	WaterCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~WaterCube(void);
	void accept(CubeVisitor& cV);
};

