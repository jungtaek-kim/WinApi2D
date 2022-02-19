#include "framework.h"
#include "CTimeManager.h"

CTimeManager::CTimeManager()
{

}

CTimeManager::~CTimeManager()
{

}

void CTimeManager::update()
{
	static unsigned int updateCount = 0;
	static double updateOneSecond = 0;

	QueryPerformanceCounter(&m_llCurCount);
	// 이전 프레임의 카운팅과, 현재 프레임 카운팅 값의 차이를 구한다.
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFrequency.QuadPart;
	// 이전 프레임을 현재 프레임 카운팅 값으로 넣는다.
	m_llPrevCount = m_llCurCount;

	++updateCount;
	updateOneSecond += m_dDT;
	if (updateOneSecond >= 1.0)
	{
		m_uiFPS = updateCount;

		updateOneSecond = 0;
		updateCount = 0;
	}
}

void CTimeManager::init()
{
	QueryPerformanceCounter(&m_llPrevCount);
	QueryPerformanceFrequency(&m_llFrequency);
}

unsigned int CTimeManager::GetFPS()
{
	return m_uiFPS;
}

double CTimeManager::GetDT()
{
	return m_dDT;
}
