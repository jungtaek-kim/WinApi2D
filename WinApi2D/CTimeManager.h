#pragma once
class CTimeManager
{
	SINGLETON(CTimeManager);

private:
	// LARGE_INTEGER : long long 변수의 공용체 HighPart + LowPart = QuadPart
	LARGE_INTEGER m_llCurCount;		// 현재 카운트
	LARGE_INTEGER m_llPrevCount;	// 이전 카운트
	LARGE_INTEGER m_llFrequency;	// 초당 카운트 횟수

	unsigned int	m_uiFPS;			// FPS : 초당 호출된 업데이트 수 == 초당 그려진 화면 수
	double			m_dDT;				// Delta Time : 단위시간, 업데이트당 소요된 시간 == 1프레임당 소요된 시간

public:
	void update();		// 업데이트
	void init();		// 초기화

	unsigned int GetFPS();
	double GetDT();
};

