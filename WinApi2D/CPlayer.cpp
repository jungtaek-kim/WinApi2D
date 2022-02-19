#include "framework.h"
#include "CPlayer.h"

void CPlayer::update()
{
	fPoint pos = GetPos();

	if (CKeyManager::getInst()->GetButton(VK_LEFT))
	{
		pos.x -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_RIGHT))
	{
		pos.x += 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_UP))
	{
		pos.y -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (CKeyManager::getInst()->GetButton(VK_DOWN))
	{
		pos.y += 100 * CTimeManager::getInst()->GetDT();
	}

	SetPos(pos);
}

void CPlayer::render(HDC hDC)
{
	Rectangle(hDC,
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2);
}
