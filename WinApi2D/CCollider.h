#pragma once

class CGameObject;

class CCollider
{
	friend class CGameObject;

private:
	CGameObject* m_pOwner;
	fPoint m_fptOffsetPos;
	fPoint m_fptFinalPos;
	fPoint m_fptScale;

public:
	CCollider();
	~CCollider();

	fPoint GetOffsetPos();
	fPoint GetFinalPos();
	fPoint GetScale();

	void SetOffsetPos(fPoint offsetPos);
	void SetFinalPos(fPoint finalPos);
	void SetScale(fPoint scale);

	void finalupdate();
	void render(HDC hDC);
};

