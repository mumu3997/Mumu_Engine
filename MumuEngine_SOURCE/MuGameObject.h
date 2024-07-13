#pragma once
#include "CommonInclude.h"

namespace mu
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC mHdc);

		float GetXPosition() { return mX; }
		float GetYPosition() { return mY; }
		
		void SetPosition(float x, float y) 
		{
			mX = x;
			mY = y;
		}
		void AddPosition(float x, float y)
		{
			mX += x;
			mY += y; 
		}
		void SetWASD(bool beWASD) 
		{
			isWASD = beWASD;
		}
	private:
		float mX;
		float mY;

		bool isWASD;

		HDC mHdc;
	};

}

