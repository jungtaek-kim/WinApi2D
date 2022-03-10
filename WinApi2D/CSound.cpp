#include "framework.h"
#include "CSound.h"

CSound::CSound()
{
	sound = nullptr;
	channel = nullptr;
}

CSound::~CSound()
{
	Stop();
	if (nullptr != channel)
	{
		delete channel;
	}

	if (nullptr != sound)
	{
		sound->release();
		delete sound;
	}
}

void CSound::Load(const wstring& strFilePath)
{
	char str[255];
	wcstombs_s(nullptr, str, strFilePath.c_str(), 255);

	CSoundManager::getInst()->GetSystem()->createSound(str, FMOD_LOOP_OFF, 0, &sound);
}

void CSound::Play()
{
	CSoundManager::getInst()->GetSystem()->playSound(sound, 0, false, &channel);
	assert(channel);
}

void CSound::Pause()
{
	if (nullptr != channel)
		channel->setPaused(true);
}

void CSound::Stop()
{
	if (nullptr != channel)
		channel->stop();
}

void CSound::Resume()
{
	if (nullptr != channel)
		channel->setPaused(true);
}

bool CSound::IsPlaying()
{
	bool playing = false;
	if (nullptr != channel)
		channel->isPlaying(&playing);

	return playing;
}

bool CSound::IsPaused()
{
	bool paused = false;
	if (nullptr != channel)
		channel->getPaused(&paused);

	return paused;
}

void CSound::SetLoop(bool loop)
{
	if (loop)
	{
		sound->setMode(FMOD_DEFAULT);
	}
	else
	{
		sound->setMode(FMOD_LOOP_OFF);
	}
}