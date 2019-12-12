#ifndef MOUSEEVENTLISTENER_H
#define MOUSEEVENTLISTENER_H

#include <SDL.h>
#include <glm/glm.hpp>

class CoreEngine;

class MouseEventListener
{
public:
	MouseEventListener(const MouseEventListener&) = delete;
	MouseEventListener(MouseEventListener&&) = delete;
	MouseEventListener& operator=(const MouseEventListener&) = delete;
	MouseEventListener& operator=(MouseEventListener&&) = delete;

	MouseEventListener() = delete;
	~MouseEventListener();

	static void RegisterEngineObject(CoreEngine* engine_);
	static void Update(SDL_Event e_);
	static void NotifyMousePressed(int buttonType_);
	static void NotifyMouseReleased(int buttonType_);
	static void NotifyMouseMove();
	static void NotifyMouseScroll(int y_);

	static glm::vec2 GetPreviousMousePos();
	static glm::vec2 GetMousePos();
	static glm::vec2 GetMouseOffset();
private:
	static CoreEngine* engineInstance;
	static int mouseX, mouseY, prevMouseX, prevMouseY;
	static bool firstUpdate;

	static void UpdateMousePos();
};

#endif