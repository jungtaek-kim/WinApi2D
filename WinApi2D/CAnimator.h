#pragma once

class CGameObject;
class CAnimation;

class CAnimator
{
	friend class CGameObject;

private:
	map<wstring, CAnimation*> m_mapAni;
	CGameObject* m_pOwner;

public:
	CAnimator();
	~CAnimator();

	void CreateAnimation();
	void FindAnimation();
	void Play();
};

