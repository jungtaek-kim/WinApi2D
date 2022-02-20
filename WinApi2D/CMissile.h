#pragma once
#include "CGameObject.h"

class CMissile : public CGameObject
{
private:
	float m_fXDir;
	float m_fYDir;
	float m_fVelocity;

public:
	CMissile();
	~CMissile();

	virtual void update();
	virtual void render(HDC hDC);

	void SetDir(float x, float y);
};

