#pragma once

#include "CGameObject.h"

class CPlayer : public CGameObject
{
public:
	virtual void update();
	virtual void render(HDC hDC);
};

