#include "Character.h"
#define SPEED 100

Character::Character (Ogre::String name, Ogre::SceneManager *sceneMgr, Ogre::Camera *camera):mName(name), mSceneMgr(sceneMgr), 
	mCamera(camera), grounded(true) {
   
    mMainNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (mName, Ogre::Vector3(0, 100, 0));
    mSightNode = mMainNode->createChildSceneNode (mName + "_sight", Ogre::Vector3 (0, 0, -100));
    mCameraNode = mMainNode->createChildSceneNode (mName + "_camera", Ogre::Vector3 (0, 100, 250));
	mHeroNode = mMainNode->createChildSceneNode (mName + "_hero", Ogre::Vector3 (0, 0, 0));

    mEntity = mSceneMgr->createEntity (mName, "robot.mesh");

    mHeroNode->attachObject (mEntity);
	mHeroNode->yaw(Ogre::Degree(90));
	mCameraNode->attachObject(mCamera);
	
	Ogre::AxisAlignedBox box = mEntity->getBoundingBox();
	mHeroLength = box.getSize().x;

	mEntity->setCastShadows(true);

	mAnimationState = mEntity->getAnimationState("Idle");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
}

Character::~Character () {
    mMainNode->detachAllObjects ();
    delete mEntity;
    mMainNode->removeAndDestroyAllChildren ();
    mSceneMgr->destroySceneNode (mName);
}

void Character::move(Ogre::Real elapsedTime, Ogre::Vector3 direction, Ogre::Real rotation) {
	
	mAnimationState->addTime(elapsedTime);

	if(direction != Ogre::Vector3::ZERO && !isCollision(mMainNode->getPosition(), direction)) {
		mAnimationState = mEntity->getAnimationState("Walk");
		mAnimationState->setLoop(true);
		mAnimationState->setEnabled(true);

		if(grounded)
			mMainNode->translate(direction * elapsedTime, Ogre::Node::TS_LOCAL);
	}else
	{
		mAnimationState = mEntity->getAnimationState("Idle");
		mAnimationState->setLoop(true);
		mAnimationState->setEnabled(true);
	}
}

void Character::ground(Ogre::Real elapsedTime) {


	Ogre::Vector3 direction = Ogre::Vector3::NEGATIVE_UNIT_Y * 50;
	
	if(!isCollision(mMainNode->getPosition(), direction) && mMainNode->getPosition().y >= 0)
		mMainNode->translate(direction * elapsedTime, Ogre::Node::TS_LOCAL);
	else if(isCollision(mMainNode->getPosition(), direction) || mMainNode->getPosition().y <= 0)
		grounded = true;
	
}
 
void Character::setVisible (bool visible) {
    mMainNode->setVisible (visible);
}

bool Character::isCollision(const Ogre::Vector3& position, const Ogre::Vector3& direction) 
{

	Ogre::Ray ray(position, mMainNode->getOrientation() * direction/100);
	mRaySceneQuery = mSceneMgr->createRayQuery(ray);
	Ogre::RaySceneQueryResult &result = mRaySceneQuery->execute();
    Ogre::RaySceneQueryResult::iterator itr;

	if(result.size() > 0)
		for (itr = result.begin(); itr != result.end(); itr++) {
			if (itr->movable->getName().compare("RoboOgre")!=0 && itr->movable->getName().compare("PlayerCam")!=0 && itr->movable->getName().find("Cube") != Ogre::String::npos && itr->distance < mHeroLength/2 ) {
				return true;
			}
		}
	return false;
}


