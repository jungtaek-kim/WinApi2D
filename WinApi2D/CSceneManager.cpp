#include "framework.h"
#include "CSceneManager.h"

#include "CScene_Start.h"

CSceneManager::CSceneManager()
{
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurScene = nullptr;
}

CSceneManager::~CSceneManager()
{
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneManager::update()
{
	m_pCurScene->update();
	m_pCurScene->finalupdate();
}

void CSceneManager::render(HDC hDC)
{
	m_pCurScene->render(hDC);
}

void CSceneManager::init()
{
	m_arrScene[(size_t)GROUP_SCENE::START] = new CScene_Start;
	m_arrScene[(size_t)GROUP_SCENE::START]->SetName(L"Start_Scene");

	m_pCurScene = m_arrScene[(size_t)GROUP_SCENE::START];
	m_pCurScene->Enter();
}

CScene* CSceneManager::GetCurScene()
{
	return m_pCurScene;
}
