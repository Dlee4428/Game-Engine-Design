#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <string>
#include <iostream>
#include <stdio.h>

#include "../Core/Debug/Debug.h"
#include "../../Resources/Imgui/imgui.h"
#include "../../Resources/Imgui/imgui_impl_sdl.h"
#include "../../Resources/Imgui/imgui_impl_opengl3.h"

class Window
{
public:
	Window();
	~Window();

	bool OnCreate(std::string name_, int width_, int height_);
	void OnDestroy();
	int GetWidth() const;
	int GetHeight() const;
	SDL_Window* GetWindow() const;
	void ImGuiTheme();

private:
	void SetAttributes();
	int width;
	int height;
	SDL_Window* window;
	SDL_GLContext context;
	std::string glsl_version_string = "#version 450";
};
#endif // !WINDOW_H
