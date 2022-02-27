#include "framework.h"
#include "CScene_Start.h"

#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::update()
{
	CScene::update();

	if (KeyDown(VK_ESCAPE))
	{
		ChangeScn(GROUP_SCENE::TOOL);
	}

	if (KeyDown(VK_LBUTTON))
	{
		fPoint fptLookAt = CCameraManager::getInst()->GetRealPos(MousePos());
		CCameraManager::getInst()->SetLookAt(fptLookAt);
	}
}

void CScene_Start::Enter()
{
	// Player 추가
	CGameObject* pPlayer = new CPlayer;
	pPlayer->SetPos(fPoint(200, 200));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	// Monster 추가
	CMonster* pMonster = new CMonster;
	pMonster->SetPos(fPoint(1100, 350));
	pMonster->SetCenterPos(pMonster->GetPos());
	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MONSTER);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::MISSILE_PLAYER, GROUP_GAMEOBJ::MONSTER);

	// Camera Look 지정
	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));
	//CCameraManager::getInst()->SetTargetObj(pPlayer);
}

void CScene_Start::Exit()
{
	DeleteAll();

	CCollisionManager::getInst()->Reset();
}
