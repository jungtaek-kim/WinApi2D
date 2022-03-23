#include "framework.h"
#include "CIdleState.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CAnimator.h"

CIdleState::CIdleState(STATE_MON state)
	: CState(state)
{
}

CIdleState::~CIdleState()
{
}

void CIdleState::update()
{
	CPlayer* pPlayer = CPlayer::GetPlayer();
	if (nullptr == pPlayer)
		return;

	fPoint fptPlayerPos = pPlayer->GetPos();

	CMonster* pMonster = GetMonster();
	fPoint fptMonsterPos = pMonster->GetPos();

	fVec2 fvDiff = fptPlayerPos - fptMonsterPos;
	float fLen = fvDiff.Length();
	if (fLen < pMonster->GetMonInfo().fRecogRange)
	{
		ChangeAIState(GetOwnerAI(), STATE_MON::TRACE);
	}
	pMonster->GetAnimator()->Play(L"PlayerStand");
}

void CIdleState::Enter()
{
}

void CIdleState::Exit()
{
}
