#ifndef __HeroClass_h_
#define __HeroClass_h_

#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>

class HeroClass
{
public:
	HeroClass(Ogre::SceneManager* sceneMgr, Ogre::Camera* camera);
	~HeroClass(void);
	Ogre::Node* getNode(){ return node_; }
	Ogre::Real getMoveSpeed(){ return moveSpeed_; }
	Ogre::Camera* getCamera(){ return camera_; }
	Ogre::Entity* getEntity(){ return entity_; }
private:
	Ogre::Entity* entity_;
	Ogre::SceneManager* sceneMgr_;
	Ogre::SceneNode* node_;
	Ogre::Camera* camera_;
	Ogre::Real moveSpeed_;
};

#endif // #ifndef __HeroClass_h_

