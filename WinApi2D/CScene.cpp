#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"

CScene::CScene()
{
    m_strName = L"";
}

CScene::~CScene()
{
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
