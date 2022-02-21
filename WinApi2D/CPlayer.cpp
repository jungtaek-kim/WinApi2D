#include "framework.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#include "CTexture.h"
#include "CResourceManager.h"

CPlayer::CPlayer()
{
	m_pTex = CResourceManager::getInst()->LoadTextrue(L"PlayerTex", L"texture\\Player.bmp");
}

CPlayer::~CPlayer()
{

}

void CPlayer::update()
{
	fPoint pos = GetPos();

	if (Key(VK_LEFT))
	{
		pos.x -= 100 * fDT;
	}

	if (Key(VK_RIGHT))
	{
		pos.x += 100 * fDT;
	}				   
					   
	if (Key(VK_UP))	   
	{				   
		pos.y -= 100 * fDT;
	}				   
					   
	if (Key(VK_DOWN))  
	{				   
		pos.y += 100 * fDT;
	}

	SetPos(pos);

	if (KeyDown(VK_SPACE))
	{
		CreateMissile();
	}
}

void CPlayer::render(HDC hDC)
{
	int iWidth = (int)(m_pTex->GetBmpWidth());
	int iHeight = (int)(m_pTex->GetBmpHeight());

	fPoint pos = GetPos();

	TransparentBlt(hDC,
		(int)(pos.x - (float)(iWidth / 2)),
		(int)(pos.y - (float)(iHeight / 2)),
		iWidth, iHeight,
		m_pTex->GetDC(),
		0, 0, iWidth, iHeight,
		RGB(255, 0, 255));

	component_render(hDC);
}

void CPlayer::CreateMissile()
{
 	fPoint fpMissilePos = GetPos();
	fpMissilePos.x += GetScale().x / 2.f;

	// Misiile Object
	CMissile* pMissile1 = new CMissile;
	pMissile1->SetPos(fpMissilePos);
	pMissile1->SetScale(fPoint(25.f, 25.f));
	pMissile1->SetDir(fVec2(1, 0));

	CMissile* pMissile2 = new CMissile;
	pMissile2->SetPos(fpMissilePos);
	pMissile2->SetScale(fPoint(25.f, 25.f));
	pMissile2->SetDir(fVec2(1, 1));   

	CMissile* pMissile3 = new CMissile;
	pMissile3->SetPos(fpMissilePos);
	pMissile3->SetScale(fPoint(25.f, 25.f));
	pMissile3->SetDir(fVec2(1, -1));

	CMissile* pMissile4 = new CMissile;
	pMissile4->SetPos(fpMissilePos);
	pMissile4->SetScale(fPoint(25.f, 25.f));
	pMissile4->SetDir(3.141592f);

	CMissile* pMissile5 = new CMissile;
	pMissile5->SetPos(fpMissilePos);
	pMissile5->SetScale(fPoint(25.f, 25.f));
	pMissile5->SetDir(3.141592f * 90 / 180);

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile1, GROUP_GAMEOBJ::MISSILE);
	pCurScene->AddObject(pMissile2, GROUP_GAMEOBJ::MISSILE);
	pCurScene->AddObject(pMissile3, GROUP_GAMEOBJ::MISSILE);
	pCurScene->AddObject(pMissile4, GROUP_GAMEOBJ::MISSILE);
	pCurScene->AddObject(pMissile5, GROUP_GAMEOBJ::MISSILE);
}
