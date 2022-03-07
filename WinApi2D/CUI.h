#pragma once
#include "CGameObject.h"
class CUI : public CGameObject
{
private:
	vector<CUI*> m_vecChildUI;	// 자식 UI를 계층적 구조로 구현
	CUI* m_pParentUI;

	fPoint m_fptFinalPos;

public:
	CUI();
	virtual ~CUI();

	virtual CUI* Clone();

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC hDC);

	void update_child();
	void finalupdate_child();
	void render_child(HDC hDC);

	virtual void MouseOn();
	virtual void MouseLbtnDown();
	virtual void MouseLbtnUp();
	virtual void MouseLbtnClicked();

	fPoint GetFinalPos();

	CUI* GetParent();
	void AddChild(CUI* pUI);
};

