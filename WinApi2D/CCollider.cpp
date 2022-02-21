#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"

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
	HPEN hGreenPen = CCore::getInst()->GetPen(TYPE_PEN::GREEN);
	HPEN hDefaultPen = (HPEN)SelectObject(hDC, hGreenPen);

	HBRUSH hHollowBrush = CCore::getInst()->GetBrush(TYPE_BRUSH::HOLLOW);
	HBRUSH hDefaultBrush = (HBRUSH)SelectObject(hDC, hHollowBrush);

	Rectangle(hDC,
		m_fptFinalPos.x - m_fptScale.x / 2.f,
		m_fptFinalPos.y - m_fptScale.y / 2.f,
		m_fptFinalPos.x + m_fptScale.x / 2.f,
		m_fptFinalPos.y + m_fptScale.y / 2.f);

	(HPEN)SelectObject(hDC, hDefaultPen);
	(HBRUSH)SelectObject(hDC, hDefaultBrush);
}
