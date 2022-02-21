#include "framework.h"
#include "CResourceManager.h"
#include "CTexture.h"

CResourceManager::CResourceManager()
{
	m_mapTex = {};
}

CResourceManager::~CResourceManager()
{
	// 자료구조에 저장된 모든 Texture 삭제
	for (map<wstring, CTexture*>::iterator iter = m_mapTex.begin(); iter != m_mapTex.end(); iter++)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	m_mapTex.clear();
}

CTexture* CResourceManager::FindTexture(const wstring& strKey)
{
	// Texture 키 값을 통해 탐색
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(strKey);
	
	if (m_mapTex.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}

CTexture* CResourceManager::LoadTextrue(const wstring& strKey, const wstring& strRelativePath)
{
	// Texture를 불러오기 전 자료구조에 이미 Texture가 있는지 확인
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
	{
		return pTex;
	}
	
	// Texture 저장 경로 확인
	wstring strFilePath = CPathManager::getInst()->GetContentPath();
	strFilePath += strRelativePath;

	// Texture 생성 후 저장
	pTex = new CTexture;
	pTex->Load(strFilePath);
	pTex->SetKey(strKey);
	pTex->SetRelativePath(strRelativePath);

	m_mapTex.insert(make_pair(strKey, pTex));
	
	return pTex;
}
