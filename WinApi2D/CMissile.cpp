#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fXDir = 0;
	m_fYDir = 0;
	m_fVelocity = 50;
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fPoint pos = GetPos();

	pos.x += m_fVelocity * m_fXDir * DT;
	pos.y += m_fVelocity * m_fYDir * DT;

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

void CMissile::SetDir(float x, float y)
{
	m_fXDir = x;
	m_fYDir = y;
}
