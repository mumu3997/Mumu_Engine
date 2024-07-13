#include "MuApplication.h"

namespace mu
{
	Application::Application()
	{
		mHwnd = nullptr;
		mHdc = nullptr;
	}

	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd) 
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		Player.SetPosition(0.0, 0.0);
		Player.SetWASD(true);

		Player2.SetPosition(0.0, 0.0);
	}

	void Application::Update()
	{
		Player.Update();
		Player2.Update();
	}

	void Application::LateUpdate()
	{
		Player2.AddPosition(.0002, 0.0);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Render()
	{
		Player.Render(mHdc);  
		Player2.Render(mHdc);
	}
}
