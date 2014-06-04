#include "Cube.h"
#define CUBE_SCALE 0.25

Ogre::Vector3 Cube::getEntityCenter(Ogre::Entity& _entity)
{
   Ogre::AxisAlignedBox boundingBox = _entity.getBoundingBox();
   Ogre::Vector3 point = ( boundingBox.getMaximum() - boundingBox.getMinimum() ) /2;
   return point;
}

Cube::Cube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) {
	Ogre::SceneManager::MovableObjectIterator it= mSceneMgr.getMovableObjectIterator("Entity");
	Ogre::Real lowestY = 10;
	_mSceneMgr = &mSceneMgr;

	while (it.hasMoreElements())
	{
		std::string _name = it.getNext()->getName();

		if (_name != "GroundEntity" && _name != "RoboOgre") {
			try {
				std::vector<std::string> _temp = Cube::split(_name, ':');
				// 0:'Cube' 1:'x' 2:'y' 3:'z'
				if (_temp[0] == "Cube") {
					int _tempX;
					std::istringstream iss1(_temp[1]);
					iss1 >> _tempX;
					int _tempY;
					std::istringstream iss2(_temp[2]);
					iss2 >> _tempY;
					int _tempZ;
					std::istringstream iss3(_temp[3]);
					iss3 >> _tempZ;
					if (_tempX > (x - 25) && _tempX < (x + 25) && _tempZ > (z - 25) && _tempZ < (z + 25))	
					{
						if (lowestY <= _tempY) lowestY = _tempY+25;
					}
				}
			}
			catch (...) {    }
		}
	}
	_name = "Cube:"+Ogre::StringConverter::toString(x,6,0, '_',0) +":"+ Ogre::StringConverter::toString(lowestY,6,0, '_',0)+":"+Ogre::StringConverter::toString(z,6,0, '_',0);

	_cubeEntity = mSceneMgr.createEntity(_name, "cube.mesh");

	_cubeNode = mSceneMgr.getRootSceneNode()->createChildSceneNode();

	_cubeNode->attachObject(_cubeEntity);

	_cubeNode->showBoundingBox(true);

	_cubeEntity->setCastShadows(true);

	_cubeNode->setPosition(x, lowestY, z);

	_cubeNode->scale(CUBE_SCALE, CUBE_SCALE, CUBE_SCALE);
	
}


std::vector<std::string> Cube::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> Cube::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	Cube::split(s, delim, elems);
	return elems;
}


Cube::~Cube() {
	_cubeNode->detachAllObjects ();
    delete _cubeEntity;
    _cubeNode->removeAndDestroyAllChildren ();
    _mSceneMgr->destroySceneNode(_name);
}

Ogre::SceneNode* Cube::getCubeNode() {
	return _cubeNode;
}

Ogre::Entity* Cube::getCubeEntity() {
	return _cubeEntity;
}

Ogre::AxisAlignedBox Cube::getBoundingBox() {
	return _cubeEntity->getBoundingBox();	
}

FireCube::FireCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("Examples/EveningSkyBox");
}


FireCube::~FireCube()
{
}


GoldCube::GoldCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("Examples/Flare3");
}


GoldCube::~GoldCube()
{
}

MetalCube::MetalCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("Examples/RustySteel");
}


MetalCube::~MetalCube()
{
}




WaterCube::WaterCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("Examples/WaterStream");

}


WaterCube::~WaterCube()
{
}


WoodenCube::WoodenCube(Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) : Cube(mSceneMgr, x, y, z)
{
	_cubeEntity->setMaterialName("WoodPallet");

}


WoodenCube::~WoodenCube()
{
}

CubeFactory& CubeFactory::getInstance()
{
	static CubeFactory instance; 
	return instance;
}

Cube* CubeFactory::create(std::string s, Ogre::SceneManager& mSceneMgr, Ogre::Real x, Ogre::Real y, Ogre::Real z) {

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
	} else return nullptr;
}

CubeFactory::CubeFactory()
{
}


CubeFactory::~CubeFactory()
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