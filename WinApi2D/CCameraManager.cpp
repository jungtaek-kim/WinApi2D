#include "framework.h"
#include "CCameraManager.h"
#include "CGameObject.h"
#include "CTexture.h"

CCameraManager::CCameraManager()
{
	m_fptLookAt = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);
	m_fptCurLookAt = m_fptLookAt;
	m_fptPrevLookAt = m_fptLookAt;
	m_pTargetObj = nullptr;
	m_fAccTime = m_fTime;
	m_fSpeed = 0;

	m_eEffect = CAM_EFFECT::NONE;
	m_pTex = nullptr;
	m_fEffectDuration = 0.f;
	m_fCurTime = 0.f;
}

CCameraManager::~CCameraManager()
{

}

void CCameraManager::init()
{
	m_pTex = CResourceManager::getInst()->CreateTexture(L"CameraTex", WINSIZEX, WINSIZEY);
}

void CCameraManager::update()
{
	if (m_pTargetObj)
	{
		if (m_pTargetObj->isDead())
		{
			m_pTargetObj = nullptr;
		}
		else
		{
			SetLookAt(m_pTargetObj->GetPos());
		}
	}

	// ȭ�� �߾Ӱ� ī�޶� LookAt ��ǥ ������ ���� ���
	CalDiff();
}

void CCameraManager::render(HDC hDC)
{
	if (CAM_EFFECT::NONE == m_eEffect)
		return;

	m_fCurTime += fDT;
	if (m_fEffectDuration < m_fCurTime)
	{
		m_eEffect = CAM_EFFECT::NONE;
		return;
	}

	float fRatio = 0.f;
	int iAlpha = 0;
	fRatio = m_fCurTime / m_fEffectDuration;
	if (CAM_EFFECT::FADE_OUT == m_eEffect)
	{
		iAlpha = (int)(255.f * fRatio);
	}
	else if (CAM_EFFECT::FADE_IN == m_eEffect)
	{
		iAlpha = (int)(255.f * (1.f - fRatio));
	}

	BLENDFUNCTION bf = {};

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = iAlpha;

	AlphaBlend(hDC
		, 0, 0
		, (int)(m_pTex->GetBmpWidth())
		, (int)(m_pTex->GetBmpHeight())
		, m_pTex->GetDC()
		, 0, 0
		, (int)(m_pTex->GetBmpWidth())
		, (int)(m_pTex->GetBmpHeight())
		, bf);
}

void CCameraManager::SetLookAt(fPoint lookAt)
{
	m_fptLookAt = lookAt;
	float fMoveDist = (m_fptLookAt - m_fptPrevLookAt).Length();

	m_fSpeed = fMoveDist / m_fTime;
	m_fAccTime = 0.f;
}

void CCameraManager::SetTargetObj(CGameObject* target)
{
	m_pTargetObj = target;
}

fPoint CCameraManager::GetLookAt()
{
	return m_fptCurLookAt;
}

fPoint CCameraManager::GetRenderPos(fPoint objPos)
{
	return objPos - m_fptDiff;
}

fPoint CCameraManager::GetRealPos(fPoint renderPos)
{
	// ������ ��ǥ���� ���̰���ŭ �����ָ� ���� ��ǥ�� ����.
	return renderPos + m_fptDiff;
}

void CCameraManager::FadeIn(float duration)
{
	m_eEffect = CAM_EFFECT::FADE_IN;
	m_fEffectDuration = duration;

	if (0.f == m_fEffectDuration)
	{
		assert(nullptr);
	}
}

void CCameraManager::FadeOut(float duration)
{
	m_eEffect = CAM_EFFECT::FADE_OUT;
	m_fEffectDuration = duration;

	if (0.f == m_fEffectDuration)
	{
		assert(nullptr);
	}
}

void CCameraManager::Scroll(fVec2 vec, float velocity)
{
	m_fptLookAt = m_fptLookAt + vec * velocity * fDT;
	m_fptCurLookAt = m_fptCurLookAt + vec * velocity * fDT;

	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);
	m_fptDiff = m_fptCurLookAt - fptCenter;
}

void CCameraManager::CalDiff()
{
	m_fAccTime += fDT;

	// �ð��� ������, �����Ѱ����� ����
	if (m_fTime <= m_fAccTime)
	{
		m_fptCurLookAt = m_fptLookAt;
	}
	else
	{
		fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);

		m_fptCurLookAt = m_fptPrevLookAt + (m_fptLookAt - m_fptPrevLookAt).normalize() * m_fSpeed * fDT;
		m_fptDiff = m_fptCurLookAt - fptCenter;
		m_fptPrevLookAt = m_fptCurLookAt;
	}
}
