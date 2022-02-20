#pragma once
#include "CGameObject.h"

class CMissile : public CGameObject
{
private:
	fVec2 m_fvDir;
	float m_fVelocity;

public:
	CMissile();
	~CMissile();

	virtual void update();
	virtual void render(HDC hDC);

	void SetDir(fVec2 vec);
	void SetDir(float theta);
};
