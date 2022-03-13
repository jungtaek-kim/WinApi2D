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
		CRenderManager::getInst()->GetRenderTarget()->DrawBitmap(m_pBitmap, m_imgRect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
	}
}

void CD2DImage::render(float dstX, float dstY, float dstW, float dstH)
{
	m_imgRect = { dstX, dstY, dstW, dstH };
	render();
}

void CD2DImage::renderFrame(float dstX, float dstY, float dstW, float dstH, float srcX, float srcY, float srcW, float srcH)
{
	m_imgRect = { dstX, dstY, dstW, dstH };
	D2D1_RECT_F srcRect = { srcX, srcY, srcW, srcH };
	
	if (nullptr != m_pBitmap)
	{
		CRenderManager::getInst()->GetRenderTarget()->DrawBitmap(m_pBitmap, m_imgRect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
	}
}

void CD2DImage::renderReverseFrame(float dstX, float dstY, float dstW, float dstH, float srcX, float srcY, float srcW, float srcH)
{
	m_imgRect = { dstX, dstY, dstW, dstH };
	D2D1_RECT_F srcRect = { srcX, srcY, srcW, srcH };

	CRenderManager::getInst()->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Scale(-1.f, 1.f,
		D2D1_POINT_2F{ dstX + dstW / 2.f, dstY + dstH / 2.f }));

	if (nullptr != m_pBitmap)
	{
		CRenderManager::getInst()->GetRenderTarget()->DrawBitmap(m_pBitmap, m_imgRect, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
	}

	CRenderManager::getInst()->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Scale(1.f, 1.f,
		D2D1_POINT_2F{ dstX + dstW / 2.f, dstY + dstH / 2.f }));
}

void CD2DImage::SetImage(ID2D1Bitmap* bitmap)
{
	m_pBitmap = bitmap;
}

int CD2DImage::GetWidth()
{
	return (int)m_pBitmap->GetSize().width;
}

int CD2DImage::GetHeight()
{
	return (int)m_pBitmap->GetSize().height;
}
