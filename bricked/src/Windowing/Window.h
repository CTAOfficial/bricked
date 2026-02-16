#pragma once
#include <SDL3/SDL.h>
#include <string>

class Window {
private:

	bool IsRunning = false;


protected:
	Window(std::string& title, int width, int height);
	SDL_Window* window;
	SDL_Renderer* renderer;

	double deltaTime = 0.0;
	Uint64 lastTick{ 0 };
	Uint64 currentTick{ 0 };

public:
	~Window();	

	std::string Title;
	int Width;
	int Height;

	void Run();
	virtual void HandlePoll(SDL_Event event);
	virtual void Update(){}
	void Close();
	virtual void OnClose(){}

	static Window* Create(std::string title, int width, int height);
};