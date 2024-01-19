#include "Client.h"

bool Client::ClientCom()
{
    #ifdef _DEBUG
    OutputDebugString("Client");
    #endif // _DEBUG
    
    //WinSock初期化
    WSADATA wsaData;
    ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (ret != 0)
    {
        #ifdef _DEBUG
        OutputDebugString("Error: WSAStartup( ErrorCode:" + ret + ')' + '\n');
        #endif //_DEBUG
        return 1;
    }

    //ソケットの作成
    int listenSock;
    listenSock = socket(AF_INET, SOCK_STREAM, 0);/*TCPソケットの作成 */

    if (listenSock < 0)//ソケットの作成に失敗したら )
    {
        #ifdef _DEBUG
        OutputDebugString("Error: WSAStartup( ErrorCode:" + listenSock + ')' + '\n');
        #endif  //_DEBUG
    }

    struct sockaddr_in bindAddr;
    memset(&bindAddr, 0, sizeof(bindAddr));
    bindAddr.sin_family = AF_INET;
	bindAddr.sin_port = htons(SERVERPORT);
	bindAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listenSock,(struct sockaddr*)&bindAddr, sizeof(bindAddr)) != 0){
        #ifdef _DEBUG
		OutputDebugString("Error: Bind ( ErrorCode:" + ret + ')' + '\n');
        #endif // _DEBUG
    }

	if (listen(listenSock, 1) != 0) {
        #ifdef _DEBUG
		OutputDebugString("Error: listen ( ErrorCode:" + ret + ')' + '\n');
        #endif // _DEBUG
	}

    //通信用ソケット(サーバーのソケットと、このソケット間にコネクションが確率)
	struct sockaddr_in serverAddr;
    int addrlen = sizeof(serverAddr);
    sock = accept(listenSock, (struct sockAddr*)&serverAddr, &addrlen);

    if(sock < 0){
        #ifdef _DEBUG
		OutputDebugString("Error: accept ( ErrorCode:" + sock + ')' + '\n');
        #endif // _DEBUG
    }
    /*
    接続要求受付
    コネクション確立
    コネクション確立済みソケットの作成
    */
    while (true)
    {
        struct TestStruct value;
        Recv(sock, &value);
    }

	// 送受信ともに切断
	// shutdown(sock, 0x02);
	if (shutdown(sock, SD_BOTH) != 0)
	{
		// エラーコードを出力
        #ifdef _DEBUG
		OutputDebugString("Error: shutdown( ErrorCode: " + WSAGetLastError() + ')' + '\n');
        #endif // _DEBUG
	}

	// ソケットの破棄
	if (closesocket(sock) != 0)
	{
		// エラーコードを出力
        #ifdef _DEBUG
   		OutputDebugString("Error: closesocket( ErrorCode: " + WSAGetLastError() + ')' + '\n');
        #endif // _DEBUG
	}

	if (closesocket(listenSock) != 0)
	{
		// エラーコードを出力
        #ifdef _DEBUG
		OutputDebugString("Error: closesocket( ErrorCode: " + WSAGetLastError() + ')' + '\n');
        #endif // _DEBUG	
	}

	// WinSock終了処理
	if (WSACleanup() != 0)
	{
        #ifdef _DEBUG
		OutputDebugString("Error: WSACleanup( ErrorCode: " + WSAGetLastError() + ')' + '\n');
        #endif // _DEBUG
	}
}

bool Client::sendStruct(int sock, TestStruct test)
{
	struct TestStruct temp;
	temp.hp = htonl(test.hp);
	temp.hp = htonl(test.x);
	temp.hp = htonl(test.y);
	int ret = send(sock, (char*)&test, sizeof(test), 0);
	if (ret != sizeof(test))
	{
		return false;
	}
	return true;
}

void Client::Draw()
{

}

void Client::DrawDialog()
{

}

void Client::SearchServer()
{

}

void Client::ServerIn()
{

}



//クライアント側がサーバに接続する
//手入力でＩＰを入力する必要がある？
//ゲーム内で打つ？ダイアログ出してそこに打ち込む？