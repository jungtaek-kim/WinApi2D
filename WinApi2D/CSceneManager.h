#pragma once

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);

private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE];
	CScene* m_pCurScene;

public:
	void update();
	void render(HDC hDC);
	void init();
};

