#pragma once
class CCore : public SingleTon<CCore>
{
public:
	void update();
	void render();
};

