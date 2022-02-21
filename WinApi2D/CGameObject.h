#pragma once

class CCollider;

class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

	CCollider* m_pCollider;

public:
	CGameObject();
	virtual ~CGameObject();

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();

	virtual void update() = 0;
	virtual void finalupdate() final;	// 상속받는 클래스가 오버라이딩 할 수 없게 막는 final 키워드
	virtual void render(HDC hDC);
	virtual void component_render(HDC hDC);

	CCollider* GetCollider();
	void CreateCollider();
};

