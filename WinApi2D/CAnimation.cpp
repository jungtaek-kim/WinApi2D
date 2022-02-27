#include "framework.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CGameObject.h"
#include "CTexture.h"

CAnimation::CAnimation()
{
    m_strName = L"";
    m_pAnimator = nullptr;
    m_pTex = nullptr;
    m_iCurFrm = -1;
}

CAnimation::~CAnimation()
{
}

void CAnimation::SetName(const wstring& strName)
{
    m_strName = strName;
}

const wstring& CAnimation::GetName()
{
    return m_strName;
}

void CAnimation::update()
{
    // TODO : �ִϸ��̼� ������ ��ȯ
    m_iCurFrm = 0;
}

void CAnimation::render(HDC hDC)
{
    CGameObject* pObj = m_pAnimator->GetObj();
    fPoint fptPos = pObj->GetPos();
    tAniFrm frm = m_vecFrm[m_iCurFrm];

    TransparentBlt(hDC,
        (int)(fptPos.x - frm.fptSlice.x / 2.f),
        (int)(fptPos.y - frm.fptSlice.y / 2.f),
        (int)(frm.fptSlice.x),
        (int)(frm.fptSlice.y),
        m_pTex->GetDC(),
        (int)(frm.fptLT.x),
        (int)(frm.fptLT.y),
        (int)(frm.fptSlice.x),
        (int)(frm.fptSlice.y),
        RGB(255, 0, 255));
}

void CAnimation::Create(CTexture* tex,      // �ִϸ��̼��� �̹���
                        fPoint lt,          // �ִϸ��̼� ���� �������� �»�� ��ǥ
                        fPoint slice,       // �ִϸ��̼� �������� ũ��
                        fPoint step,        // �ִϸ��̼� �������� �ݺ� ��ġ
                        float duration,     // �ִϸ��̼� ������ ���ӽð�
                        UINT frmCount)      // �ִϸ��̼� ������ ����
{
    m_pTex = tex;

    tAniFrm frm = {};
    for (UINT i = 0; i < frmCount; i++)
    {
        frm.fDuration = duration;
        frm.fptSlice = slice;
        frm.fptLT = lt + step * i;

        m_vecFrm.push_back(frm);
    }
}
