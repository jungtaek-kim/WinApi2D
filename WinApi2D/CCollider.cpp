#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"

CCollider::CCollider()
{
	m_pOwner = nullptr;
}

CCollider::~CCollider()
{
}

void CCollider::finalupdate()
{
	fPoint fptObjectPos = m_pOwner->GetPos();
	m_fptFinalPos = fptObjectPos + m_fptOffsetPos;
}
