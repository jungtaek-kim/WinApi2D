#include "framework.h"
#include "CScene_Tool.h"
#include "CTile.h"

CScene_Tool::CScene_Tool()
{
}

CScene_Tool::~CScene_Tool()
{
}

void CScene_Tool::update()
{
	CScene::update();

	if (KeyDown(VK_ESCAPE))
	{
		ChangeScn(GROUP_SCENE::START);
	}
}

void CScene_Tool::Enter()
{
	// Tile »ý¼º
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			CTile* pTile = new CTile();
			pTile->SetPos(fPoint((float)(j * CTile::SIZE_TILE), (float)(i * CTile::SIZE_TILE)));
			AddObject(pTile, GROUP_GAMEOBJ::TILE);
		}
	}

	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));
}

void CScene_Tool::Exit()
{
}
