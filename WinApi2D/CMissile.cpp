#include "framework.h"
#include "CMissile.h"
#include "CCollider.h"

CMissile::CMissile()
{
	SetScale(fPoint(25.f, 25.f));
	m_fvDir = fVec2(0, 0);

	CreateCollider();
	GetCollider()->SetScale(fPoint(15.f, 15.f));
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fPoint pos = GetPos();

	pos.x += m_fVelocity * m_fvDir.x * fDT;
	pos.y += m_fVelocity * m_fvDir.y * fDT;

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

	component_render(hDC);
}

void CMissile::SetDir(fVec2 vec)
{
	m_fvDir = vec.normalize();
}

void CMissile::SetDir(float theta)
{
	m_fvDir.x = (float)cos(theta);
	m_fvDir.y = (float)sin(theta);
}
