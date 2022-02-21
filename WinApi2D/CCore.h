#pragma once

class CCore
{
	SINGLETON(CCore);

private:
	HDC m_hDC;
	HDC m_hMemDC;
	HBITMAP m_hBMP;

	// GDI
	HBRUSH m_arrBrush[(int)TYPE_BRUSH::SIZE];
	HPEN m_arrPen[(int)TYPE_PEN::SIZE];

public:
	void update();
	void render();
	void init();

	HDC GetMainDC();

	void CreateBrushPen();
	HBRUSH GetBrush(TYPE_BRUSH type);
	HPEN GetPen(TYPE_PEN type);
};

