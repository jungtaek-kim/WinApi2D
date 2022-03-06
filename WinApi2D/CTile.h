#pragma once
#include "CGameObject.h"
class CTile : public CGameObject
{
public:
	const static int SIZE_TILE = 16;

	CTile();
	virtual ~CTile();

	virtual CTile* Clone();

private:
	virtual void update();
	virtual void render(HDC hDC);

};

