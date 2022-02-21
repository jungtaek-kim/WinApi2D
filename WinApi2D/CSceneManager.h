#pragma once

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);

private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE];		// 전체 씬 목록
	CScene* m_pCurScene;							// 현재 씬

public:
	void update();
	void render(HDC hDC);
	void init();

	CScene* GetCurScene();							//현재 씬 반환
};

