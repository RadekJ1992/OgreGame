#ifndef __Cube_h_
#define __Cube_h_
#pragma once
#pragma message ("Cube object is defined")
#include <OgreEntity.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgrePrerequisites.h>
#include <OgreStringConverter.h>
#include <sstream>


class Cube
{
public:
	Cube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	virtual ~Cube();
	Ogre::SceneNode* getCubeNode();
	Ogre::Entity* getCubeEntity();
	Ogre::AxisAlignedBox getBoundingBox();
	static std::vector<std::string> Cube::split(const std::string &s, char delim, std::vector<std::string> &elems);
	static std::vector<std::string> Cube::split(const std::string &s, char delim);
protected:
	Ogre::SceneNode* _cubeNode;
	Ogre::Entity* _cubeEntity;
private:
	void ground(Ogre::SceneManager& mSceneMgr);
	Ogre::Vector3 getEntityCenter(Ogre::Entity& _entity);
	Ogre::SceneManager* _mSceneMgr;
	std::string _name;
	
};



class GoldCube :
	public Cube
{
public:
	GoldCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~GoldCube();
};

class MetalCube :
	public Cube
{
public:
	MetalCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~MetalCube();
};

class FireCube :
	public Cube
{
public:
	FireCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~FireCube();
};

class WaterCube :
	public Cube
{
public:
	WaterCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~WaterCube();
};

class WoodenCube :
	public Cube
{
public:
	WoodenCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~WoodenCube();
};

class CubeFactory
{
public:
	static CubeFactory& getInstance();
	Cube* create(std::string, Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);

private:

	CubeFactory();
	~CubeFactory();

	Cube* createWoodenCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Cube* createMetalCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Cube* createWaterCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Cube* createFireCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	Cube* createGoldCubeFun(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
};



#endif