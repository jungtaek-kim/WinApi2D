#pragma once

class CCore
{
	SINGLETON(CCore);

private:
	HDC m_hDC;

public:
	void update();
	void render();
	void init();
};

