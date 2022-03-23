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

	virtual void OnCollision(CCollider* _pOther);			// 재정의용 충돌중 가상함수
	virtual void OnCollisionEnter(CCollider* _pOther);	// 재정의용 충돌시 가상함수
	virtual void OnCollisionExit(CCollider* _pOther);		// 재정의용 탈충돌 가상함수

	void RegisterPlayer();
	static CPlayer* GetPlayer();	// 게임 내에 하나만 있는 플레이어 객체 확인(임의로 싱글톤 선언)
};

