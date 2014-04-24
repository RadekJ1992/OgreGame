#include "MetalCube.h"


MetalCube::MetalCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("Examples/Chrome");
}


MetalCube::~MetalCube(void)
{
}

void MetalCube::accept(CubeVisitor& cV) {
	cV.visit(*this);
}
