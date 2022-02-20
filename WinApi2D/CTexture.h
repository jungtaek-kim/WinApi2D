#pragma once
#include "CResource.h"
class CTexture : public CResource
{
private:
	HDC m_hDC;
	HBITMAP m_hBMP;

public:
	CTexture();
	virtual ~CTexture();

	HDC GetDC();
	HBITMAP GetBitmap();

	void Load(const wstring& strFilePath);
};

