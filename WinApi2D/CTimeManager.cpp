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
	static unsigned int updateCount = 0;	// update가 발생한 카운트 저장
	static double updateOneSecond = 0;		// update가 1초가 되었는지 판단하기 위해 저장

	// 시간 측정
	// 현재 카운트 - 이전 카운트 => 이전 업데이트에서 현재 업데이트가 호출되기 까지 카운트 수
	// (현재 카운트 - 이전 카운트) / 초당 카운트 수 => 1update가 발생할 때까지의 시간

	// ex)
	// 속력이 100km/h 인 자동차가 10km지점에서 20km 지점까지 가는데 걸리는 시간을 구하려면
	// (20km - 10km) / 100km/h = 0.1h

	// 현재 카운트 갯수 확인
	QueryPerformanceCounter(&m_llCurCount);
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFrequency.QuadPart;
	// 이전 카운트를 현재 카운트 값으로 넣는다.
	m_llPrevCount = m_llCurCount;

	// update 함수가 호출될때마다 증가하는 updateCount
	++updateCount;
	// 단위 시간만큼 1초가 되었는지 확인하는 updateOneSecond에 추가
	updateOneSecond += m_dDT;
	if (updateOneSecond >= 1.0)	// 만약 updateOneSecond가 1초 이상이 되었다면
	{
		m_uiFPS = updateCount;	// 초당 update 횟수 == FPS

		updateOneSecond = 0;	// updateOneSecond를 초기화
		updateCount = 0;		// updateCount를 초기화
	}
}

void CTimeManager::init()
{
	// GetTickCount				: 간단하고 빠르게 카운트 측정 함수
	// QueryPerformanceCount	: 좀 더 정교한 카운트 측정 함수

	// 현재 카운트 갯수 확인
	QueryPerformanceCounter(&m_llCurCount);
	// 초당 카운트 갯수 확인
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
