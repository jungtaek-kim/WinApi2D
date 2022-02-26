#pragma once
class CCollisionManager
{
	SINGLETON(CCollisionManager);

public:
	void init();
	void update();
	void CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);
};

