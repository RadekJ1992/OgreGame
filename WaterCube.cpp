#include "WaterCube.h"


WaterCube::WaterCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("Examples/WaterStream");
}


WaterCube::~WaterCube(void)
{
}

void WaterCube::accept(CubeVisitor& cV) {
	cV.visit(*this);
}