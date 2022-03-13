#pragma once
#include "CResource.h"
#include <d2d1.h>
#pragma comment(lib, "D2D1.lib")

class CD2DImage : public CResource
{
	ID2D1Bitmap* m_pBitmap;
	D2D1_RECT_F m_imgRect;

public:
	CD2DImage();
	~CD2DImage();

	void render();
	void render(float dstX, float dstY, float dstW, float dstH);

	void renderFrame(float dstX, float dstY, float dstW, float dstH, float srcX, float srcY, float srcW, float srcH);
	void renderReverseFrame(float dstX, float dstY, float dstW, float dstH, float srcX, float srcY, float srcW, float srcH);

	void renderRectangle(D2D1::ColorF color, float dstX, float dstY, float dstW, float dstH);

	void SetImage(ID2D1Bitmap* bitmap);

	int GetWidth();
	int GetHeight();
};

