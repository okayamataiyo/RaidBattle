#include "Client.h"

bool Client::ClientCom()
{
    #ifdef _DEBUG
    OutputDebugString("Server");
    #endif // _DEBUG

    //WinSock初期化
    WSADATA wsaData;
    int ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (ret != 0)
    {
        cout << "Error: WSAStartup ( ErrorCode:" << ret << " )" << endl;
        return 1;	//おーわり！
    }
    cout << "Success: WSAStartup" << endl;

    //ソケットの作成
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);/*TCPソケットの作成 */

    if (sock < 0)//ソケットの作成に失敗したら )
    {
        //エラー処理して終わり
        cout << "Error: Socket(ErrorCode: " << WSAGetLastError() << ")" << endl;
        return -1;
    }

    cout << "Success: socket()" << endl;

    if (ret == SOCKET_ERROR)
    {
        //エラー処理
        return 1;
    }
    cout << "Success: ioctsocket()" << endl;

    //sockをノンブロッキングモードにする
    unsigned long cmdarg = 0x01;
    ret = ioctlsocket(sock, FIONBIO, &cmdarg);

    /*
        サーバのIPアドレスを入力
        サーバのソケットアドレス情報をセット
    */
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVERPORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr.s_addr);   //ほんとはよくない。せめて127.0.0.1を定数化

    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0)
    {

    }
    cout << "Success: connect()" << endl;
    /*
        接続要求
        コネクション確立
    */

    while (true)
    {
        /*
        メッセージ入力
        サーバへの文字列送信
        */
        cout << "Input message:";
        cin >> buff;
        ret = send(sock, buff, strlen(buff), 0);
        if (ret != strlen(buff))
        {

        }

        /*
            サーバから文字列受信
            出力
        */
        ret = recv(sock, buff, sizeof(buff) - 1, 0);
        if (ret < 0)
        {
            //エラーコードがWSAEWOULDBLOCKの場合は、受信データがなかったってこと
            if (WSAGetLastError() == WSAEWOULDBLOCK)
            {
                cout << "受信データなし" << endl;
            }
            else
            {
                //エラーコードを出力
                cout << "Error: recv(ErrorCode: " << WSAGetLastError() << ")" << endl;
                break;
            }
            //エラーコードを出力
            cout << "Error: recv(ErrorCode: " << WSAGetLastError() << ")" << endl;
            break;
        }
        //終端記号の追加
        buff[ret] = '\0';
        cout << buff << endl;
    }
}