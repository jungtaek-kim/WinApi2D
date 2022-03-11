#pragma once

class CUI;

class CUIManager
{
	SINGLETON(CUIManager);

private:

public:
	void update();

private:
	CUI* GetTargetUI(CUI* pParentUI);
};

