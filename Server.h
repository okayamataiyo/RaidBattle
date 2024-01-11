#pragma once
#include "Socket.h"

#define  WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinSock2.h> 
#include<ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#include<String>
#include<DirectXMath.h>

using namespace std;
using namespace DirectX;
const int SERVERPORT{ 8888 };
//127.0.0.2
class Server :
    public Socket
{
private:
    int sock;
    int ret;

    struct TestStruct {
        string name;
        int x;
        int y;
        int hp;
    };

public:
    bool ServerCom();

    template<class T>bool Send(int sock, const T& value);



};

//SendTo<int>();

