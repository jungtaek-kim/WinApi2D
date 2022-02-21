#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"

#include "SelectGDI.h"

CCollider::CCollider()
{
	m_pOwner = nullptr;
	m_fptOffsetPos = {};
	m_fptFinalPos = {};
	m_fptScale = {};
}

CCollider::~CCollider()
{
}

fPoint CCollider::GetOffsetPos()
{
	return m_fptOffsetPos;
}

fPoint CCollider::GetFinalPos()
{
	return m_fptFinalPos;
}

fPoint CCollider::GetScale()
{
	return m_fptScale;
}

void CCollider::SetOffsetPos(fPoint offsetPos)
{
	m_fptOffsetPos = offsetPos;
}

void CCollider::SetFinalPos(fPoint finalPos)
{
	m_fptFinalPos = finalPos;
}

void CCollider::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

void CCollider::finalupdate()
{
	fPoint fptObjectPos = m_pOwner->GetPos();
	m_fptFinalPos = fptObjectPos + m_fptOffsetPos;
}

void CCollider::render(HDC hDC)
{
	SelectGDI brush(hDC, TYPE_BRUSH::HOLLOW);
	SelectGDI pen(hDC, TYPE_PEN::GREEN);

	Rectangle(hDC,
		(int)(m_fptFinalPos.x - m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y - m_fptScale.y / 2.f),
		(int)(m_fptFinalPos.x + m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y + m_fptScale.y / 2.f));
}
