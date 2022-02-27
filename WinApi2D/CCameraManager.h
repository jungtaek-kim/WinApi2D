#pragma once

class CGameObject;

class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;			// ���� �ִ� ��ġ
	CGameObject* m_pTargetObj;	// Ʈ��ŷ �� ������Ʈ

	fPoint m_fptDiff;			// �ػ� �߽ɰ� ī�޶� LookAt ������ ����

public:
	void update();

	void SetLookAt(fPoint lookAt);
	void SetTargetObj(CGameObject* target);

	fPoint GetRenderPos(fPoint objPos);

	void CalDiff();
};

