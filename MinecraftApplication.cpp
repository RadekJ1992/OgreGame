/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
	  |___/                              
	  Tutorial Framework
	  http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "MinecraftApplication.h"


//-------------------------------------------------------------------------------------
MinecraftApplication::MinecraftApplication(void)
{
}
//-------------------------------------------------------------------------------------
MinecraftApplication::~MinecraftApplication(void)
{
}

//-------------------------------------------------------------------------------------
void MinecraftApplication::createScene(void)
{
	
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 0 , 0, 0);
	CubeFactory::getInstance().create("GoldCube", *mSceneMgr, 25 , 25, 25);
	CubeFactory::getInstance().create("WaterCube", *mSceneMgr, 25 , 0, 0);
	CubeFactory::getInstance().create("MetalCube", *mSceneMgr, 0 , 25, 0);
	CubeFactory::getInstance().create("FireCube", *mSceneMgr, 0 , 25, 25);

	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.0, 0.0, 0.0));
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	
	addSpotlight("spotLight1", 250.0, 0);
	addSpotlight("spotLight2", 0, -250.0);
	addSpotlight("spotLight3", 0, 250.0);
	addSpotlight("spotLight4", -250.0, 0);


	//Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	//Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	//plane, 200, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

	//Ogre::Entity* entGround = mSceneMgr->createEntity("GroundEntity", "ground");
	//mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entGround);
	//entGround->setMaterialName("Examples/BumpyMetal");
	//entGround->setCastShadows(false);
	
}

void MinecraftApplication::createViewports(void) {

	Ogre::Viewport* vp = mWindow->addViewport(mCamera);

	vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

	mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));    

}

void MinecraftApplication::createCamera(void)

{

	mCamera = mSceneMgr->createCamera("PlayerCam"); 

	mCamera->setPosition(Ogre::Vector3(150, 200, 0));

	mCamera->lookAt(Ogre::Vector3(0,0,0));

	mCamera->setNearClipDistance(5);

	mCameraMan = new OgreBites::SdkCameraMan(mCamera);   

}

void MinecraftApplication::addSpotlight(const Ogre::String name, const Ogre::Real xPos, const Ogre::Real zPos) {
	Ogre::Light* spotLight = mSceneMgr->createLight(name);
	spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
	spotLight->setDiffuseColour(1.0, 1.0, 1.0);
	spotLight->setSpecularColour(1.0, 1.0, 1.0);
	if (zPos != 0 && xPos != 0) {
	spotLight->setDirection(-xPos/abs(xPos), -1, -zPos/abs(zPos));
	spotLight->setPosition(xPos, 250.0, zPos);
	} else if (zPos == 0 && xPos != 0) {
		spotLight->setDirection(-xPos/abs(xPos), -1, 0);
		spotLight->setPosition(xPos, 250.0, zPos);
	} else if (zPos != 0 && xPos == 0) {
		spotLight->setDirection(0, -1, -zPos/abs(zPos));
		spotLight->setPosition(xPos, 250.0, zPos);
	} else if (zPos == 0 && xPos == 0) {
		spotLight->setDirection(0, -1, 0);
		spotLight->setPosition(xPos, 250.0, zPos);
	}
	spotLight->setAttenuation(500.0f, 0.5f, 0.007f, 0.0f);
	spotLight->setSpotlightRange(Ogre::Degree(180), Ogre::Degree(180));

}
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
	int main(int argc, char *argv[])
#endif
	{
		// Create application object
		MinecraftApplication app;
		
		try {
			app.go();
		} catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
			MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
			std::cerr << "An exception has occured: " <<
				e.getFullDescription().c_str() << std::endl;
#endif
		}

		return 0;
	}

#ifdef __cplusplus
}
#endif
