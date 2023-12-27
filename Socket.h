#pragma once

class Socket
{
private:

public:
	void WSAStartup();
	void SocketCreate();
	void Bind();
	void Send();
	void Recv();
	void CloseSocket();
	void WSACleanup();
};

