#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Core/CoreEngine.h"
#include <glm/gtx/string_cast.hpp>

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime_);
	virtual void Render();
	virtual void OnDestroy();
private:
	std::vector<SceneGraph*> scenePtr;
	std::vector<Model*> modelPtr;
};

#endif // !1

