#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"

CScene::CScene()
{
    m_strName = L"";
}

CScene::~CScene()
{
    // 씬이 가진 모든 게임오브젝트 삭제
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
    // 씬이 가진 모든 오브젝트 업데이트
    for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
    {
        for (int j = 0; j < m_arrObj[i].size(); j++)
        {
            if (!m_arrObj[i][j]->isDead())
                m_arrObj[i][j]->update();
        }
    }
}

void CScene::finalupdate()
{
    // 씬이 가진 모든 오브젝트 finalupdate
    for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
    {
        for (int j = 0; j < m_arrObj[i].size(); j++)
        {
            m_arrObj[i][j]->finalupdate();
        }
    }
}

void CScene::render(HDC hDC)
{
    // 씬이 가진 모든 오브젝트 render
    for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
    {
        for (vector<CGameObject*>::iterator iter = m_arrObj[i].begin();
            iter != m_arrObj[i].end(); )
        {
            if (!(*iter)->isDead())
            {
                (*iter)->render(hDC);
                iter++;
            }
            else
            {
                iter = m_arrObj[i].erase(iter);
            }
        }
    }
}

const vector<CGameObject*>& CScene::GetGroupObject(GROUP_GAMEOBJ group)
{
    return m_arrObj[(UINT)group];
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

void CScene::DeleteGroup(GROUP_GAMEOBJ group)
{
    for (int i = 0; i < m_arrObj[(UINT)group].size(); i++)
    {
        delete m_arrObj[(UINT)group][i];
    }
    m_arrObj[(UINT)group].clear();
}

void CScene::DeleteAll()
{
    for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
    {
        DeleteGroup((GROUP_GAMEOBJ)i);
    }
}
