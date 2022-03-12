#include "framework.h"
#include "CResourceManager.h"
#include "CTexture.h"
#include "CSound.h"
#include "CD2DImage.h"

CResourceManager::CResourceManager()
{
	m_pBGM = nullptr;

	m_pFactory = nullptr;
	m_pRenderTarget = nullptr;
	m_pWriteFactory = nullptr;
	m_pImageFactory = nullptr;
	m_pBitmap = nullptr;
}

CResourceManager::~CResourceManager()
{
	// �ڷᱸ���� ����� ��� Texture ����
	for (map<wstring, CTexture*>::iterator iter = m_mapTex.begin(); iter != m_mapTex.end(); iter++)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	m_mapTex.clear();
	// �ڷᱸ���� ����� ��� Sound ����
	for (map<wstring, CSound*>::iterator iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	m_mapSound.clear();

	if (nullptr != m_pRenderTarget)
	{
		m_pRenderTarget->Release();
	}
	// �ڷᱸ���� ����� ��� D2DImage ����
	for (map<wstring, CD2DImage*>::iterator iter = m_mapD2DImg.begin(); iter != m_mapD2DImg.end(); iter++)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	m_mapD2DImg.clear();
}

void CResourceManager::init()
{
	RECT rc;
	GetClientRect(hWnd, &rc);

	// D2D1Factory ����
	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pFactory);

	// ������ �������� Ŭ���̾�Ʈ ������ �׸��� �׸��� ���� Render Target�� ����
	m_pFactory->CreateHwndRenderTarget(RenderTargetProperties(),
		HwndRenderTargetProperties(hWnd, SizeU(rc.right, rc.bottom)),
		&m_pRenderTarget);

	// WICImagingFactory ����
	if (S_OK == CoInitialize(nullptr))
	{

	}
	if (S_OK == CoCreateInstance(CLSID_WICImagingFactory, nullptr,
		CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pImageFactory)))
	{

	}
	if (S_OK == DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(m_pWriteFactory),
		reinterpret_cast<IUnknown**>(&m_pWriteFactory)))
	{

	}
}

