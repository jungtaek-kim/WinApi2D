#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"
#include "CTexture.h"

CCore::CCore()
{

}

CCore::~CCore()
{

}

void CCore::update()
{
	// 이전 update에서 추가된 이벤트를 프레임 초기에 한꺼번에 처리
	CEventManager::GetInst()->update();

	CTimeManager::GetInst()->update();
	CKeyManager::GetInst()->update();
	CSoundManager::GetInst()->update();

	CSceneManager::GetInst()->update();
	CCollisionManager::GetInst()->update();
	CCameraManager::GetInst()->update();
	CUIManager::GetInst()->update();
}

void CCore::render()
{
	CRenderManager::GetInst()->GetRenderTarget()->BeginDraw();

	CRenderManager::GetInst()->RenderFillRectangle(-1, -1, WINSIZEX + 1, WINSIZEY + 1, RGB(255, 255, 255));

	CSceneManager::GetInst()->render();
	CCameraManager::GetInst()->render();

	// 오른쪽 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::GetInst()->GetFPS());
	CRenderManager::GetInst()->RenderText(strFPS, WINSIZEX - 50, 10, WINSIZEX, 50, 12, RGB(0, 0, 0));

	CRenderManager::GetInst()->GetRenderTarget()->EndDraw();
}

void CCore::init()
{
	CPathManager::GetInst()->init();
	CTimeManager::GetInst()->init();
	CKeyManager::GetInst()->init();
	CSoundManager::GetInst()->init();
	CRenderManager::GetInst()->init();

	CCameraManager::GetInst()->init();
	CSceneManager::GetInst()->init();
	CCollisionManager::GetInst()->init();
}
