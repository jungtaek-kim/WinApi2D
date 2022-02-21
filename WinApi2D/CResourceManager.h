#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);

private:
	map<wstring, CTexture*> m_mapTex;		// Texture 리소스의 저장 자료구조

public:
	CTexture* FindTexture(const wstring& strKey);	// 저장된 Texture 탐색
	CTexture* LoadTextrue(const wstring& strKey, const wstring& strRelativePath);	// Texture 불러오기 이미 있는 경우 있던 Texture 반환

};

