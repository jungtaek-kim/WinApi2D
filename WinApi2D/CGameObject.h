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

	virtual void update() = 0;			// �ݵ�� ��ӹ��� ��ü�� update�� �����ϵ��� ���������Լ��� ����
	virtual void finalupdate() final;	// ��ӹ޴� Ŭ������ �������̵� �� �� ���� ���� final Ű����
	virtual void render(HDC hDC);
	virtual void component_render(HDC hDC);	// ������Ʈ���� ������ ǥ���ϱ� ����

	CCollider* GetCollider();				// �浹ü ��ȯ
	void CreateCollider();					// �浹ü ����
};

