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
	fPoint pos = object.GetPos();
	// GetAsuncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌 현재 상태의 키 입력상태를 확인

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		pos.x -= 0.01;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		pos.x += 0.01;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		pos.y -= 0.01;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		pos.y += 0.01;
	}

	object.SetPos(pos);
}

void CCore::render()
{
	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2);
}

void CCore::init()
{
	m_hDC = GetDC(hWnd);

	object = CGameObject(fPoint(100, 100), fPoint{100, 100});
}
