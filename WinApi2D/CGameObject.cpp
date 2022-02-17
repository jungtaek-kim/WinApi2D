#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
	m_ptPos = {};
	m_ptScale = {};
}

CGameObject::CGameObject(POINT pos, POINT scale)
{
	m_ptPos = pos;
	m_ptScale = scale;
}

CGameObject::~CGameObject()
{
}
