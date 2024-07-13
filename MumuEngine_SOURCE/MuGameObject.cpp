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
		//	������ ���� ���� ���� ȣ�� �������� �ȴ��� ����
		//	0x8000
		//	������ ���� ���� ���� ȣ�� �������� ���� ����
		//	0x8001
		//	������ ���� ���� �ְ� ȣ�� �������� ���� ����
		//	1 (0x0001)
		//	������ ���� ���� �ְ� ȣ�� �������� �ȴ��� ����

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
		// �Ķ� �귯�� ���� 
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));
		// �Ķ� �귯�� dc ����, ��� �귯�� ��ȯ�� ��ȯ 
		// �� �� SelectObject�� �����ϴ� ���� �귯���� �ڵ��� ������ ���� OldBrush ���� ������ ������ �ξ�� �Ѵ�
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, bluebrush);

		Rectangle(mHdc, 100 + mX, 100 + mY, 300 + mX, 300 + mY);

		// DC: ȭ�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü
		//     GDI ��⿡ ���� ����
		//     ��Ʈ, ����, ���� ��...ȭ�� ��¿� �ʿ��� ��� ��� DC�� ���ؼ� ���� ����
	}

}