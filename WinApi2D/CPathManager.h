#pragma once
class CPathManager
{
	SINGLETON(CPathManager);

private:
	WCHAR m_szContentPath[255];		// 윈도우 최대 경로 255

public:
	void init();
};

