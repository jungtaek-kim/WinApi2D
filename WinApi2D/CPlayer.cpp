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
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fpMissilePos);
	pMissile->SetScale(fPoint(25.f, 25.f));
	pMissile->SetDir(true);

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_GAMEOBJ::MISSILE);
}
