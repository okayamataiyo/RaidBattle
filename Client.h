#pragma once
#include "Socket.h"

#define WIN32_LEAN_AND_MEAN
#include<Windows.h>
#include<WinSock2.h>
#include<ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#include<String>
#include<DirectXMath.h>

using namespace std;
using namespace DirectX;
const int SERVERPORT{ 8888 };
//127.0.0.2
class Client :
    public Socket
{
private:
    int sock;
    int ret;
	STARTUPINFO si{};
	PROCESS_INFORMATION pi{};

	si.cb = sizeof(si);

    struct TestStruct {
        string name;
        int x;
        int y;
        int hp;
    };

public:
    bool ClientCom();

	/// <summary>
	/// 構造体データをサーバーに送信
	/// </summary>
    bool sendStruct(int sock, struct TestStruct test);

	/// <summary>
	/// ゲームを起動
	/// </summary>
	void GameStandup() { CreateProcess(L"Server.exe", nullptr, nullptr, nullptr, false, 0, nullptr, nullptr, &si, &pi); }

	/// <summary>
	/// 画面表示
	/// </summary>
    void Draw();

	/// <summary>
	/// ダイアログ表示
	/// </summary>
    void DrawDialog();

	/// <summary>
	/// サーバーのIPを入力
	/// </summary>
    void SearchServer();

	/// <summary>
	/// サーバーに接続
	/// </summary>|
	void ServerIn();

};

