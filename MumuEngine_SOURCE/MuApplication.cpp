#include "MuApplication.h"

namespace mu
{
	Application::Application()
	{
		mHwnd = nullptr;
		mHdc = nullptr;
		mSpeed = 0; 
		mX = 0;
		mY = 0;
	}

	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd) 
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}

	void Application::Update()
	{
		mSpeed += .01f;

		//0 (0x0000)
		//	������ ���� ���� ���� ȣ�� �������� �ȴ��� ����
		//	0x8000
		//	������ ���� ���� ���� ȣ�� �������� ���� ����
		//	0x8001
		//	������ ���� ���� �ְ� ȣ�� �������� ���� ����
		//	1 (0x0001)
		//	������ ���� ���� �ְ� ȣ�� �������� �ȴ��� ����

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

	void Application::LateUpdate()
	{

	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Render()
	{
		// �Ķ� �귯�� ���� 
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));
		// �Ķ� �귯�� dc ����, ��� �귯�� ��ȯ�� ��ȯ 
		// �� �� SelectObject�� �����ϴ� ���� �귯���� �ڵ��� ������ ���� OldBrush ���� ������ ������ �ξ�� �Ѵ�
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, bluebrush);

		Rectangle(mHdc, 100 + mX, 100 + mY, 300 + mX, 300+ mY);

		// DC: ȭ�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü
		//     GDI ��⿡ ���� ����
		//     ��Ʈ, ����, ���� ��...ȭ�� ��¿� �ʿ��� ��� ��� DC�� ���ؼ� ���� ����
	}
}
