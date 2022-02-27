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

	// 화면 중앙과 카메라 LookAt 좌표 사이의 차이 계산
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
	// 렌더링 좌표에서 차이값만큼 더해주면 절대 좌표가 나옴.
	return renderPos + m_fptDiff;
}

void CCameraManager::CalDiff()
{
	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);

	m_fptDiff = m_fptCurLookAt - fptCenter;

	// 목적지에서 이전 카메라 위치를 빼면, 방향 백터가 나옴
	fVec2 vLookDir = m_fptLookAt - m_fptPrevLookAt;
	// 구한 방향 벡터를 단위 벡터로 만들고, 내가 원하는 속도로 이동하게끔 구현.
	m_fptCurLookAt = m_fptPrevLookAt + vLookDir.normalize() * 500.f * fDT;

	// 둘이 차이가 생겼어도. 계산이 다 끝나면 똑같이 만듦.
	m_fptPrevLookAt = m_fptCurLookAt;
}
