#pragma once

class CCollider;

class CGameObject
{
	friend CEventManager;

private:
	fPoint m_fptPos;
	fPoint m_fptScale;

	CCollider* m_pCollider;

	bool m_bAlive;
	void SetDead();

public:
	CGameObject();
	virtual ~CGameObject();

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();

	bool isDead();

	virtual void update() = 0;			// �ݵ�� ��ӹ��� ��ü�� update�� �����ϵ��� ���������Լ��� ����
	virtual void finalupdate() final;	// ��ӹ޴� Ŭ������ �������̵� �� �� ���� ���� final Ű����
	virtual void render(HDC hDC);
	virtual void component_render(HDC hDC);	// ������Ʈ���� ������ ǥ���ϱ� ����

	CCollider* GetCollider();				// �浹ü ��ȯ
	void CreateCollider();					// �浹ü ����

	virtual void OnCollision(CCollider* _pOther) {}			// �����ǿ� �浹�� �����Լ�
	virtual void OnCollisionEnter(CCollider* _pOther) {}	// �����ǿ� �浹�� �����Լ�
	virtual void OnCollisionExit(CCollider* _pOther) {}		// �����ǿ� Ż�浹 �����Լ�
};

