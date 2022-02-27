#include "framework.h"
#include "CGameObject.h"
#include "CCollider.h"

CGameObject::CGameObject()
{
	m_fptPos = {};
	m_fptScale = {};
	m_pCollider = nullptr;
	m_bAlive = true;
}

CGameObject::CGameObject(const CGameObject& other)
{
	m_strName	= other.m_strName;
	m_fptPos	= other.m_fptPos;
	m_fptScale	= other.m_fptScale;
	m_pCollider = nullptr;
	m_bAlive	= true;

	if (nullptr != other.m_pCollider)
	{
		m_pCollider = new CCollider(*other.m_pCollider);
		m_pCollider->m_pOwner = this;
	}
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

void CGameObject::SetName(wstring name)
{
	m_strName = name;
}

fPoint CGameObject::GetPos()
{
	return m_fptPos;
}

fPoint CGameObject::GetScale()
{
	return m_fptScale;
}

wstring CGameObject::GetName()
{
	return m_strName;
}

bool CGameObject::isDead()
{
	return !m_bAlive;
}

void CGameObject::SetDead()
{
	m_bAlive = false;
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

	component_render(hDC);
}

void CGameObject::component_render(HDC hDC)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->render(hDC);
	}
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
