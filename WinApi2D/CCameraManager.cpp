#include "framework.h"
#include "CCameraManager.h"
#include "CGameObject.h"

CCameraManager::CCameraManager()
{
	m_pTargetObj = nullptr;
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
	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);

	m_fptDiff = m_fptCurLookAt - fptCenter;

	// ���������� ���� ī�޶� ��ġ�� ����, ���� ���Ͱ� ����
	fVec2 vLookDir = m_fptLookAt - m_fptPrevLookAt;
	// ���� ���� ���͸� ���� ���ͷ� �����, ���� ���ϴ� �ӵ��� �̵��ϰԲ� ����.
	m_fptCurLookAt = m_fptPrevLookAt + vLookDir.normalize() * 500.f * fDT;

	// ���� ���̰� ����. ����� �� ������ �Ȱ��� ����.
	m_fptPrevLookAt = m_fptCurLookAt;
}
