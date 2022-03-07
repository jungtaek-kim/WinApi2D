#pragma once
#include "CUI.h"
class CButtonUI : public CUI
{
public:
	CButtonUI();
	~CButtonUI();

	virtual CButtonUI* Clone();

	virtual void MouseOn();
	virtual void MouseLbtnDown();
	virtual void MouseLbtnUp();
};

