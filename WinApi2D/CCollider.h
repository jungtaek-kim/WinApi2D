#pragma once

class CGameObject;

class CCollider
{
	friend class CGameObject;

public:
	CCollider();
	~CCollider();

private:
	CGameObject* m_pOwner;
};

