#pragma once

class CUI;

class CUIManager
{
	SINGLETON(CUIManager);

private:
	CUI* m_pFocusedUI;

public:
	void update();

private:
	CUI* GetFocusedUI();
	CUI* GetTargetedUI(CUI* pParentUI);
};

