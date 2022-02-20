#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_bDir = true;
	m_fVelocity = 600;
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fPoint pos = GetPos();

	if (m_bDir)
	{
		pos.x += m_fVelocity * DT;
	}
	else
	{
		pos.x -= m_fVelocity * DT;
	}

	SetPos(pos);
}

void CMissile::render(HDC hDC)
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();

	Ellipse(hDC,
		(int)(pos.x - scale.x / 2.f),
		(int)(pos.y - scale.y / 2.f),
		(int)(pos.x + scale.x / 2.f),
		(int)(pos.y + scale.y / 2.f));
}

void CMissile::SetDir(bool dir)
{
	m_bDir = dir;
}
