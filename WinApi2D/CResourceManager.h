#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);

private:
	map<wstring, CTexture*> m_mapTex;		// Texture ���ҽ��� ���� �ڷᱸ��

public:
	CTexture* FindTexture(const wstring& strKey);	// ����� Texture Ž��
	CTexture* LoadTextrue(const wstring& strKey, const wstring& strRelativePath);	// Texture �ҷ����� �̹� �ִ� ��� �ִ� Texture ��ȯ

};

