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

	virtual void update() = 0;			// 반드시 상속받은 객체가 update를 구현하도록 순수가상함수로 선언
	virtual void finalupdate() final;	// 상속받는 클래스가 오버라이딩 할 수 없게 막는 final 키워드
	virtual void render(HDC hDC);
	virtual void component_render(HDC hDC);	// 컴포넌트들의 영역을 표시하기 위해

	CCollider* GetCollider();				// 충돌체 반환
	void CreateCollider();					// 충돌체 생성
};

