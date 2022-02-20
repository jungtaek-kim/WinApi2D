#pragma once

#include "CGameObject.h"

class CTexture;

class CPlayer : public CGameObject
{
private:
	CTexture* m_pTex;

public:
	CPlayer();
	~CPlayer();

	virtual void update();
	virtual void render(HDC hDC);

	void CreateMissile();
};

