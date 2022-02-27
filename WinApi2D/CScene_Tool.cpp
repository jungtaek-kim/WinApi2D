#include "framework.h"
#include "CScene_Tool.h"

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
}

void CScene_Tool::Exit()
{
}
