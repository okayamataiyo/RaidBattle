#include "Client.h"

bool Client::ClientCom()
{
    #ifdef _DEBUG
    OutputDebugString("Client");
    #endif // _DEBUG
    
    //WinSock������
    WSADATA wsaData;
    ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (ret != 0)
    {
        #ifdef _DEBUG
        OutputDebugString("Error: WSAStartup( ErrorCode:" + ret + ')' + '\n');
        #endif //_DEBUG
        return 1;
    }

    //�\�P�b�g�̍쐬
    int listenSock;
    listenSock = socket(AF_INET, SOCK_STREAM, 0);/*TCP�\�P�b�g�̍쐬 */

    if (listenSock < 0)//�\�P�b�g�̍쐬�Ɏ��s������ )
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

    //�ʐM�p�\�P�b�g(�T�[�o�[�̃\�P�b�g�ƁA���̃\�P�b�g�ԂɃR�l�N�V�������m��)
	struct sockaddr_in serverAddr;
    int addrlen = sizeof(serverAddr);
    sock = accept(listenSock, (struct sockAddr*)&serverAddr, &addrlen);

    if(sock < 0){
        #ifdef _DEBUG
		OutputDebugString("Error: accept ( ErrorCode:" + sock + ')' + '\n');
        #endif // _DEBUG
    }
    /*
    �ڑ��v����t
    �R�l�N�V�����m��
    �R�l�N�V�����m���ς݃\�P�b�g�̍쐬
    */
    while (true)
    {
        struct TestStruct value;
        Recv(sock, &value);
    }

	// ����M�Ƃ��ɐؒf
	// shutdown(sock, 0x02);
	if (shutdown(sock, SD_BOTH) != 0)
	{
		// �G���[�R�[�h���o��
        #ifdef _DEBUG
		OutputDebugString("Error: shutdown( ErrorCode: " + WSAGetLastError() + ')' + '\n');
        #endif // _DEBUG
	}

	// �\�P�b�g�̔j��
	if (closesocket(sock) != 0)
	{
		// �G���[�R�[�h���o��
        #ifdef _DEBUG
   		OutputDebugString("Error: closesocket( ErrorCode: " + WSAGetLastError() + ')' + '\n');
        #endif // _DEBUG
	}

	if (closesocket(listenSock) != 0)
	{
		// �G���[�R�[�h���o��
        #ifdef _DEBUG
		OutputDebugString("Error: closesocket( ErrorCode: " + WSAGetLastError() + ')' + '\n');
        #endif // _DEBUG	
	}

	// WinSock�I������
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



//�N���C�A���g�����T�[�o�ɐڑ�����
//����͂łh�o����͂���K�v������H
//�Q�[�����őłH�_�C�A���O�o���Ă����ɑł����ށH