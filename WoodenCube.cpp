#include "WoodenCube.h"


WoodenCube::WoodenCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("WoodPallet");

}


WoodenCube::~WoodenCube(void)
{
}

void WoodenCube::accept(CubeVisitor& cV) {
	cV.visit(*this);
}
