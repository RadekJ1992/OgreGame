#pragma once
#include "Cube.h"
#pragma message ("FireCube object is defined")
class FireCube :
	public Cube
{
public:
	FireCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~FireCube(void);
	void accept(CubeVisitor& cV);
};

