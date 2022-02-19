#include "framework.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager()
{
	// 키 상태를 모두 눌리지 않은 상태로 초기화
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
	// 모든 키 사이즈만큼 반복하며 입력상태를 확인
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

