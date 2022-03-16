#include "framework.h"
#include "CMonster.h"
#include "CCollider.h"
#include "CD2DImage.h"
#include "CAnimator.h"
#include "AI.h"

CMonster* CMonster::Clone()
{
	return new CMonster(*this);
}

CMonster::CMonster()
{
	m_fptCenterPos = fPoint(0, 0);
	m_fVelocity = 0;
	m_fDistance = 300;
	m_bIsUPDir = true;

	SetName(L"Monster");
	SetScale(fPoint(100, 100));

	CreateCollider();
	GetCollider()->SetScale(fPoint(90.f, 90.f));

	m_pImg = CResourceManager::getInst()->LoadD2DImage(L"MonsterTex", L"texture\\PlayerStand.png");

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"PlayerStand", m_pImg, fPoint(0, 0), fPoint(32.f, 32.f), fPoint(32.f, 0), 0.1f, 5, true);
	GetAnimator()->Play(L"PlayerStand");
}

CMonster::~CMonster()
{
	if (nullptr != m_pAI)
	{
		delete m_pAI;
	}
}

void CMonster::render()
{
	fPoint pos = GetPos();
 	fPoint scale = GetScale();
	pos = CCameraManager::getInst()->GetRenderPos(pos);

	component_render();

	/*CRenderManager::getInst()->RenderImage(
		m_pImg,
		pos.x,
		pos.y,
		pos.x + scale.x,
		pos.y + scale.y);*/
}

void CMonster::update()
{
	fPoint pos = GetPos();

	if (m_bIsUPDir)
	{
		pos.y -= fDT * m_fVelocity;
		if (pos.y < m_fptCenterPos.y - m_fDistance)
			m_bIsUPDir = false;
	}
	else
	{
		pos.y += fDT * m_fVelocity;
		if (pos.y > m_fptCenterPos.y + m_fDistance)
			m_bIsUPDir = true;
	}

	SetPos(pos);

	if (nullptr != GetAnimator())
		GetAnimator()->update();
	if (nullptr != m_pAI)
		m_pAI->update();

}

void CMonster::SetAI(AI* ai)
{
	m_pAI = ai;
	m_pAI->m_pOwner = this;
}

void CMonster::SetCenterPos(fPoint point)
{
	m_fptCenterPos = point;
}

void CMonster::OnCollisionEnter(CCollider* pOther)
{

}