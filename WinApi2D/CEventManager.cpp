#include "framework.h"
#include "CEventManager.h"

CEventManager::CEventManager()
{

}

CEventManager::~CEventManager()
{

}

void CEventManager::Execute(const tEvent& event)
{
	switch (event.eEven)
	{
	case TYPE_EVENT::CREATE_OBJECT:
		// lParam : Object аж╪р
		// wParam : Group 
		break;
	case TYPE_EVENT::DELETE_OBJECT:
		break;
	case TYPE_EVENT::SCENE_CHANGE:
		break;
	}
}

void CEventManager::update()
{
	for (int i = 0; i < m_vecEvent.size(); i++)
	{
		Execute(m_vecEvent[i]);
	}
}

void CEventManager::AddEvent(const tEvent& event)
{
}

void CEventManager::EventCreateObject(CGameObject* pObj, GROUP_GAMEOBJ group)
{
	tEvent event = {};
	event.eEven = TYPE_EVENT::CREATE_OBJECT;
	event.lParam = (DWORD_PTR)pObj;
	event.wParam = (DWORD_PTR)group;

	AddEvent(event);
}
