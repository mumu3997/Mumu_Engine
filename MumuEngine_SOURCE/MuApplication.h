#pragma once
#include "MuGameObject.h"

namespace mu 
{

	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject Player; 
		GameObject Player2;
	};
}

