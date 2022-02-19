#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
}

void CGameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

void CGameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

fPoint CGameObject::GetPos()
{
	return m_fptPos;
}

fPoint CGameObject::GetScale()
{
	return m_fptScale;
}

void CGameObject::render(HDC hDC)
{
	Rectangle(hDC,
		(int)(m_fptPos.x - m_fptScale.x / 2),
		(int)(m_fptPos.y - m_fptScale.y / 2),
		(int)(m_fptPos.x + m_fptScale.x / 2),
		(int)(m_fptPos.y + m_fptScale.y / 2));
}
