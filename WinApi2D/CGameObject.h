#pragma once
class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	CGameObject();
	virtual ~CGameObject();

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();

	virtual void update() = 0;
	virtual void render(HDC hDC);
};

