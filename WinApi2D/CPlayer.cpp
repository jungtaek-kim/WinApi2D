#include "framework.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"

CPlayer::CPlayer()
{
	m_pTex = CResourceManager::getInst()->LoadTextrue(L"PlayerTex", L"texture\\Player.bmp");

	CreateCollider();
	GetCollider()->SetScale(fPoint(40.f, 40.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 10.f));
}

CPlayer::~CPlayer()
{

}

void CPlayer::update()
{
	fPoint pos = GetPos();

	if (Key(VK_LEFT))
	{
		pos.x -= m_fVelocity * fDT;
	}

	if (Key(VK_RIGHT))
	{
		pos.x += m_fVelocity * fDT;
	}				   
					   
	if (Key(VK_UP))	   
	{				   
		pos.y -= m_fVelocity * fDT;
	}				   
					   
	if (Key(VK_DOWN))  
	{				   
		pos.y += m_fVelocity * fDT;
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
	CMissile* pMissile = new CMissile;
	pMissile->SetName(L"MISSILE_PLAYER");
	pMissile->SetPos(fpMissilePos);
	pMissile->SetDir(fVec2(1, 0));

	CreateObj(pMissile, GROUP_GAMEOBJ::MISSILE_PLAYER);
}
