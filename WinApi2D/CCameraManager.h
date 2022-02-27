#pragma once

class CGameObject;

class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;			// 보고 있는 위치
	CGameObject* m_pTargetObj;	// 트래킹 할 오브젝트

	fPoint m_fptDiff;			// 해상도 중심과 카메라 LookAt 사이의 차이

public:
	void update();

	void SetLookAt(fPoint lookAt);
	void SetTargetObj(CGameObject* target);

	fPoint GetRenderPos(fPoint objPos);

	void CalDiff();
};

