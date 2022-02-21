#pragma once

class CGameObject;

class CCollider
{
	friend class CGameObject;

private:
	CGameObject* m_pOwner;		// 충돌체를 가지는 게임오브젝트의 주소
	fPoint m_fptOffsetPos;		// 충돌체의 변위차(수정값)
	fPoint m_fptFinalPos;		// 충돌체의 최종 위치
	fPoint m_fptScale;			// 충돌체의 크기

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

