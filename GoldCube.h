#pragma once
#pragma message ("GoldCube object is defined")
#include "Cube.h"
class GoldCube :
	public Cube
{
public:
	GoldCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~GoldCube(void);
	void accept(CubeVisitor& cV);
};

