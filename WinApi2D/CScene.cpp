#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"

CScene::CScene()
{
    m_strName = L"";
}

CScene::~CScene()
{
    for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
    {
        for (int j = 0; j < m_arrObj[i].size(); j++)
        {
            delete m_arrObj[i][j];
        }
    }
}

void CScene::update()
{
    for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
    {
        for (int j = 0; j < m_arrObj[i].size(); j++)
        {
            m_arrObj[i][j]->update();
        }
    }
}

void CScene::render(HDC hDC)
{
    for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
    {
        for (int j = 0; j < m_arrObj[i].size(); j++)
        {
            m_arrObj[i][j]->render(hDC);
        }
    }
}

void CScene::SetName(const wstring& strName)
{
    m_strName = strName;
}

wstring CScene::GetName()
{
    return m_strName;
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{
    m_arrObj[(int)type].push_back(pObj);
}
