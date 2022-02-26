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
		// �浹ü ������Ʈ�� ���� ��� ����
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (int j = 0; j < vecRight.size(); j++)
		{
			// �浹ü ������Ʈ�� ���� ��� ����
			if (nullptr == vecRight[i]->GetCollider())
				continue;

			// �ڱ� �ڽŰ��� �浹�� ����
			if (vecLeft[i] == vecRight[i])
				continue;

			// �浹 ó��
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
				// �浹�� �˻��ؾ��ϴ� �� �׷�
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow, (GROUP_GAMEOBJ)iCol);
			}
		}
	}
}

void CCollisionManager::CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	// [��][��]
	UINT iRow;	// ��
	UINT iCol;	// ��

	// �� ���� ���� ������ ��
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
	// [��][��]
	UINT iRow;	// ��
	UINT iCol;	// ��

	// �� ���� ���� ������ ��
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
	// memset(���� �ּ�, ������ ������, ������ ũ��);
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_GAMEOBJ::SIZE);
	/*for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		m_arrCheck[i] = 0;
	}*/
}
