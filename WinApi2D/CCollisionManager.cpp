#include "framework.h"
#include "CCollisionManager.h"
#include "CScene.h"

CCollisionManager::CCollisionManager()
{
	m_arrCheck[0] = 0;
}

CCollisionManager::~CCollisionManager()
{

}

void CCollisionManager::init()
{
}

void CCollisionManager::update()
{
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
