#include "framework.h"
#include "CScene_Tool.h"
#include "CTile.h"
#include "resource.h"
#include "CScene.h"
#include "CTexture.h"

INT_PTR CALLBACK TileWinProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

CScene_Tool::CScene_Tool()
{
	m_hWnd = 0;
	m_iIdx = 0;
}

CScene_Tool::~CScene_Tool()
{
}

void CScene_Tool::update()
{
	CScene::update();

	if (KeyDown(VK_TAB))
	{
		ChangeScn(GROUP_SCENE::START);
	}

	SetTileIdx();
}

void CScene_Tool::Enter()
{
	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));

	CreateTile(5, 5);

	m_hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TILEBOX), hWnd, TileWinProc);
	ShowWindow(m_hWnd, SW_SHOW);
}

void CScene_Tool::Exit()
{
	EndDialog(m_hWnd, IDOK);
	DeleteGroup(GROUP_GAMEOBJ::TILE);
}

void CScene_Tool::SetIdx(UINT idx)
{
	m_iIdx = idx;
}

void CScene_Tool::SetTileIdx()
{
	if (Key(VK_LBUTTON))
	{
		fPoint fptMousePos = MousePos();
		fptMousePos = CCameraManager::getInst()->GetRealPos(fptMousePos);

		int iTileX = (int)GetTileX();
		int iTileY = (int)GetTileY();

		int iCol = (int)fptMousePos.x / CTile::SIZE_TILE;
		int iRow = (int)fptMousePos.y / CTile::SIZE_TILE;

		if (fptMousePos.x < 0.f || iTileX <= iCol ||
			fptMousePos.y < 0.f || iTileY <= iRow)
		{
			return;		// 타일이 없는 위치 무시
		}

		UINT iIdx = iRow * iTileX + iCol;
		const vector<CGameObject*>& vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);
		((CTile*)vecTile[iIdx])->SetImgIdx(m_iIdx);
	}
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK TileWinProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_BUTTON_SIZE)
		{
			int x = GetDlgItemInt(hDlg, IDC_EDIT_SIZEX, nullptr, false);
			int y = GetDlgItemInt(hDlg, IDC_EDIT_SIZEY, nullptr, false);

			CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
			assert(pToolScene);

			pToolScene->DeleteGroup(GROUP_GAMEOBJ::TILE);
			pToolScene->CreateTile(x, y);
		}
		else if (LOWORD(wParam) == IDC_BUTTON_TILE)
		{
			int m_iIdx = GetDlgItemInt(hDlg, IDC_EDIT_TILE, nullptr, false);

			CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
			assert(pToolScene);

			CTexture* pTex = CResourceManager::getInst()->FindTexture(L"Tile");

			UINT iWidth = pTex->GetBmpWidth();
			UINT iHeight = pTex->GetBmpHeight();

			UINT iMaxRow = iHeight / CTile::SIZE_TILE;
			UINT iMaxCol = iWidth / CTile::SIZE_TILE;

			UINT iCurRow = (m_iIdx / iMaxCol) % iMaxRow;
			UINT iCurCol = (m_iIdx % iMaxCol);

			BitBlt(GetDC(hDlg),
				(int)(150),
				(int)(150),
				(int)(CTile::SIZE_TILE),
				(int)(CTile::SIZE_TILE),
				pTex->GetDC(),
				(int)(iCurCol * CTile::SIZE_TILE),
				(int)(iCurRow * CTile::SIZE_TILE),
				SRCCOPY);

			pToolScene->SetIdx(m_iIdx);
		}
		break;
	}
	return (INT_PTR)FALSE;
}