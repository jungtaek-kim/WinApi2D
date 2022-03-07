#include "framework.h"
#include "CUI.h"

CUI::CUI()
{
	m_pParentUI = nullptr;
}

CUI::~CUI()
{
	for (int i = 0; i < m_vecChildUI.size(); i++)
	{
		if (nullptr != m_vecChildUI[i])
			delete m_vecChildUI[i];
	}
}

CUI* CUI::Clone()
{
	return new CUI(*this);
}

void CUI::update()
{
	update_child();
}

void CUI::finalupdate()
{
	CGameObject::finalupdate();

	m_fptFinalPos = GetPos();
	if (GetParent())
	{
		fPoint fptParentPos = GetParent()->GetFinalPos();
		m_fptFinalPos += fptParentPos;
	}

	finalupdate_child();
}

void CUI::render(HDC hDC)
{
	fPoint fptPos = GetPos();
	fPoint fptScale = GetScale();

	Rectangle(hDC,
		(int)(fptPos.x),
		(int)(fptPos.y),
		(int)(fptPos.x + fptScale.x),
		(int)(fptPos.y + fptScale.y));

	render_child(hDC);
}

void CUI::update_child()
{
	for (UINT i = 0; i < m_vecChildUI.size(); i++)
	{
		m_vecChildUI[i]->update();
	}
}

void CUI::finalupdate_child()
{
	for (UINT i = 0; i < m_vecChildUI.size(); i++)
	{
		m_vecChildUI[i]->finalupdate();
	}
}

void CUI::render_child(HDC hDC)
{
	for (UINT i = 0; i < m_vecChildUI.size(); i++)
	{
		m_vecChildUI[i]->render(hDC);
	}
}

fPoint CUI::GetFinalPos()
{
	return m_fptFinalPos;
}

CUI* CUI::GetParent()
{
	return m_pParentUI;
}

void CUI::AddChild(CUI* pUI)
{
	m_vecChildUI.push_back(pUI);
	pUI->m_pParentUI = this;
}
