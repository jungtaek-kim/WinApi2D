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
}

void CScene_Start::Enter()
{
	// Player �߰�
	CGameObject* pPlayer = new CPlayer;
	pPlayer->SetPos(fPoint(200, 200));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	CGameObject* pOtherPlayer = pPlayer->Clone();
	pOtherPlayer->SetPos(fPoint(200, 400));
	AddObject(pOtherPlayer, GROUP_GAMEOBJ::PLAYER);

	// Monster �߰�
	CMonster* pMonster = new CMonster;
	pMonster->SetPos(fPoint(1100, 350));
	pMonster->SetCenterPos(pMonster->GetPos());
	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MONSTER);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::MISSILE_PLAYER, GROUP_GAMEOBJ::MONSTER);
}

void CScene_Start::Exit()
{
	DeleteAll();

	CCollisionManager::getInst()->Reset();
}
