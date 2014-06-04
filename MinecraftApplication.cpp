#include "MinecraftApplication.h"

#define TEST

MinecraftApplication::MinecraftApplication():bLMouseDown(false), bRMouseDown(false), mCurrentObject(0)
{
}
MinecraftApplication::~MinecraftApplication()
{
	
}

void MinecraftApplication::createViewports()
{
	Ogre::Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
	mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));    
}

void MinecraftApplication::createWorld() {
	//Z
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 110, 15, 10);
	CubeFactory::getInstance().create("GoldCube", *mSceneMgr, 135 , 15,10);
	CubeFactory::getInstance().create("WaterCube", *mSceneMgr, 160 ,15, 10);
	CubeFactory::getInstance().create("MetalCube", *mSceneMgr, 185 , 15, 10);
	CubeFactory::getInstance().create("FireCube", *mSceneMgr, 135 , 15, 35);
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 160 , 15, 60);
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 110 , 15, 85);
	CubeFactory::getInstance().create("GoldCube", *mSceneMgr, 135 , 15,85);
	CubeFactory::getInstance().create("WaterCube", *mSceneMgr, 160 ,15, 85);
	CubeFactory::getInstance().create("MetalCube", *mSceneMgr, 185 , 15, 85);
	/*//P
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 235 , 15, 10);
	CubeFactory::getInstance().create("GoldCube", *mSceneMgr, 235 , 15, 35);
	CubeFactory::getInstance().create("WaterCube", *mSceneMgr, 235 ,15, 60);
	CubeFactory::getInstance().create("MetalCube", *mSceneMgr, 235 , 15, 85);
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 260 , 15, 60);
	CubeFactory::getInstance().create("FireCube", *mSceneMgr, 260 , 15, 85);
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 285 , 15,60);
	CubeFactory::getInstance().create("FireCube", *mSceneMgr, 285 , 15, 85);
	//R
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 310 , 15, 10);
	CubeFactory::getInstance().create("GoldCube", *mSceneMgr, 310 , 15, 35);
	CubeFactory::getInstance().create("WaterCube", *mSceneMgr, 310 ,15, 60);
	CubeFactory::getInstance().create("MetalCube", *mSceneMgr, 310 , 15, 85);
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 235 , 15, 60);
	CubeFactory::getInstance().create("FireCube", *mSceneMgr, 235 , 15, 85);
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 360 , 15, 10);
	CubeFactory::getInstance().create("GoldCube", *mSceneMgr, 360 , 15, 35);
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 260 , 15, 60);
	CubeFactory::getInstance().create("FireCube", *mSceneMgr, 260 , 15, 85);*/
	
}

void MinecraftApplication::createScene()
{
	Ogre::MaterialManager::getSingleton().setDefaultTextureFiltering(Ogre::TFO_NONE);
#ifdef TEST
	CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, 10, 10, 10);

	Ogre::SceneManager::MovableObjectIterator it= mSceneMgr->getMovableObjectIterator("Entity");
	std::ofstream myfile;
	myfile.open ("testLogs.txt", std::ios::out | std::ios::app );

	try {
		while (it.hasMoreElements())
		{
			std::string _name = it.getNext()->getName();

			std::vector<std::string> inputResult = Cube::split(_name, ':');
			std::vector<std::string> result;
			result.push_back("Cube");
			result.push_back("10");
			result.push_back("10");
			result.push_back("10");
			// 0:'WoodenCube' 1:'x' 2:'y' 3:'z'
			if (inputResult.at(0) == result.at(0) && inputResult.at(1) == result.at(1) && inputResult.at(2) == result.at(2) && inputResult.at(3) == result.at(3)) {
				myfile << "CubeFactory::create pozytywnie przeszlo test\n";
			} else {
				myfile << "CubeFactory::create nie przeszlo testu. Oczekiwany wynik : WoodenCubeCube, 10, 10, 10/ Otrzymany wynik : " + inputResult.at(0) + ", " + inputResult.at(1) + ", " + inputResult.at(2) + ", " + inputResult.at(3) + "\n";
			}

			mSceneMgr->getRootSceneNode()->removeAllChildren();
				//->removeChild("Cube:10:10:10");
				//
		}
	} catch (...) {
		myfile << "CubeFactory::create nie przeszlo testu - rzucony zostal wyjatek\n";
	}
	myfile.close();
#endif
	createWorld();
	
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.0, 0.0, 0.0));
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	
	addSpotlight("spotLight1", 250.0, 0);
	addSpotlight("spotLight2", 0, -250.0);
	addSpotlight("spotLight3", 0, 250.0);
	addSpotlight("spotLight4", -250.0, 0);

	mPlane = new Ogre::Plane(Ogre::Vector3::UNIT_Y, 0);
	Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *mPlane, 1000, 1000, 20, 20, true, 1, 10, 10, Ogre::Vector3::UNIT_Z);

	Ogre::Entity* entGround = mSceneMgr->createEntity("GroundEntity", "ground");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entGround);
	entGround->setMaterialName("Examples/BumpyMetal");
	entGround->setCastShadows(false);
	hero = new Character ("RoboOgre", mSceneMgr, mCamera);

}

