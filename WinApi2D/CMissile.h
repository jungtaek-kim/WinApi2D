#pragma once
#include "CGameObject.h"

class CMissile : public CGameObject
{
private:
	bool m_bDir;
	float m_fVelocity;

public:
	CMissile();
	~CMissile();

	virtual void update();

	void SetDir(bool dir);
};

