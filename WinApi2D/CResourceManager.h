#pragma once
#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>
#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "Dwrite.lib")

class CTexture;
class CSound;
class CD2DImage;

using namespace D2D1;

class CResourceManager
{
	SINGLETON(CResourceManager);

private:
	map<wstring, CTexture*> m_mapTex;		// Texture 리소스의 저장 자료구조
	map<wstring, CSound*> m_mapSound;		// Sound 리소스의 저장 자료구조
	CSound* m_pBGM;							// BGM 리소스의 저장 변수

	map<wstring, CD2DImage*> m_mapD2DImg;	// D2D Image 리소스의 저장 자료구조

	ID2D1Factory*			m_pFactory;
	ID2D1HwndRenderTarget*	m_pRenderTarget;
	IDWriteFactory*			m_pWriteFactory;
	IWICImagingFactory*		m_pImageFactory;
	ID2D1Bitmap*			m_pBitmap;

public:
	void init();

	CTexture* FindTexture(const wstring& strKey);	// 저장된 Texture 탐색
	CTexture* LoadTextrue(const wstring& strKey, const wstring& strRelativePath);	// Texture 불러오기 이미 있는 경우 있던 Texture 반환
	CTexture* CreateTexture(const wstring& strKey, UINT width, UINT height);

	CSound* FindSound(const wstring& strKey);		// 저장된 Sound 탐색
	CSound* LoadSound(const wstring& strKey, const wstring& strRelativePath);	// Sound 불러오기 이미 있는 경우 있던 Sound 반환

	CSound* LoadBGM(const wstring& strKey, const wstring& strRelativePath);		// BGM 불러오기 이미 있는 경우 있던 BGM 반환

	CD2DImage* FindD2DImage(const wstring& strKey);
	CD2DImage* LoadD2DImage(const wstring& strKey, const wstring& strRelativePath);	// D2DImage 불러오기 이미 있는 경우 있던 D2DImage 반환

	ID2D1HwndRenderTarget*	GetRenderTarget();
	IWICImagingFactory*		GetImageFactory();
	IDWriteFactory*			GetWriteFactory();

};

