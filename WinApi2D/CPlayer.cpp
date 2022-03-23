#include "framework.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CTile.h"

CPlayer* CPlayer::instance = nullptr;

CPlayer::CPlayer()
{
	CD2DImage* m_pImg = CResourceManager::GetInst()->LoadD2DImage(L"PlayerImg", L"texture\\Animation_Player.bmp");
	SetName(L"Player");
	SetScale(fPoint(70.f, 70.f));

	CreateCollider();
	GetCollider()->SetScale(fPoint(40.f, 40.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 10.f));

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"LeftNone",		m_pImg, fPoint(0.f, 0.f),	fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"RightNone",	m_pImg, fPoint(0.f, 70.f),	fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"LeftMove",		m_pImg, fPoint(0.f, 140.f),	fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"RightMove",	m_pImg, fPoint(0.f, 210.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"LeftHit",		m_pImg, fPoint(140.f, 0.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"RightHit",		m_pImg, fPoint(140.f, 70.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 1);
	GetAnimator()->Play(L"LeftNone");

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"LeftMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -20.f);
	pAni = GetAnimator()->FindAnimation(L"RightMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -20.f);

	m_uiGroundCount = 0;
	m_fHorizontalSpeed = 0;
}

CPlayer::~CPlayer()
{
	instance = nullptr;
}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::update()
{
	fPoint pos = GetPos();

	if (Key(VK_LEFT))
	{
		pos.x -= m_fSpeed * fDT;
		GetAnimator()->Play(L"LeftMove");
	}
	if (Key(VK_RIGHT))
	{
		pos.x += m_fSpeed * fDT;
		GetAnimator()->Play(L"RightMove");
	}				   
	if (Key('X'))
	{
		m_fHorizontalSpeed = -300.f;
	}
	pos.y += m_fHorizontalSpeed * fDT;

	SetPos(pos);

	if (KeyDown(VK_SPACE))
	{
		CreateMissile();
		GetAnimator()->Play(L"LeftHit");
	}

	GetAnimator()->update();

	if (m_uiGroundCount > 0)
	{
		m_fHorizontalSpeed = 0.f;
	}
	else
	{
		m_fHorizontalSpeed += fDT * 500.f;
		if (m_fHorizontalSpeed > 500.f)
		{
			m_fHorizontalSpeed = 500.f;
		}
	}
}

void CPlayer::render()
{
	component_render();
}

void CPlayer::OnCollision(CCollider* _pOther)
{
	if (_pOther->GetObj()->GetName() == L"Tile")
	{
		CTile* pTile = (CTile*)(_pOther->GetObj());
		fPoint pos = GetPos();
		fPoint offset = GetCollider()->GetOffsetPos();
		fPoint thisPos = GetCollider()->GetFinalPos();
		fPoint thisScale = GetCollider()->GetScale();
		fPoint otherPos = _pOther->GetFinalPos();
		fPoint otherScale = _pOther->GetScale();

		if (pTile->GetGroup() == GROUP_TILE::GROUND)
		{
			// 바닥과 충돌 처리
			// 계속 밀어내기 - 정해진 위치로 set
			// 위에서 아래로 충돌
			pos.y = otherPos.y - otherScale.y / 2.f - thisScale.y / 2.f - offset.y + 1;

			// 좌우에서 충돌

		}
		else if (pTile->GetGroup() == GROUP_TILE::WALL)
		{
			// 벽과 충돌 처리
		}
		SetPos(pos);
	}
}

void CPlayer::OnCollisionEnter(CCollider* _pOther)
{
	if (_pOther->GetObj()->GetName() == L"Tile")
	{
		CTile* pTile = (CTile*)_pOther->GetObj();
		fPoint thisPos = GetCollider()->GetFinalPos();
		fPoint otherPos = _pOther->GetFinalPos();
		if (pTile->GetGroup() == GROUP_TILE::GROUND)
		{
			// 바닥과 충돌 처리
			m_uiGroundCount++;
		}
		else if (pTile->GetGroup() == GROUP_TILE::WALL)
		{
			// 벽과 충돌 처리
		}
	}
}

void CPlayer::OnCollisionExit(CCollider* _pOther)
{
	if (_pOther->GetObj()->GetName() == L"Tile")
	{
		CTile* pTile = (CTile*)_pOther->GetObj();
		if (pTile->GetGroup() == GROUP_TILE::GROUND)
		{
			// 바닥과 충돌 처리
			m_uiGroundCount--;
		}
		else if (pTile->GetGroup() == GROUP_TILE::WALL)
		{
			// 벽과 충돌 처리
		}
	}
}

void CPlayer::RegisterPlayer()
{
	instance = this;
}

CPlayer* CPlayer::GetPlayer()
{
	return instance;
}

void CPlayer::CreateMissile()
{
 	fPoint fpMissilePos = GetPos();
	fpMissilePos.x += GetScale().x / 2.f;

	// Misiile Object
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fpMissilePos);
	pMissile->SetDir(fVec2(1, 0));
	pMissile->SetName(L"Missile_Player");

	CreateObj(pMissile, GROUP_GAMEOBJ::MISSILE_PLAYER);
}
