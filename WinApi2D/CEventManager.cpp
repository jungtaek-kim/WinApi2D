#include "framework.h"
#include "CEventManager.h"
#include "CGameObject.h"
#include "CScene.h"

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
		{
			// lParam : Object аж╪р
			// wParam : Group 
			CGameObject* pObj = (CGameObject*)event.lParam;
			GROUP_GAMEOBJ group = (GROUP_GAMEOBJ)event.wParam;

			CSceneManager::getInst()->GetCurScene()->AddObject(pObj, group);
		}
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
	m_vecEvent.clear();
}

void CEventManager::AddEvent(const tEvent& event)
{
	m_vecEvent.push_back(event);
}

void CEventManager::EventCreateObject(CGameObject* pObj, GROUP_GAMEOBJ group)
{
	tEvent event = {};
	event.eEven = TYPE_EVENT::CREATE_OBJECT;
	event.lParam = (DWORD_PTR)pObj;
	event.wParam = (DWORD_PTR)group;

	AddEvent(event);
}
