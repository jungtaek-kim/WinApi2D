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

	m_fSpeed = fMoveDist / m_fTime;
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

void CCameraManager::Scroll(fVec2 vec, float velocity)
{
	m_fptLookAt = m_fptLookAt + vec * velocity * fDT;
	m_fptCurLookAt = m_fptCurLookAt + vec * velocity * fDT;

	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);
	m_fptDiff = m_fptCurLookAt - fptCenter;
}

void CCameraManager::CalDiff()
{
	m_fAccTime += fDT;

	// �ð��� ������, �����Ѱ����� ����
	if (m_fTime <= m_fAccTime)
	{
		m_fptCurLookAt = m_fptLookAt;
	}
	else
	{
		fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);

		m_fptCurLookAt = m_fptPrevLookAt + (m_fptLookAt - m_fptPrevLookAt).normalize() * m_fSpeed * fDT;
		m_fptDiff = m_fptCurLookAt - fptCenter;
		m_fptPrevLookAt = m_fptCurLookAt;
	}
}
