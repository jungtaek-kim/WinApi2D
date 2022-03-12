#include "framework.h"
#include "Map_Start.h"
#include "CD2DImage.h"

Map_Start::Map_Start()
{
    pimg = new CD2DImage;
    pimg = CResourceManager::getInst()->LoadD2DImage(L"test", L"texture\\map\\Test.png");
}

Map_Start::~Map_Start()
{
}

Map_Start* Map_Start::Clone()
{
    return nullptr;
}

void Map_Start::update()
{
}

void Map_Start::render(HDC hDC)
{
    pimg->render();
}
