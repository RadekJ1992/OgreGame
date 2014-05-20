/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
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
#ifndef __MinecraftApplication_h_
#define __MinecraftApplication_h_

#include "BaseApplication.h"
#include "Cube.h"
#include "Character.h"
#include "OgreRoot.h"

#pragma message ("MinecraftApplication object is defined")

class MinecraftApplication : public BaseApplication
{
public:
	MinecraftApplication(void);
	virtual ~MinecraftApplication(void);

	enum QueryFlags
	{
		CUBE_MASK = 1<<0,
	};

protected:
	virtual void createViewports(void);
	virtual void createScene(void);
	virtual void createFrameListener(void);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	
	Ogre::SceneNode *mMainNode;
	Character *hero;
	Ogre::SceneNode *mCurrentObject;
	Ogre::RaySceneQuery* mRayScnQuery;	//pointer to our ray scene query
	bool bLMouseDown, bRMouseDown;	//true if mouse buttons are held down
	virtual bool keyPressed( const OIS::KeyEvent& evt );
    virtual bool keyReleased( const OIS::KeyEvent& evt );
	virtual bool mouseMoved(const OIS::MouseEvent& arg);
	virtual bool mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent& arg, OIS::MouseButtonID id);
	Ogre::Real mRotate;          // The rotate constant
	Ogre::Vector3 mDirection;
	Ogre::Real mMove;
private:
	void addSpotlight(const Ogre::String name, const Ogre::Real xPos, const Ogre::Real zPos);
};

#endif // #ifndef __TutorialApplication_h_
