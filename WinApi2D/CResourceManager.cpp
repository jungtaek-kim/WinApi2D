#include "framework.h"
#include "CResourceManager.h"
#include "CTexture.h"
#include "CSound.h"

CResourceManager::CResourceManager()
{
	m_mapTex = {};
}

CResourceManager::~CResourceManager()
{
	// �ڷᱸ���� ����� ��� Texture ����
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
	// Texture Ű ���� ���� Ž��
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(strKey);
	
	if (m_mapTex.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}

CTexture* CResourceManager::LoadTextrue(const wstring& strKey, const wstring& strRelativePath)
{
	// Texture�� �ҷ����� �� �ڷᱸ���� �̹� Texture�� �ִ��� Ȯ��
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
	{
		return pTex;
	}
	
	// Texture ���� ��� Ȯ��
	wstring strFilePath = CPathManager::getInst()->GetContentPath();
	strFilePath += strRelativePath;

	// Texture ���� �� ����
	pTex = new CTexture;
	pTex->Load(strFilePath);
	pTex->SetKey(strKey);
	pTex->SetRelativePath(strRelativePath);

	m_mapTex.insert(make_pair(strKey, pTex));
	
	return pTex;
}

CSound* CResourceManager::FindSound(const wstring& strKey)
{
	// CSound Ű ���� ���� Ž��
	map<wstring, CSound*>::iterator iter = m_mapSound.find(strKey);

	if (m_mapSound.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}

CSound* CResourceManager::LoadSound(const wstring& strKey, const wstring& strRelativePath)
{
	// Sound�� �ҷ����� �� �ڷᱸ���� �̹� Sound�� �ִ��� Ȯ��
	CSound* pSound = FindSound(strKey);
	if (nullptr != pSound)
	{
		return pSound;
	}

	// Sound ���� ��� Ȯ��
	wstring strFilePath = CPathManager::getInst()->GetRelativeContentPath();
	strFilePath += strRelativePath;

	// Sound ���� �� ����
	pSound = new CSound;
	pSound->Load(strFilePath);
	pSound->SetKey(strKey);
	pSound->SetRelativePath(strRelativePath);

	m_mapSound.insert(make_pair(strKey, pSound));

	return pSound;
}
