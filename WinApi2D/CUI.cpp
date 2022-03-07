#include "framework.h"
#include "CUI.h"
#include "SelectGDI.h"

CUI::CUI(bool bCameraAffected)
{
	m_pParentUI = nullptr;
	m_bCameraAffected = false;
	m_bMouseOn = false;
	m_bLbtnDown = false;
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

	MouseOnCheck();

	finalupdate_child();
}

void CUI::render(HDC hDC)
{
	fPoint fptPos = GetFinalPos();
	fPoint fptScale = GetScale();

	if (m_bCameraAffected)	// 카메라 영향 받으면 랜더링 좌표로
	{
		fptPos = CCameraManager::getInst()->GetRenderPos(fptPos);
	}

	if (m_bLbtnDown)
	{
		SelectGDI green(hDC, TYPE_PEN::GREEN);
		
		Rectangle(hDC,
			(int)(fptPos.x),
			(int)(fptPos.y),
			(int)(fptPos.x + fptScale.x),
			(int)(fptPos.y + fptScale.y));
	}
	else
	{
		Rectangle(hDC,
			(int)(fptPos.x),
			(int)(fptPos.y),
			(int)(fptPos.x + fptScale.x),
			(int)(fptPos.y + fptScale.y));
	}

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

void CUI::MouseOn()
{
	int a = 0;
}

void CUI::MouseLbtnDown()
{
	int a = 0;
}

void CUI::MouseLbtnUp()
{
	int a = 0;
}

void CUI::MouseLbtnClicked()
{
	int a = 0;
}

fPoint CUI::GetFinalPos()
{
	return m_fptFinalPos;
}

bool CUI::GetCameraAffected()
{
	return m_bCameraAffected;
}

bool CUI::IsMouseOn()
{
	return m_bMouseOn;
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

void CUI::MouseOnCheck()
{
	fPoint fptMousePos = MousePos();
	fPoint fptScale = GetScale();

	if (m_bCameraAffected)
	{
		fptMousePos = CCameraManager::getInst()->GetRenderPos(fptMousePos);
	}

	if (m_fptFinalPos.x <= fptMousePos.x && fptMousePos.x <= m_fptFinalPos.x + fptScale.x
		&& m_fptFinalPos.y <= fptMousePos.y && fptMousePos.y <= m_fptFinalPos.y + fptScale.y)
	{
		m_bMouseOn = true;
	}
	else
	{
		m_bMouseOn = false;
	}
}