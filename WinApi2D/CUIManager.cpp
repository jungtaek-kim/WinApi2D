#include "framework.h"
#include "CUIManager.h"
#include "CScene.h"
#include "CUI.h"

CUIManager::CUIManager()
{
	m_pFocusedUI = nullptr;
}

CUIManager::~CUIManager()
{

}

void CUIManager::update()
{
	CUI* pFocusedUI = GetFocusedUI();

	if (nullptr == pFocusedUI)
	{
		return;		// 포커스된 UI가 없으므로 상태 변환 없음
	}

	CUI* pTargetUI = GetTargetedUI(pFocusedUI);

	if (nullptr != pTargetUI)
	{
		pTargetUI->MouseOn();

		if (KeyDown(VK_LBUTTON))
		{
			pTargetUI->MouseLbtnDown();
			pTargetUI->m_bLbtnDown = true;
		}
		else if (KeyUp(VK_LBUTTON))
		{
			pTargetUI->MouseLbtnUp();

			if (pTargetUI->m_bLbtnDown)
			{
				pTargetUI->MouseLbtnClicked();
			}
			pTargetUI->m_bLbtnDown = false;
		}
	}
}

CUI* CUIManager::GetFocusedUI()
{
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	vector<CGameObject*>& vecUI = pCurScene->GetUIGroup();

	CUI* pFocusedUI = m_pFocusedUI;

	if (!KeyDown(VK_LBUTTON))
	{
		return pFocusedUI;	// 클릭이 없었으니 포커스 변환 없음
	}

	vector<CGameObject*>::iterator targetIter = vecUI.end();
	vector<CGameObject*>::iterator iter = vecUI.begin();
	for (; iter != vecUI.end(); iter++)
	{
		if (((CUI*)*iter)->IsMouseOn())
		{
			targetIter = iter;
		}
	}
	if (vecUI.end() == targetIter)
	{
		return nullptr;		// targetIter가 end iterator라는 것은 마우스가 올려진 포커스된 UI가 없다는 의미
	}

	pFocusedUI = (CUI*)*targetIter;

	vecUI.erase(targetIter);
	vecUI.push_back(pFocusedUI);
	m_pFocusedUI = pFocusedUI;

	return pFocusedUI;
}

CUI* CUIManager::GetTargetedUI(CUI* pParentUI)
{
	static list<CUI*> queue;
	static vector<CUI*> vecNoneTarget;
	CUI* pTargetUI = nullptr;

	queue.push_back(pParentUI);

	while (!queue.empty())
	{
		CUI* pUI = queue.front();
		queue.pop_front();

		if (pUI->IsMouseOn())
		{
			if (nullptr != pTargetUI)
			{
				vecNoneTarget.push_back(pTargetUI);
			}
			pTargetUI = pUI;
		}
		else
		{
			vecNoneTarget.push_back(pUI);
		}

		const vector<CUI*>& vecChild = pUI->GetChildUI();
		for (size_t i = 0; i < vecChild.size(); ++i)
		{
			queue.push_back(vecChild[i]);
		}

	}

	if (KeyUp(VK_LBUTTON))
	{
		for (size_t i = 0; i < vecNoneTarget.size(); i++)
		{
			vecNoneTarget[i]->m_bLbtnDown = false;
		}
	}

	return pTargetUI;
}
