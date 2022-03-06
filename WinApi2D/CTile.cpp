#include "framework.h"
#include "CTile.h"

CTile::CTile()
{
	SetScale(fPoint(SIZE_TILE, SIZE_TILE));
}

CTile::~CTile()
{
}

CTile* CTile::Clone()
{
	return new CTile(*this);
}

void CTile::update()
{
}

void CTile::render(HDC hDC)
{
	fPoint fptRenderPos = CCameraManager::getInst()->GetRenderPos(GetPos());
	fPoint fptScale = GetScale();

	Rectangle(hDC,
		(int)(fptRenderPos.x),
		(int)(fptRenderPos.y),
		(int)(fptRenderPos.x + fptScale.x),
		(int)(fptRenderPos.y + fptScale.y));
}
