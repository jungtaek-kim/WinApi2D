#pragma once

class CKeyManager
{
	SINGLETON(CKeyManager);

private:
	static const int VKEY_SIZE = 0xFF;		// VK�� �ִ� ����

	bool m_arrPrevKey[VKEY_SIZE];			// ���� Ű�� �Է»���
	bool m_arrCurKey[VKEY_SIZE];			// ���� Ű�� �Է»���

public:
	void update();
	void init();

	bool GetButton(const int key);			// Ű�� ������ ���� true
	bool GetButtonUP(const int key);		// Ű�� �ö� ���� true
	bool GetButtonDOWN(const int key);		// Ű�� ������ ���� true
};

