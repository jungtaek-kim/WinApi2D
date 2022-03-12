#include "framework.h"
#include "CD2DImage.h"

CD2DImage::CD2DImage()
{
	m_pBitmap = nullptr;
	m_imgRect = {};
}

CD2DImage::~CD2DImage()
{
}

void CD2DImage::render()
{
	if (nullptr != m_pBitmap)
	{
		m_imgRect = { 100, 100, 200, 200 };
		CResourceManager::getInst()->GetRenderTarget()->DrawBitmap(m_pBitmap, m_imgRect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
	}
	else
	{
		// �̹����� ���� ���ߴٸ� ȭ���� ���������� ��µǱ� ������ Clear �Լ���
		// ����Ͽ� ������ ��ü ������ �ϴû����� ä���.
		CResourceManager::getInst()->GetRenderTarget()->Clear(ColorF(0.0f, 0.8f, 1.0f));
	}
}

void CD2DImage::render(RECT rect)
{
}

void CD2DImage::SetImage(ID2D1Bitmap* bitmap)
{
	m_pBitmap = bitmap;
}

int CD2DImage::GetWidth()
{
	return m_pBitmap->GetSize().width;
}

int CD2DImage::GetHeight()
{
	return m_pBitmap->GetSize().height;
}
