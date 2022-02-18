#pragma once

class CCore
{
	SINGLETON(CCore);

private:
	HDC m_hDC;			// 윈도우 DC 핸들 : 게임 윈도우 창의 그리기 DC
	HDC m_hMemDC;		// 메모리 DC 핸들 : 그리기 작업을 임시로 진행할 메모리의 DC
	HBITMAP m_hBMP;		// 비트맵 핸들 : 그리기 내용에 대한 이미지 핸들

public:
	void update();
	void render();
	void init();
};

