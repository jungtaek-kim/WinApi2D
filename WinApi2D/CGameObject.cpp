#include "framework.h"
#include "CGameObject.h"
#include "CCollider.h"

CGameObject::CGameObject()
{
	m_fptPos = {};
	m_fptScale = {};
	m_pCollider = nullptr;
}

CGameObject::~CGameObject()
{
	if (nullptr != m_pCollider)
	{
		delete m_pCollider;
	}
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

void CGameObject::finalupdate()
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->finalupdate();
	}
}

void CGameObject::render(HDC hDC)
{
	Rectangle(hDC,
		(int)(m_fptPos.x - m_fptScale.x / 2),
		(int)(m_fptPos.y - m_fptScale.y / 2),
		(int)(m_fptPos.x + m_fptScale.x / 2),
		(int)(m_fptPos.y + m_fptScale.y / 2));
}

CCollider* CGameObject::GetCollider()
{
	return m_pCollider;
}

void CGameObject::CreateCollider()
{
	m_pCollider = new CCollider();
	m_pCollider->m_pOwner = this;
}
