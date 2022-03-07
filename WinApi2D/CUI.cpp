#include "framework.h"
#include "CUI.h"

CUI::CUI()
{
}

CUI::~CUI()
{
}

CUI* CUI::Clone()
{
	return new CUI(*this);
}

void CUI::update()
{
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
}
