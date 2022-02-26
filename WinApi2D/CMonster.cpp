#include "framework.h"
#include "CMonster.h"
#include "CCollider.h"

CMonster::CMonster()
{
	m_fptCenterPos = fPoint(0, 0);
	m_fVelocity = 200;
	m_fDistance = 300;
	m_bIsUPDir = true;

	CreateCollider();
	GetCollider()->SetScale(fPoint(90.f, 90.f));
}

CMonster::~CMonster()
{
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
}

void CMonster::SetCenterPos(fPoint point)
{
	m_fptCenterPos = point;
}
