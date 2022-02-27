#pragma once

class CGameObject;

class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;			// ���� �ִ� ��ġ
	fPoint m_fptCurLookAt;		// ī�޶� ���� ���� ��ġ
	fPoint m_fptPrevLookAt;		// ī�޶� ������ ���� ��ġ
	CGameObject* m_pTargetObj;	// Ʈ��ŷ �� ������Ʈ

	fPoint m_fptDiff;			// �ػ� �߽ɰ� ī�޶� LookAt ������ ����

	void CalDiff();

public:
	void update();

	void SetLookAt(fPoint lookAt);
	void SetTargetObj(CGameObject* target);

	fPoint GetLookAt();			// ���� ī�޶� ��ġ ��ȯ
	fPoint GetRenderPos(fPoint objPos);
	fPoint GetRealPos(fPoint renderPos);
};

