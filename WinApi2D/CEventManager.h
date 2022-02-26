#pragma once

struct tEvent
{
	TYPE_EVENT	eEven;		// 이벤트 타입
	DWORD_PTR	lParam;		// 추가적인 정보1
	DWORD_PTR	wParam;		// 추가적인 정보2
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

