#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"

CGameObject object;

CCore::CCore()
{
	// ���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
	m_hDC = 0;
}

CCore::~CCore()
{
	// ���� �ھ� ���� ������ DC �ڵ鰪 �ݳ�
	ReleaseDC(hWnd, m_hDC);
}

void CCore::update()
{
	// GetAsuncKeyState : �޽��� ť�� Ű �Է��� �޴� ����� �ƴ� ���� ������ Ű �Է»��¸� Ȯ��
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		object.m_ptPos.x -= 1;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		object.m_ptPos.x += 1;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		object.m_ptPos.y -= 1;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		object.m_ptPos.y += 1;
	}
}

void CCore::render()
{
	Rectangle(m_hDC,
		object.m_ptPos.x - object.m_ptScale.x / 2,
		object.m_ptPos.y - object.m_ptScale.y / 2,
		object.m_ptPos.x + object.m_ptScale.x / 2,
		object.m_ptPos.y + object.m_ptScale.y / 2);
}

void CCore::init()
{
	m_hDC = GetDC(hWnd);

	object = CGameObject(POINT{ 100, 100 }, POINT{ 100, 100 });
}
