#include "GoldCube.h"

GoldCube::GoldCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("Examples/EveningSkyBox");
}


GoldCube::~GoldCube(void)
{
}

void GoldCube::accept(CubeVisitor& cV) {
	cV.visit(*this);
}
