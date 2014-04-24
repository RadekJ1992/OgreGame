#include "CubeFactory.h"

CubeFactory& CubeFactory::getInstance(void)
{
	static CubeFactory instance; 
	return instance;
}

Cube* CubeFactory::create(std::string s, Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) {
	/*Callbacks::const_iterator i = callbacks_.find(s);
	if(i == callbacks_.end() ) {
		//Blad - nieznany typ figury
	}
	  else {
		return (i->second)(mSceneMgr, x, y, z);
	}*/
	if (s == "WoodenCube") {
		return createWoodenCubeFun(mSceneMgr, x, y, z);
	} else if (s == "MetalCube") {
		return createMetalCubeFun(mSceneMgr, x, y, z);
	} else if (s == "WaterCube") {
		return createWaterCubeFun(mSceneMgr, x, y, z);
	} else if (s == "FireCube") {
		return createFireCubeFun(mSceneMgr, x, y ,z);
	} else if (s == "GoldCube") {
		return createGoldCubeFun(mSceneMgr, x, y, z);
	}
}

CubeFactory::CubeFactory(void)
{
	//RegisterCube("WoodenCube", CubeFactory::createWoodenCubeFun());

}
/*
bool CubeFactory::RegisterCube(std::string s, CreateCubeFun fun) {
	callbacks_[s] = fun;

}*/

CubeFactory::~CubeFactory(void)
{
}

Cube* CubeFactory::createWoodenCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) {
	return new WoodenCube(mSceneMgr, x, y, z);
}
Cube* CubeFactory::createMetalCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z){
	return new MetalCube(mSceneMgr, x, y, z);
}
Cube* CubeFactory::createWaterCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z){
	return new WaterCube(mSceneMgr, x, y, z);
}
Cube* CubeFactory::createFireCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z){
	return new FireCube(mSceneMgr, x, y, z);
}
Cube* CubeFactory::createGoldCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z){
	return new GoldCube(mSceneMgr, x, y, z);
}