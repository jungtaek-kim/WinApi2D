#include "framework.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{

}

CPathManager::~CPathManager()
{

}

void CPathManager::init()
{
	GetCurrentDirectory(255, m_szContentPath);

	Logger::info(m_szContentPath);
}
