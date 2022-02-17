// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include "SingleTon.h"
#include "CCore.h"


//========================================
//##			디파인문				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX


//========================================
//## 전역변수(인스턴스, 윈도우 핸들)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;


//================================================
//## Logger	(visual studio 출력창에 정보 표시)	##
//================================================

#include <string>

class Logger
{
	static std::wstring format(const std::wstring fmt, va_list args)
	{
		int size = ((int)fmt.size()) * 2;
		wchar_t* buffer = nullptr;
		while (true) {
			if (buffer != nullptr)
			{
				delete[] buffer;
			}
			buffer = new wchar_t[size + 1];
			int n = _vsnwprintf_s(buffer, size + 1, size, (wchar_t*)fmt.c_str(), args);
			if (-1 < n && n < size) {
				break;
			}
			else
			{
				size *= 2;
			}
		}
		std::wstring result = buffer;
		delete[] buffer;
		return result;
	}

	static std::wstring format(const std::wstring fmt, ...)
	{
		va_list args; va_start(args, fmt);
		std::wstring result = format(fmt, args);
		va_end(args);
		return result;
	}

public:

	static void debug(const wchar_t log[])
	{
		SYSTEMTIME st;
		GetLocalTime(&st);

		std::wstring str = L"";
		str = format(L"%d/%d/%d %d:%2d:%2d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

		OutputDebugStringW(str.c_str());
		OutputDebugStringW(L" [DEBUG] ");
		OutputDebugStringW(log);
		OutputDebugStringW(L"\n");
	}
};
