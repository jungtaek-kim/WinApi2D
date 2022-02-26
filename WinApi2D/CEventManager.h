#pragma once

struct tEvent
{
	TYPE_EVENT	eEven;		// �̺�Ʈ Ÿ��
	DWORD_PTR	lParam;		// �߰����� ����1
	DWORD_PTR	wParam;		// �߰����� ����2
};

class CEventManager
{
	SINGLETON(CEventManager);

private:
	vector<tEvent> m_vecEvent;

	void Execute(const tEvent& event);

public:
	void update();

	void AddEvent(const tEvent& event);
};

