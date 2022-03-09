#include "framework.h"
#include "CSound.h"

CSound::CSound()
{
	system = nullptr;
	sound = nullptr;
	channel = nullptr;
}

CSound::~CSound()
{
	Stop();
}

void CSound::Load(const wstring& strFilePath)
{
	FMOD_RESULT ret;
	char str[255];
	wcstombs_s(nullptr, str, strFilePath.c_str(), 255);

	ret = FMOD::System_Create(&system);
	assert(system);
	ret = system->init(32, FMOD_INIT_NORMAL, nullptr);
	ret = system->createSound(str, FMOD_DEFAULT, 0, &sound);
	assert(sound);
}

void CSound::Play()
{
	system->playSound(sound, 0, false, &channel);
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
