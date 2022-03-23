#pragma once

#include "CGameObject.h"

class CD2DImage;

class CPlayer : public CGameObject
{
private:
	static CPlayer* instance;
	float m_fSpeed = 300;
	float m_fHorizontalSpeed;

	UINT m_uiGroundCount;

	void CreateMissile();

public:
	CPlayer();
	~CPlayer();
	virtual CPlayer* Clone();

	virtual void update();
	virtual void render();

	virtual void OnCollision(CCollider* _pOther);			// �����ǿ� �浹�� �����Լ�
	virtual void OnCollisionEnter(CCollider* _pOther);	// �����ǿ� �浹�� �����Լ�
	virtual void OnCollisionExit(CCollider* _pOther);		// �����ǿ� Ż�浹 �����Լ�

	void RegisterPlayer();
	static CPlayer* GetPlayer();	// ���� ���� �ϳ��� �ִ� �÷��̾� ��ü Ȯ��(���Ƿ� �̱��� ����)
};

