#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::CGameObject(fPoint pos, fPoint scale)
{
	m_fptPos = pos;
	m_fptScale = scale;
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

void CGameObject::update()
{
	if (CKeyManager::getInst()->GetButton(VK_LEFT))
	{
		m_fptPos.x -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_RIGHT))
	{
		m_fptPos.x += 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_UP))
	{
		m_fptPos.y -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_DOWN))
	{
		m_fptPos.y += 100 * CTimeManager::getInst()->GetDT();
	}
}

void CGameObject::render(HDC hDC)
{
	Rectangle(hDC,
		m_fptPos.x - m_fptScale.x / 2,
		m_fptPos.y - m_fptScale.y / 2,
		m_fptPos.x + m_fptScale.x / 2,
		m_fptPos.y + m_fptScale.y / 2);
}
