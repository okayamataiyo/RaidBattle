#include "TestScene.h"
#include "Player.h"
#include "Ore.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	//Playerのインスタンスを生成＆初期化
	pPlayer_ = Instantiate<Player>(this);
	Instantiate<Ore>(this);
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
