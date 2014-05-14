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
#include "HeroClass.h"
#pragma message ("MinecraftApplication object is defined")

class MinecraftApplication : public BaseApplication
{
public:
	MinecraftApplication(void);
	virtual ~MinecraftApplication(void);

protected:
	virtual void createViewports(void);
	virtual void createCamera(void);
	virtual void createScene(void);

private:
	void addSpotlight(const Ogre::String name, const Ogre::Real xPos, const Ogre::Real zPos);
};

#endif // #ifndef __TutorialApplication_h_
