#pragma once

class CCollider;

class CCollisionManager
{
	SINGLETON(CCollisionManager);

private:
	/*
	* 여러 그룹간의 충돌을 비트를 통해서 구분
	* ex) m_arrCheck[GROUP_GAMEOBJ::PLAYER] = 0000 0000 0000 1100 일 때
	* Player 그룹은 3, 2 번째 그룹인 Missile과 Monster에 충돌한다.
	*/
	UINT m_arrCheck[(UINT)GROUP_GAMEOBJ::SIZE];		// 충돌해야하는 그룹들을 가진 배열

public:
	void init();
	void update();

	void CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);		// 그룹간 충돌 설정
	void UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);	// 그룹간 충돌 해제
	void Reset();
};

