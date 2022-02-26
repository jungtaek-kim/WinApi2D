#include "framework.h"
#include "CCollisionManager.h"
#include "CScene.h"
#include "CGameObject.h"

CCollisionManager::CCollisionManager()
{
	m_arrCheck[0] = 0;
}

CCollisionManager::~CCollisionManager()
{

}

void CCollisionManager::CollisionGroupUpdate(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

	const vector<CGameObject*>& vecLeft = pCurScene->GetGroupObject(objLeft);
	const vector<CGameObject*>& vecRight = pCurScene->GetGroupObject(objRight);

	for (int i = 0; i < vecLeft.size(); i++)
	{
		// 충돌체 컴포넌트가 없는 경우 무시
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (int j = 0; j < vecRight.size(); j++)
		{
			// 충돌체 컴포넌트가 없는 경우 무시
			if (nullptr == vecRight[i]->GetCollider())
				continue;

			// 자기 자신과의 충돌은 무시
			if (vecLeft[i] == vecRight[i])
				continue;

			// 충돌 처리
		}
	}
}

void CCollisionManager::init()
{
}

void CCollisionManager::update()
{
	for (UINT iRow = 0; iRow < (UINT)GROUP_GAMEOBJ::SIZE; iRow++)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_GAMEOBJ::SIZE; iCol++)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				// 충돌을 검사해야하는 두 그룹
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow, (GROUP_GAMEOBJ)iCol);
			}
		}
	}
}

void CCollisionManager::CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	// [행][렬]
	UINT iRow;	// 렬
	UINT iCol;	// 행

	// 더 작은 수를 행으로 둠
	if ((UINT)objLeft > (UINT)objRight)
	{
		iRow = (UINT)objLeft;
		iCol = (UINT)objRight;
	}
	else
	{
		iRow = (UINT)objRight;
		iCol = (UINT)objLeft;
	}

	m_arrCheck[iRow] |= (1 << iCol);
}

void CCollisionManager::UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	// [행][렬]
	UINT iRow;	// 렬
	UINT iCol;	// 행

	// 더 작은 수를 행으로 둠
	if ((UINT)objLeft > (UINT)objRight)
	{
		iRow = (UINT)objLeft;
		iCol = (UINT)objRight;
	}
	else
	{
		iRow = (UINT)objRight;
		iCol = (UINT)objLeft;
	}

	m_arrCheck[iRow] &= ~(1 << iCol);
}

void CCollisionManager::Reset()
{
	// memset(시작 주소, 설정할 데이터, 설정할 크기);
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_GAMEOBJ::SIZE);
	/*for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		m_arrCheck[i] = 0;
	}*/
}
