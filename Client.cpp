#include "Client.h"

bool Client::ClientCom()
{
    #ifdef _DEBUG
    OutputDebugString("Server");
    #endif // _DEBUG

    //WinSock������
    WSADATA wsaData;
    int ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (ret != 0)
    {
        cout << "Error: WSAStartup ( ErrorCode:" << ret << " )" << endl;
        return 1;	//���[���I
    }
    cout << "Success: WSAStartup" << endl;

    //�\�P�b�g�̍쐬
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);/*TCP�\�P�b�g�̍쐬 */

    if (sock < 0)//�\�P�b�g�̍쐬�Ɏ��s������ )
    {
        //�G���[�������ďI���
        cout << "Error: Socket(ErrorCode: " << WSAGetLastError() << ")" << endl;
        return -1;
    }

    cout << "Success: socket()" << endl;

    if (ret == SOCKET_ERROR)
    {
        //�G���[����
        return 1;
    }
    cout << "Success: ioctsocket()" << endl;

    //sock���m���u���b�L���O���[�h�ɂ���
    unsigned long cmdarg = 0x01;
    ret = ioctlsocket(sock, FIONBIO, &cmdarg);

    /*
        �T�[�o��IP�A�h���X�����
        �T�[�o�̃\�P�b�g�A�h���X�����Z�b�g
    */
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVERPORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr.s_addr);   //�ق�Ƃ͂悭�Ȃ��B���߂�127.0.0.1��萔��

    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0)
    {

    }
    cout << "Success: connect()" << endl;
    /*
        �ڑ��v��
        �R�l�N�V�����m��
    */

    while (true)
    {
        /*
        ���b�Z�[�W����
        �T�[�o�ւ̕����񑗐M
        */
        cout << "Input message:";
        cin >> buff;
        ret = send(sock, buff, strlen(buff), 0);
        if (ret != strlen(buff))
        {

        }

        /*
            �T�[�o���當�����M
            �o��
        */
        ret = recv(sock, buff, sizeof(buff) - 1, 0);
        if (ret < 0)
        {
            //�G���[�R�[�h��WSAEWOULDBLOCK�̏ꍇ�́A��M�f�[�^���Ȃ��������Ă���
            if (WSAGetLastError() == WSAEWOULDBLOCK)
            {
                cout << "��M�f�[�^�Ȃ�" << endl;
            }
            else
            {
                //�G���[�R�[�h���o��
                cout << "Error: recv(ErrorCode: " << WSAGetLastError() << ")" << endl;
                break;
            }
            //�G���[�R�[�h���o��
            cout << "Error: recv(ErrorCode: " << WSAGetLastError() << ")" << endl;
            break;
        }
        //�I�[�L���̒ǉ�
        buff[ret] = '\0';
        cout << buff << endl;
    }
}