#include "framework.h"
#include "CPanelUI.h"

CPanelUI::CPanelUI()
	: CUI(false)
{
	m_fptDragStart = {};
}

CPanelUI::~CPanelUI()
{
}

void CPanelUI::MouseOn()
{
	if (IsLbtnDown())
	{
		fPoint fptDiff = MousePos() - m_fptDragStart;

		fPoint fptCurPos = GetPos();
		fptCurPos += fptDiff;
		SetPos(fptCurPos);

		m_fptDragStart = MousePos();
	}
}

void CPanelUI::MouseLbtnDown()
{
	m_fptDragStart = MousePos();
}

void CPanelUI::MouseLbtnUp()
{
}
