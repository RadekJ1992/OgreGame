#include "Cube.h"

Cube::Cube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) {

	_cubeEntity = mSceneMgr.createEntity("Cube", "cube.mesh");

	_cubeNode = mSceneMgr.getRootSceneNode()->createChildSceneNode();

	_cubeNode->attachObject(_cubeEntity);
	
	_cubeNode->showBoundingBox(true);

	_cubeEntity->setCastShadows(true);

	_cubeNode->setPosition(x, y, z);
}

Cube::~Cube(void) {

}

Ogre::SceneNode* Cube::getCubeNode(void) {
	return _cubeNode;
}

Ogre::Entity* Cube::getCubeEntity(void) {
	return _cubeEntity;
}

Ogre::AxisAlignedBox Cube::getBoundingBox(void) {
	return _cubeEntity->getBoundingBox();	
}