#include "TestScene2.h"

#include "Point.h"
#include "Player.h"

TestScene2::TestScene2(GameObject* parent)
{
}

void TestScene2::Initialize()
{
	Instantiate<Point>(this);
	Instantiate<Player>(this);

}

void TestScene2::Update()
{
}

void TestScene2::Draw()
{
}

void TestScene2::Release()
{
}
