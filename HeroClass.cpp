#include "HeroClass.h"


HeroClass::HeroClass(Ogre::SceneManager* sceneMgr, Ogre::Camera* camera): sceneMgr_(sceneMgr), camera_(camera), moveSpeed_(250)
{
	entity_ = sceneMgr_->createEntity("Ninja", "ninja.mesh");

	node_ = sceneMgr_->getRootSceneNode();

	node_ = node_->createChildSceneNode("NinjaNode");
	node_->attachObject(entity_);

	node_ = node_->createChildSceneNode("CamNode", Ogre::Vector3(0, 200, 300));
	node_->attachObject(camera_);

	
	//node_ = node_->createChildSceneNode("NinjaNode");
	/*node_->attachObject(entity_);

	node_ = node_->createChildSceneNode("CamNode", Ogre::Vector3(0, 200, 300));
	node_->attachObject(camera_);*/
	
}


HeroClass::~HeroClass(void)
{

}