void MinecraftApplication::createFrameListener()
{
	BaseApplication::createFrameListener();

	mDirection = Ogre::Vector3::ZERO;
	mMove = 100;
	mRotate = 0.13;

	mRayScnQuery = mSceneMgr->createRayQuery(Ogre::Ray());
 
	mTrayMgr->showCursor();
	mTrayMgr->getCursorContainer()->setPosition(mWindow->getWidth()/2, mWindow->getHeight()/2);
}
bool MinecraftApplication::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	if(!BaseApplication::frameRenderingQueued(evt))
	{
		return false;
	}

	if (mWindow->isClosed()) return false;
	if (mShutDown) return false;
	mKeyboard->capture();
	mMouse->capture();
	mTrayMgr->frameRenderingQueued(evt);

	hero->move(evt.timeSinceLastFrame, mDirection, mRotate);
	hero->ground(evt.timeSinceLastFrame);
	
	Ogre::Vector3 camPos = mCamera->getPosition();
	Ogre::Ray cameraRay(Ogre::Vector3(camPos.x, 5000.0f, camPos.z), Ogre::Vector3::NEGATIVE_UNIT_Y);
 
	mRayScnQuery->setRay(cameraRay);
 
	mRayScnQuery->setSortByDistance(false);
	Ogre::RaySceneQueryResult& result = mRayScnQuery->execute();
	Ogre::RaySceneQueryResult::iterator iter = result.begin();
 
	for(iter; iter != result.end(); iter++)
	{
		if(iter->worldFragment)
		{

			Ogre::Real terrainHeight = iter->worldFragment->singleIntersection.y;
 
			if((terrainHeight + 10.0f) > camPos.y)
			{
				hero->getCameraNode()->setPosition(camPos.x, camPos.y, camPos.z);
			}
			break;
		}
	}

	return true;
}

bool MinecraftApplication::keyPressed(const OIS::KeyEvent& evt)
{
	switch (evt.key)
	{
		case OIS::KC_ESCAPE: 
			mShutDown = true;
			break;
	

		case OIS::KC_UP:
		case OIS::KC_W:
			mDirection.z = -mMove;
			break;
 
		case OIS::KC_DOWN:
		case OIS::KC_S:
			mDirection.z = mMove;
			break;
 
		case OIS::KC_LEFT:
		case OIS::KC_A:
			mDirection.x = -mMove;
			break;
 
		case OIS::KC_RIGHT:
		case OIS::KC_D:
			mDirection.x = mMove;
			break;

		case OIS::KC_SPACE:
			
			if(hero->grounded)
			{	
				mDirection.y = 2*mMove;
				hero->grounded = false;
			}

			break;

		default:
			break;
	}

	return true;
}

bool MinecraftApplication::keyReleased(const OIS::KeyEvent& evt) {
	
	switch (evt.key)
	{
		case OIS::KC_UP:
		case OIS::KC_W:
			mDirection.z = 0;
			break;
 
		case OIS::KC_DOWN:
		case OIS::KC_S:
			mDirection.z = 0;
			break;
 
		case OIS::KC_LEFT:
		case OIS::KC_A:
			mDirection.x = 0;
			break;
 
		case OIS::KC_RIGHT:
		case OIS::KC_D:
			mDirection.x = 0;
			break;
 
		case OIS::KC_PGDOWN:
		case OIS::KC_E:
			mDirection.y = 0;
			break;
 
		case OIS::KC_SPACE:
			mDirection.y = 0;
			break;
		
		case OIS::KC_X:
			if(bLMouseDown && mCurrentObject){
				mCurrentObject->getParent()->removeChild(mCurrentObject->getName());
				mCurrentObject = NULL;
			}
			break;

		case OIS::KC_1:
			{
			CubeFactory::getInstance().create("WoodenCube", *mSceneMgr, mouseX, mouseY, mouseZ);
			}
			break;
			
		case OIS::KC_2:
			CubeFactory::getInstance().create("WaterCube", *mSceneMgr, mouseX, mouseY, mouseZ);
			break;

		case OIS::KC_3:
			CubeFactory::getInstance().create("FireCube", *mSceneMgr, mouseX, mouseY, mouseZ);
			break;

		case OIS::KC_4:
			CubeFactory::getInstance().create("MetalCube", *mSceneMgr, mouseX, mouseY, mouseZ);
			break;

		case OIS::KC_5:
			CubeFactory::getInstance().create("GoldCube", *mSceneMgr, mouseX, mouseY, mouseZ);
			break;

		default:
			break;
	}

	return true;
}

