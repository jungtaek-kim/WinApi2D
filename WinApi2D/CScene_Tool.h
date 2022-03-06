#pragma once
#include "CScene.h"
class CScene_Tool : public CScene
{
private:
	HWND m_hWnd;
	UINT m_iIdx;

public:
	CScene_Tool();
	~CScene_Tool();

	virtual void update();

	virtual void Enter();
	virtual void Exit();

	void SetIdx(UINT idx);
	void SetTileIdx();		// 마우스와 상호작용해서 타일을 바꿈.
};

