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
	CTimeManager::getInst()->update();

	fPoint pos = object.GetPos();
	// GetAsuncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌 현재 상태의 키 입력상태를 확인
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		pos.x -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		pos.x += 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		pos.y -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		pos.y += 100 * CTimeManager::getInst()->GetDT();
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

	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2 + 200,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2 + 200,
		object.GetPos().y + object.GetScale().y / 2);

	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2 + 200,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2 + 200);

	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2 + 200,
		object.GetPos().y - object.GetScale().y / 2 + 200,
		object.GetPos().x + object.GetScale().x / 2 + 200,
		object.GetPos().y + object.GetScale().y / 2 + 200);

	// 오른쪽 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hDC, WINSIZEX - 50, 10, strFPS, 5);
}

void CCore::init()
{
	CTimeManager::getInst()->init();

	m_hDC = GetDC(hWnd);

	object = CGameObject(fPoint(100, 100), fPoint{100, 100});
}
