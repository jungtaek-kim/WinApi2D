#include "framework.h"
#include "CScene_Title.h"
#include "CImageObject.h"
#include "CImageButton.h"

CScene_Title::CScene_Title()
{
}

CScene_Title::~CScene_Title()
{
}

void ClickStartButton(DWORD_PTR, DWORD_PTR)
{
	//ChangeScn(GROUP_SCENE::STAGE_01);
}

void ClickExitButton(DWORD_PTR, DWORD_PTR)
{
	PostQuitMessage(0);
}

void CScene_Title::Enter()
{
	// TODO :
	// 1. 배경 출력
	CImageObject* backgroundObject = new CImageObject;
	backgroundObject->Load(L"BackImage", L"texture\\background.png");
	backgroundObject->SetPos(fPoint(0.f, 0.f));
	backgroundObject->SetScale(fPoint(WINSIZEX, WINSIZEY));
	AddObject(backgroundObject, GROUP_GAMEOBJ::BACKGROUND);

	// 2. 로고 출력용 오브젝트 제작
	CImageObject* logoObject = new CImageObject;
	logoObject->Load(L"LogoImage", L"texture\\titleImage.png");
	logoObject->SetPos(fPoint(100.f, 100.f));
	logoObject->SetScale(fPoint(1080.f, 200.f));
	AddObject(logoObject, GROUP_GAMEOBJ::BACKGROUND);

	// 3. 시작 버튼
	CImageButton* startButton = new CImageButton;
	startButton->Load(L"Button", L"texture\\button.png");
	startButton->SetText(L"시작 하기");
	startButton->SetPos(fPoint(WINSIZEX / 2.f - 100.f, 500.f));
	startButton->SetScale(fPoint(200.f, 50.f));
	startButton->SetClickedCallBack(ClickStartButton, 0, 0);
	AddObject(startButton, GROUP_GAMEOBJ::UI);
	// 4. 종료 버튼

	CImageButton* exitButton = new CImageButton;
	exitButton->Load(L"Button", L"texture\\button.png");
	exitButton->SetText(L"종료");
	exitButton->SetPos(fPoint(WINSIZEX / 2.f - 100.f, 600.f));
	exitButton->SetScale(fPoint(200.f, 50.f));
	exitButton->SetClickedCallBack(ClickExitButton, 0, 0);
	AddObject(exitButton, GROUP_GAMEOBJ::UI);
}

void CScene_Title::Exit()
{
}
