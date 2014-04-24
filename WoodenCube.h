#pragma once
#pragma message ("WoodenCube object is defined")
#include "Cube.h"
class WoodenCube :
	public Cube
{
public:
	WoodenCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~WoodenCube(void);
	void accept(CubeVisitor& cV);
};

