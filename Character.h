#pragma once
#include "OIS.h"
#include "Ogre.h"
#include "Cube.h"

class Character {
     protected:
         Ogre::SceneNode *mMainNode; // Main character node
         Ogre::SceneNode *mSightNode; // "Sight" node - The character is supposed to be looking here
         Ogre::SceneNode *mCameraNode; // Node for the chase camera
		 Ogre::SceneNode *mHeroNode;
         Ogre::Entity *mEntity; // Character entity
         Ogre::SceneManager *mSceneMgr;
		 Ogre::String mName;
		 Ogre::Camera *mCamera;
		 Ogre::AnimationState *mAnimationState; // The current animation state of the object
		 Ogre::Real mHeroLength;
		 Ogre::AxisAlignedBox boundingBox;
		 Ogre::RaySceneQuery* mRaySceneQuery;
		 Ogre::MovableObject* colObj;
     public:
		 Character (Ogre::String name, Ogre::SceneManager *sceneMgr, Ogre::Camera *camera);
		 ~Character();

		 virtual void move (Ogre::Real elapsedTime, Ogre::Vector3 direction, Ogre::Real rotation);
		 virtual bool isCollision(const Ogre::Vector3& position, const Ogre::Vector3& direction);
		 virtual void ground(Ogre::Real elapsedTime);

		 bool grounded;


         Ogre::SceneNode *getSightNode () {
             return mSightNode;
         }
         Ogre::SceneNode *getCameraNode () {
             return mCameraNode;
         }
		 Ogre::SceneNode *getMainNode () {
             return mMainNode;
         }
         Ogre::Vector3 getWorldPosition () {
             return mMainNode->_getDerivedPosition ();
         }

		 Ogre::AnimationState *getAnimationState () {
			return mAnimationState;
		 }

		 void setVisible (bool visible);
 };

