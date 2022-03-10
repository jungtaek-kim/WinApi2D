#include "framework.h"
#include "CSoundManager.h"
#include "CSound.h"

CSoundManager::CSoundManager()
{
	m_pSystem = nullptr;
}

CSoundManager::~CSoundManager()
{

}

System* CSoundManager::GetSystem()
{
	return m_pSystem;
}

void CSoundManager::init()
{
	// ���� �ý��� ����
	System_Create(&m_pSystem);
	assert(m_pSystem);
	m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr);
}

void CSoundManager::update()
{
	m_pSystem->update();		// �ݵ�� �� �����Ӹ��� ������Ʈ �Ǿ�� ��. fmod���� �Ϸ�
}

void CSoundManager::AddSound(wstring keyName, wstring filePath, bool loop)
{
	CSound* pSound = CResourceManager::getInst()->LoadSound(keyName, filePath);
	pSound->SetLoop(loop);
	m_mapSound.insert(make_pair(keyName, pSound));
}

void CSoundManager::Play(wstring keyName)
{
	map<wstring, CSound*>::iterator iter;
	for (iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (keyName == iter->first)
		{
			iter->second->Play();
			break;
		}
	}
}

void CSoundManager::Stop(wstring keyName)
{
	map<wstring, CSound*>::iterator iter;
	for (iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (keyName == iter->first)
		{
			iter->second->Stop();
			break;
		}
	}
}

void CSoundManager::Pause(wstring keyName)
{
	map<wstring, CSound*>::iterator iter;
	for (iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (keyName == iter->first)
		{
			iter->second->Pause();
			break;
		}
	}
}

void CSoundManager::Resume(wstring keyName)
{
	map<wstring, CSound*>::iterator iter;
	for (iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (keyName == iter->first)
		{
			iter->second->Resume();
			break;
		}
	}
}

bool CSoundManager::IsPlaySound(wstring keyName)
{
	map<wstring, CSound*>::iterator iter;
	for (iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (keyName == iter->first)
		{
			return iter->second->IsPlaying();
		}
	}
	return false;
}

bool CSoundManager::IsPauseSound(wstring keyName)
{
	map<wstring, CSound*>::iterator iter;
	for (iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (keyName == iter->first)
		{
			return iter->second->IsPaused();
		}
	}
	return false;
}
