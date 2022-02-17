#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"

CGameObject object;

CCore::CCore()
{
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
	m_hDC = 0;
}

CCore::~CCore()
{
	// 게임 코어 종료 시점에 DC 핸들값 반납
	ReleaseDC(hWnd, m_hDC);
}

void CCore::update()
{
	// GetAsuncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌 현재 상태의 키 입력상태를 확인
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
