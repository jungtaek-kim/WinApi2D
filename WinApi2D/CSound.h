#pragma once
#include "FMOD/inc/fmod.hpp"
#include "CResource.h"
#pragma comment(lib,"FMOD/lib/fmod_vc.lib")

using namespace FMOD;

class CSound : public CResource
{
private:

	System*		system;
	Sound*		sound;
	Channel*	channel;

public:
	CSound();
	~CSound();

	void Play();
	void Stop();
	void Pause();
	void Resume();

	void Load(const wstring& strRelativePath);
};

