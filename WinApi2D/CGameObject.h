#pragma once
class CGameObject
{
// TODO : Core ���틚�� private
public:
	POINT m_ptPos;
	POINT m_ptScale;

public:
	CGameObject();
	CGameObject(POINT pos, POINT scale);
	~CGameObject();
};

