#include "framework.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"

void CPlayer::update()
{
	fPoint pos = GetPos();

	if (Key(VK_LEFT))
	{
		pos.x -= 100 * DT;
	}

	if (Key(VK_RIGHT))
	{
		pos.x += 100 * DT;
	}				   
					   
	if (Key(VK_UP))	   
	{				   
		pos.y -= 100 * DT;
	}				   
					   
	if (Key(VK_DOWN))  
	{				   
		pos.y += 100 * DT;
	}

	SetPos(pos);

	if (KeyDown(VK_SPACE))
	{
		CreateMissile();
	}
}

void CPlayer::render(HDC hDC)
{
	Rectangle(hDC,
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2);
}

void CPlayer::CreateMissile()
{
	fPoint fpMissilePos = GetPos();
	fpMissilePos.x += GetScale().x / 2.f;

	// Misiile Object
	CMissile* pMissile1 = new CMissile;
	pMissile1->SetPos(fpMissilePos);
	pMissile1->SetScale(fPoint(25.f, 25.f));
	pMissile1->SetDir(1, 0);

	CMissile* pMissile2 = new CMissile;
	pMissile2->SetPos(fpMissilePos);
	pMissile2->SetScale(fPoint(25.f, 25.f));
	pMissile2->SetDir(1, 1);

	CMissile* pMissile3 = new CMissile;
	pMissile3->SetPos(fpMissilePos);
	pMissile3->SetScale(fPoint(25.f, 25.f));
	pMissile3->SetDir(1, -1);

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile1, GROUP_GAMEOBJ::MISSILE);
	pCurScene->AddObject(pMissile2, GROUP_GAMEOBJ::MISSILE);
	pCurScene->AddObject(pMissile3, GROUP_GAMEOBJ::MISSILE);
}
