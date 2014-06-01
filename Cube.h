#ifndef __Cube_h_
#define __Cube_h_
#pragma once
#pragma message ("Cube object is defined")
#include "NewMOC.h"
#include <OgreEntity.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgrePrerequisites.h>
#include <OgreStringConverter.h>
#include <sstream>


class CubeVisitor;

class Cube
{
public:
	Cube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	virtual ~Cube(void);
	Ogre::SceneNode* getCubeNode(void);
	Ogre::Entity* getCubeEntity(void);
	Ogre::AxisAlignedBox getBoundingBox(void);
	virtual void accept(CubeVisitor& cV) = 0;
	void ground(Ogre::SceneManager& mSceneMgr);
protected:
	Ogre::SceneNode* _cubeNode;
	Ogre::Entity* _cubeEntity;
private:
	Ogre::Vector3 getEntityCenter(Ogre::Entity& _entity);
	std::vector<std::string> Cube::split(const std::string &s, char delim, std::vector<std::string> &elems);
	std::vector<std::string> Cube::split(const std::string &s, char delim);
};



class GoldCube :
	public Cube
{
public:
	GoldCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~GoldCube(void);
	void accept(CubeVisitor& cV);
};

class MetalCube :
	public Cube
{
public:
	MetalCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~MetalCube(void);
	void accept(CubeVisitor& cV);
};

class FireCube :
	public Cube
{
public:
	FireCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~FireCube(void);
	void accept(CubeVisitor& cV);
};

class WaterCube :
	public Cube
{
public:
	WaterCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~WaterCube(void);
	void accept(CubeVisitor& cV);
};

class WoodenCube :
	public Cube
{
public:
	WoodenCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z);
	~WoodenCube(void);
	void accept(CubeVisitor& cV);
};

class CubeVisitor
{
public:
	CubeVisitor(void);
	virtual ~CubeVisitor(void);

	void visit(WoodenCube& wC);
	void visit(MetalCube& mC);
	void visit(WaterCube& wC);
	void visit(FireCube& fC);
	void visit(GoldCube& gC);
protected:

private:

};

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



#endif