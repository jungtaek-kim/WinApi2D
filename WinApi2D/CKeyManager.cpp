#include "framework.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager()
{
	// Ű ���¸� ��� ������ ���� ���·� �ʱ�ȭ
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key]	= false;
		m_arrCurKey[key]	= false;
	}
}

CKeyManager::~CKeyManager()
{

}

void CKeyManager::update()
{
	// ���� ����(Focus)�� �����찡 ���� �������ΰ��� Ȯ��
	HWND curWnd = GetFocus();
	if (hWnd != curWnd)
	{
		// �����찡 ����(Focus)�� ���°� �ƴ� ��� Ű�Է��� ������Ŵ
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
		return;
	}

	// ��� Ű �����ŭ �ݺ��ϸ� �Է»��¸� Ȯ��
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrPrevKey[key] = false;
		}
	}
}

void CKeyManager::init()
{
	
}

bool CKeyManager::GetButton(const int key)
{
	return (true == m_arrCurKey[key] && true == m_arrPrevKey[key]);
}

bool CKeyManager::GetButtonUP(const int key)
{
	return (false == m_arrCurKey[key] && true == m_arrPrevKey[key]);
}

bool CKeyManager::GetButtonDOWN(const int key)
{
	return (true == m_arrCurKey[key] && false == m_arrPrevKey[key]);
}
