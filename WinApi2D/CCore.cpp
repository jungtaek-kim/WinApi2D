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
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

void CCore::update()
{
	CTimeManager::getInst()->update();
	CKeyManager::getInst()->update();

	fPoint pos = object.GetPos();
	// GetAsuncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌 현재 상태의 키 입력상태를 확인
	if (CKeyManager::getInst()->GetButton(VK_LEFT))
	{
		pos.x -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_RIGHT))
	{
		pos.x += 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_UP))
	{
		pos.y -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_DOWN))
	{
		pos.y += 100 * CTimeManager::getInst()->GetDT();
	}

	object.SetPos(pos);
}

void CCore::render()
{
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2 + 200,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2 + 200,
		object.GetPos().y + object.GetScale().y / 2);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2 + 200,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2 + 200);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2 + 200,
		object.GetPos().y - object.GetScale().y / 2 + 200,
		object.GetPos().x + object.GetScale().x / 2 + 200,
		object.GetPos().y + object.GetScale().y / 2 + 200);

	// 오른쪽 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->init();
	CSceneManager::getInst()->init();

	m_hDC = GetDC(hWnd);

	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	object = CGameObject(fPoint(100, 100), fPoint{100, 100});
}
