#pragma once
#include "CGameObject.h"
class CUI : public CGameObject
{
public:
	CUI();
	virtual ~CUI();

	virtual CUI* Clone();

	virtual void update();
	virtual void render(HDC hDC);


};