CTexture* CResourceManager::FindTexture(const wstring& strKey)
{
	// Texture Ű ���� ���� Ž��
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(strKey);
	
	if (m_mapTex.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}

CTexture* CResourceManager::LoadTextrue(const wstring& strKey, const wstring& strRelativePath)
{
	// Texture�� �ҷ����� �� �ڷᱸ���� �̹� Texture�� �ִ��� Ȯ��
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
	{
		return pTex;
	}
	
	// Texture ���� ��� Ȯ��
	wstring strFilePath = CPathManager::getInst()->GetContentPath();
	strFilePath += strRelativePath;

	// Texture ���� �� ����
	pTex = new CTexture;
	pTex->Load(strFilePath);
	pTex->SetKey(strKey);
	pTex->SetRelativePath(strRelativePath);

	m_mapTex.insert(make_pair(strKey, pTex));
	
	return pTex;
}

CTexture* CResourceManager::CreateTexture(const wstring& strKey, UINT width, UINT height)
{
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
	{
		return pTex;
	}
	
	pTex = new CTexture;
	pTex->Create(width, height);
	pTex->SetKey(strKey);

	m_mapTex.insert(make_pair(strKey, pTex));

	return pTex;
}

CSound* CResourceManager::FindSound(const wstring& strKey)
{
	// CSound Ű ���� ���� Ž��
	map<wstring, CSound*>::iterator iter = m_mapSound.find(strKey);

	if (m_mapSound.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}

CSound* CResourceManager::LoadSound(const wstring& strKey, const wstring& strRelativePath)
{
	// Sound�� �ҷ����� �� �ڷᱸ���� �̹� Sound�� �ִ��� Ȯ��
	CSound* pSound = FindSound(strKey);
	if (nullptr != pSound)
	{
		return pSound;
	}

	// Sound ���� ��� Ȯ��
	wstring strFilePath = CPathManager::getInst()->GetRelativeContentPath();
	strFilePath += strRelativePath;

	// Sound ���� �� ����
	pSound = new CSound;
	pSound->Load(strFilePath, false);
	pSound->SetKey(strKey);
	pSound->SetRelativePath(strRelativePath);

	m_mapSound.insert(make_pair(strKey, pSound));

	return pSound;
}

CSound* CResourceManager::LoadBGM(const wstring& strKey, const wstring& strRelativePath)
{
	CSound* pBGM = m_pBGM;
	if (nullptr != pBGM)
		return pBGM;

	// Sound ���� ��� Ȯ��
	wstring strFilePath = CPathManager::getInst()->GetRelativeContentPath();
	strFilePath += strRelativePath;

	// Sound ���� �� ����
	pBGM = new CSound;
	pBGM->Load(strFilePath, true);
	pBGM->SetKey(strKey);
	pBGM->SetRelativePath(strRelativePath);

	m_pBGM = pBGM;

	return pBGM;
}

CD2DImage* CResourceManager::FindD2DImage(const wstring& strKey)
{
	// CD2DImage Ű ���� ���� Ž��
	map<wstring, CD2DImage*>::iterator iter = m_mapD2DImg.find(strKey);

	if (m_mapD2DImg.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}

CD2DImage* CResourceManager::LoadD2DImage(const wstring& strKey, const wstring& strRelativePath)
{
	CD2DImage* pD2DImg = FindD2DImage(strKey);
	if (nullptr != pD2DImg)
		return pD2DImg;

	wstring strFilePath = CPathManager::getInst()->GetRelativeContentPath();
	strFilePath += strRelativePath;

	CD2DImage* img = new CD2DImage;

	IWICBitmapDecoder* p_decoder;		// ����� �̹����� ������ ��ü
	IWICBitmapFrameDecode* p_frame;		// Ư�� �׸��� ������ ��ü
	IWICFormatConverter* p_converter;	// �̹��� ��ȯ ��ü

	// WIC�� Factory ��ü�� ����Ͽ� �̹��� ���� ������ ���� ��ü�� ����
	if (S_OK != m_pImageFactory->CreateDecoderFromFilename(strFilePath.c_str(), NULL, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &p_decoder))
	{
		assert(nullptr);
	}
	// ������ �����ϴ� �̹��� �߿��� ù��° �̹����� �����Ѵ�.
	if (S_OK != p_decoder->GetFrame(0, &p_frame))
	{
		assert(nullptr);
	}
	// IWICBitmap������ ��Ʈ���� ID2D1Bitmap. �������� ��ȯ�ϱ� ���� ��ü ����
	if (S_OK != m_pImageFactory->CreateFormatConverter(&p_converter))
	{
		assert(nullptr);
	}
	// ���õ� �׸��� � ������ ��Ʈ������ ��ȯ�� ������ ����
	if (S_OK != p_converter->Initialize(p_frame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0f, WICBitmapPaletteTypeCustom))
	{
		assert(nullptr);
	}
	// IWICBitmap ������ ��Ʈ������ ID2D1Bitmap ��ü�� ����
	if (S_OK != m_pRenderTarget->CreateBitmapFromWicBitmap(p_converter, NULL, &m_pBitmap))
	{
		assert(nullptr);
	}

	// ���������� ������ ���
	img->SetImage(m_pBitmap);
	img->SetKey(strKey);
	img->SetRelativePath(strRelativePath);
	m_mapD2DImg.insert(make_pair(strFilePath.c_str(), img));

	int a = m_pBitmap->GetSize().width;
	
	p_converter->Release();		// �̹��� ��ȯ ��ü ����
	p_frame->Release();			// �׸����Ͽ� �ִ� �̹����� �����ϱ� ���� ����� ��ü ����
	p_decoder->Release();		// ������ �����ϱ� ���� ������ ��ü ����

	return img;
}

ID2D1HwndRenderTarget* CResourceManager::GetRenderTarget()
{
	return m_pRenderTarget;
}

IWICImagingFactory* CResourceManager::GetImageFactory()
{
	return m_pImageFactory;
}

IDWriteFactory* CResourceManager::GetWriteFactory()
{
	return m_pWriteFactory;
}
