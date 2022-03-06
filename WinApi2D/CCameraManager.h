#pragma once

class CGameObject;

class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;			// 보고 있는 위치
	fPoint m_fptCurLookAt;		// 카메라가 지금 보는 위치
	fPoint m_fptPrevLookAt;		// 카메라가 이전에 보던 위치
	CGameObject* m_pTargetObj;	// 트래킹 할 오브젝트

	fPoint m_fptDiff;			// 해상도 중심과 카메라 LookAt 사이의 차이

	float m_fTime = 1;			// 타겟을 따라가는 총시간
	float m_fAccTime;			// 타겟을 따라간 소요시간
	float m_fSpeed;				// 타겟을 따라가는 속도

	void CalDiff();

public:
	void update();

	void SetLookAt(fPoint lookAt);
	void SetTargetObj(CGameObject* target);

	fPoint GetLookAt();			// 현재 카메라 위치 반환
	fPoint GetRenderPos(fPoint objPos);
	fPoint GetRealPos(fPoint renderPos);

	void Scroll(fVec2 vec, float velocity);
};

