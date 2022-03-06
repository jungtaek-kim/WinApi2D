#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"
#include "CTile.h"

CScene::CScene()
{
    m_strName = L"";
    m_iTileX = 0;
    m_iTileY = 0;
}

CScene::~CScene()
{
    // ���� ���� ��� ���ӿ�����Ʈ ����
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
    // ���� ���� ��� ������Ʈ ������Ʈ
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
    // ���� ���� ��� ������Ʈ finalupdate
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
    // ���� ���� ��� ������Ʈ render
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

UINT CScene::GetTileX()
{
    return m_iTileX;
}

UINT CScene::GetTileY()
{
    return m_iTileY;
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

void CScene::CreateTile(UINT xSize, UINT ySize)
{
    m_iTileX = xSize;
    m_iTileY = ySize;

    CTexture* pTex = CResourceManager::getInst()->LoadTextrue(L"Tile", L"texture\\tile\\tilemap.bmp");

    for (UINT i = 0; i < ySize; i++)
    {
        for (UINT j = 0; j < xSize; j++)
        {
            CTile* pTile = new CTile();
            pTile->SetPos(fPoint((float)(j * CTile::SIZE_TILE), (float)(i * CTile::SIZE_TILE)));
            pTile->SetTexture(pTex);
            AddObject(pTile, GROUP_GAMEOBJ::TILE);
        }
    }
}
