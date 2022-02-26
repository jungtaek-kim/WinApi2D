#pragma once

#include "CGameObject.h"

class CTexture;

class CPlayer : public CGameObject
{
private:
	CTexture* m_pTex;

	float m_fVelocity = 300;

public:
	CPlayer();
	~CPlayer();

	virtual void update();
	virtual void render(HDC hDC);

	void CreateMissile();
};

