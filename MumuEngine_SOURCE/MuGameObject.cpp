#include "MuGameObject.h"

namespace mu 
{
	GameObject::GameObject()
	{
		mX, mY = 0;
		mHdc = nullptr;
		isWASD = false;
	}
	GameObject::~GameObject() 
	{

	}
	void GameObject::Update()
	{
		//0 (0x0000)
		//	이전에 누른 적이 없고 호출 시점에서 안눌린 상태
		//	0x8000
		//	이전에 누른 적이 없고 호출 시점에서 눌린 상태
		//	0x8001
		//	이전에 누른 적이 있고 호출 시점에서 눌린 상태
		//	1 (0x0001)
		//	이전에 누른 적이 있고 호출 시점에서 안눌린 상태

		if (isWASD == false) {
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				mX -= 0.01;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				mX += 0.01;
			}
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				mY -= 0.01;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				mY += 0.01;
			}
		}
		else {
			if (GetAsyncKeyState('A') & 0x8000)
			{
				mX -= 0.01;
			}
			if (GetAsyncKeyState('D') & 0x8000)
			{
				mX += 0.01;
			}
			if (GetAsyncKeyState('W') & 0x8000)
			{
				mY -= 0.01;
			}
			if (GetAsyncKeyState('S') & 0x8000)
			{
				mY += 0.01;
			}
		}
		
	}
	void GameObject::LateUpdate() 
	{

	}

	void GameObject::Render(HDC mHdc)
	{
		// 파랑 브러쉬 생성 
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));
		// 파랑 브러쉬 dc 선택, 흰색 브러쉬 반환값 반환 
		// 이 때 SelectObject가 리턴하는 이전 브러시의 핸들은 복구를 위해 OldBrush 등의 변수에 저장해 두어야 한다
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, bluebrush);

		Rectangle(mHdc, 100 + mX, 100 + mY, 300 + mX, 300 + mY);

		// DC: 화면 출력에 필요한 모든 정보를 가지는 데이터 구조체
		//     GDI 모듈에 의해 관리
		//     폰트, 굵기, 색상 등...화면 출력에 필요한 모든 경우 DC를 통해서 진행 가능
	}

}