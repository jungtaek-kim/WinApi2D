#pragma once

class CUI;

class CUIManager
{
	SINGLETON(CUIManager);

public:
	void update();

private:
	CUI* GetTargetUI(CUI* pParentUI);
};

