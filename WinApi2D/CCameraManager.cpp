#include "framework.h"
#include "CCameraManager.h"
#include "CGameObject.h"

CCameraManager::CCameraManager()
{
	m_fptLookAt = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);
	m_fptCurLookAt = m_fptLookAt;
	m_fptPrevLookAt = m_fptLookAt;
	m_pTargetObj = nullptr;
	m_fAccTime = m_fTime;
	m_fSpeed = 0;
	m_fPreSpeed = m_fSpeed;
	m_fAccel = 0;
}

CCameraManager::~CCameraManager()
{

}

void CCameraManager::update()
{
	if (m_pTargetObj)
	{
		if (m_pTargetObj->isDead())
		{
			m_pTargetObj = nullptr;
		}
		else
		{
			SetLookAt(m_pTargetObj->GetPos());
		}
	}

	// ȭ�� �߾Ӱ� ī�޶� LookAt ��ǥ ������ ���� ���
	CalDiff();
}

void CCameraManager::SetLookAt(fPoint lookAt)
{
	m_fptLookAt = lookAt;
	float fMoveDist = (m_fptLookAt - m_fptPrevLookAt).Length();
	m_fAccel = fMoveDist / m_fTime;		// ��ӵ� ���
	m_fAccel *= m_fAccDir;

	if (m_fAccDir < 0) // �ʱ� �ӵ� ����
	{
		m_fSpeed = fMoveDist;
	}
	else
	{
		m_fSpeed = 0.f;
	}
	m_fAccTime = 0.f;
}

void CCameraManager::SetTargetObj(CGameObject* target)
{
	m_pTargetObj = target;
}

fPoint CCameraManager::GetLookAt()
{
	return m_fptCurLookAt;
}

fPoint CCameraManager::GetRenderPos(fPoint objPos)
{
	return objPos - m_fptDiff;
}

fPoint CCameraManager::GetRealPos(fPoint renderPos)
{
	// ������ ��ǥ���� ���̰���ŭ �����ָ� ���� ��ǥ�� ����.
	return renderPos + m_fptDiff;
}

void CCameraManager::CalDiff()
{
	m_fAccTime += fDT;

	fVec2 fvLookDir = m_fptLookAt - m_fptPrevLookAt;

	// �ð��� �����ų� ���� ������ ũ�Ⱑ 0�̶��, �����Ѱ����� ����. �ӵ��� 0����
	if (m_fTime <= m_fAccTime || fvLookDir.Length() == 0)
	{
		m_fptCurLookAt = m_fptLookAt;
		m_fSpeed = 0.f;
	}
	else
	{
		m_fptCurLookAt = m_fptPrevLookAt + fvLookDir.normalize() * m_fSpeed * fDT;
	}

	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);

	m_fptDiff = m_fptCurLookAt - fptCenter;
	m_fptPrevLookAt = m_fptCurLookAt;
	m_fPreSpeed = m_fSpeed;

	// ��ӵ���ŭ �����ӵ��� ������.
	m_fSpeed = m_fPreSpeed += m_fAccel * fDT;
}
