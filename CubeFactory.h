#pragma once
#pragma message ("CubeFactory object is defined")
//#include "Cube.h"
#include "WoodenCube.h"
#include "MetalCube.h"
#include "WaterCube.h"
#include "FireCube.h"
#include "GoldCube.h"

class CubeFactory
{
public:
	static CubeFactory& getInstance(void);
	//typedef Cube* (*CreateCubeFun)(const Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	//bool RegisterCube(std::string, CreateCubeFun fun);
	Cube* create(std::string, Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	
private:
	//typedef std::map<std::string, CreateCubeFun> Callbacks;
	//Callbacks callbacks_;

	CubeFactory(void);
	~CubeFactory(void);

	Cube* createWoodenCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Cube* createMetalCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Cube* createWaterCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Cube* createFireCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Cube* createGoldCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
};

