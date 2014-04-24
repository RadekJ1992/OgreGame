#include "FireCube.h"


FireCube::FireCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("Fury/HeatVision/HeatCaster");
}


FireCube::~FireCube(void)
{
}

void FireCube::accept(CubeVisitor& cV) {
	cV.visit(*this);
}