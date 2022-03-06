#pragma once
#include "CGameObject.h"

class CTexture;

class CTile : public CGameObject
{

private:
	CTexture* m_pTex;
	int m_iIdx;			// 텍스쳐 인덱스

public:
	const static int SIZE_TILE = 16;

	CTile();
	virtual ~CTile();

	virtual CTile* Clone();

	virtual void update();
	virtual void render(HDC hDC);

	void SetTexture(CTexture* pTex);

};

