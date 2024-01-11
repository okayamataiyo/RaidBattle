#include "Server.h"

bool Server::ServerCom()
{
	#ifdef _DEBUG
	OutputDebugString("Server");
	#endif // _DEBUG
	
	// WinSock������
	WSADATA wsaData;
	ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (ret != 0)
	{
		#ifdef _DEBUG
		OutputDebugString("Error: WSAStartup ( ErrorCode:" + ret + ')' + '\n');
		#endif // _DEBUG
		return 1;	// ���[���I
	}
	
	// ���X���\�P�b�g�̍쐬
	int listenSock;
	listenSock = socket(AF_INET, SOCK_STREAM, 0);

	if (listenSock < 0)
	{
		#ifdef _DEBUG
		OutputDebugString("Error: listenSocket ( ErrorCode:" + ret + ')' + '\n');
		#endif // _DEBUG
	}

	struct sockaddr_in bindAddr;	// bind�p�̃\�P�b�g�A�h���X���
	memset(&bindAddr, 0, sizeof(bindAddr));
	bindAddr.sin_family = AF_INET;
	bindAddr.sin_port = htons(SERVERPORT);
	bindAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(listenSock, (struct sockaddr*)&bindAddr, sizeof(bindAddr)) != 0) {
		#ifdef _DEBUG
		OutputDebugString("Error: Bind ( ErrorCode:" + ret + ')' + '\n');
		#endif // _DEBUG
	}

	if (listen(listenSock, 1) != 0) {
		#ifdef _DEBUG
		OutputDebugString("Error: listen ( ErrorCode:" + ret + ')' + '\n');
		#endif // _DEBUG
	}

	// �ʐM�p�\�P�b�g ( �N���C�A���g�̃\�P�b�g�Ƃ��̃\�P�b�g�ԂɃR�l�N�V�������m�� )
	int sock;
	struct sockaddr_in	 clientAddr;
	int addrlen = sizeof(clientAddr);
	sock = accept(listenSock, (struct sockaddr*)&clientAddr, &addrlen);

	if (sock < 0) {
		#ifdef _DEBUG
		OutputDebugString("Error: accept ( ErrorCode:" + ret + ')' + '\n');
		#endif // _DEBUG
	}
	/*
	�ڑ��v����t
	�R�l�N�V�����m��
	�R�l�N�V�����m���ς݃\�P�b�g�̍쐬
	*/
	unsigned int buff = 0;
	while (true)
	{
		struct TestStruct value;
		Recv(sock, &value);
		cout << "Name:" << value.name << endl;
		cout << "Pos;(" << value.x << "," << value.y << ")" << endl;
		cout << "hp:" << value.hp << endl;
	}

	// ����M�Ƃ��ɐؒf
	// shutdown(sock, 0x02);
	if (shutdown(sock, SD_BOTH) != 0)
	{
		// �G���[�R�[�h���o��
		#ifdef _DEBUG
		OutputDebugString("Error: shutdown( ErrorCode: " + WSAGetLastError() +')' + '\n');
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

template<class T>
inline bool Server::Send(int sock, const T& value)
{

}