bool MinecraftApplication::mouseMoved(const OIS::MouseEvent& arg)
{
	Ogre::Real screenWidth = Ogre::Root::getSingleton().getAutoCreatedWindow()->getWidth();
	Ogre::Real screenHeight = Ogre::Root::getSingleton().getAutoCreatedWindow()->getHeight();
 
	Ogre::Real offsetX = arg.state.X.abs / screenWidth;
	Ogre::Real offsetY = arg.state.Y.abs / screenHeight;
 
	Ogre::Ray mouseRay = mCamera->getCameraToViewportRay(offsetX, offsetY);
 
   std::pair<bool, Ogre::Real> result = mouseRay.intersects(*mPlane);
 
    if(result.first) {
       Ogre::Vector3 point = mouseRay.getPoint(result.second);
	   mouseX = point.x;
	   mouseY = point.y;
	   mouseZ = point.z;
	}

	mTrayMgr->injectMouseMove(arg);

	if(bLMouseDown)
	{
	
		Ogre::Ray mouseRay = mTrayMgr->getCursorRay(mCamera);
 
		mRayScnQuery->setRay(mouseRay);
		mRayScnQuery->setSortByDistance(false);
 
		Ogre::RaySceneQueryResult& result = mRayScnQuery->execute();
		Ogre::RaySceneQueryResult::iterator iter = result.begin();
 
		for(iter; iter != result.end(); iter++)
		{
			if(iter->worldFragment)
			{
				mCurrentObject->setPosition(iter->worldFragment->singleIntersection);
				break;
			}	
		}

		if(mCurrentObject)
			mCurrentObject->translate(hero->getMainNode()->getOrientation() * Ogre::Vector3(arg.state.X.rel, -arg.state.Y.rel, -arg.state.Z.rel));
	}
	else if(bRMouseDown)
	{
		hero->getMainNode()->yaw(Ogre::Degree(-mRotate * arg.state.X.rel), Ogre::Node::TS_WORLD);
	}
 
	return true;
}

bool MinecraftApplication::mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id)
{
	if(id == OIS::MB_Left)
	{
		if(mCurrentObject)
		{
			mCurrentObject->showBoundingBox(false);
		}
 
		Ogre::Ray mouseRay = mTrayMgr->getCursorRay(mCamera);
 
		mRayScnQuery->setRay(mouseRay);
		mRayScnQuery->setSortByDistance(true);
		mRayScnQuery->setQueryMask(CUBE_MASK);

		Ogre::RaySceneQueryResult& result = mRayScnQuery->execute();
		Ogre::RaySceneQueryResult::iterator iter = result.begin();
 
		for(iter; iter != result.end(); iter++)
		{
			
			if(iter->movable && iter->movable->getName().find("Cube") != std::string::npos)
			{
				mCurrentObject = iter->movable->getParentSceneNode();
				break;
			}
			else if(iter->worldFragment)
			{
				break;
			}
		}
 
		if(mCurrentObject)
		{
			mCurrentObject->showBoundingBox(true);
		}
 
		bLMouseDown = true;

	}
	else if(id == OIS::MB_Right)
	{
		mTrayMgr->hideCursor();
 
		bRMouseDown = true;
	} 
 
	return true;
}

bool MinecraftApplication::mouseReleased(const OIS::MouseEvent& arg, OIS::MouseButtonID id)
{
	if(id  == OIS::MB_Left)
	{
		bLMouseDown = false;
	}
	else if(id == OIS::MB_Right)
	{
		mTrayMgr->showCursor();
 
		bRMouseDown = false;
	}
	return true;
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
		MinecraftApplication app;
#ifdef TEST
		remove("testLogs.txt");
		std::ofstream myfile;
		myfile.open ("testLogs.txt");
		myfile << "Raport z testow jednostkowych:\n";

		std::vector<std::string> result;
		result.push_back("Cube");
		result.push_back("1");
		result.push_back("2");
		result.push_back("3");
		std::string input = "Cube:1:2:3";
		std::vector<std::string> inputResult = Cube::split(input, ':');
		if (inputResult.at(0) == result.at(0) && inputResult.at(1) == result.at(1) && inputResult.at(2) == result.at(2) && inputResult.at(3) == result.at(3)) {
			myfile << "Cube::split pozytywnie przeszlo test\n";
		} else {
			myfile << "Cube::split nie przeszlo testu. Oczekiwany wynik : Cube, 1, 2, 3\nOtrzymany wynik : " + inputResult.at(0) + ", " + inputResult.at(1) + ", " + inputResult.at(2) + ", " + inputResult.at(3) + "\n";
		}
		myfile.close();
#endif
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
