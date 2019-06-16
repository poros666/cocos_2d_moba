#include "SocketClient.h"
SocketClient::SocketClient(void) :
	onRecv(nullptr),
	_socektClient(0)
{

}





SocketClient::~SocketClient(void)
{
	if (_socektClient != 0)
	{
		_mutex.lock();
		this->closeConnect(_socektClient);
		_mutex.unlock();
	}
}



bool SocketClient::initClient()
{
	if (_socektClient != 0)
	{
		_mutex.lock();
		this->closeConnect(_socektClient);
		_mutex.unlock();
	}
	_socektClient = socket(AF_INET, SOCK_STREAM, 0);
	if (error(_socketServer))
	{
		log("init client error!");
		_socektClient = 0;
		return false;
	}
	return true;
}



bool SocketClient::connectServer(const char* serverIP, unsigned short port)
{
	if (!this->initClient())
	{
		return false;
	}
	struct sockaddr_in serverAddr;
	memset(&serverAddr, 0, sizeof(struct sockaddr_in));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr(serverIP);
	int ret = 0;
	ret = connect(_socektClient, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr));
	if (ret < 0)
	{
		this->closeConnect(_socektClient);
		_socektClient = 0;
		return false;
	}
	return true;
}



void SocketClient::recvMessage()
{
	char recvBuf[1024];
	int ret = 0;

	ret = recv(_socektClient, recvBuf, sizeof(recvBuf), 0);
	if (ret < 0)
	{
		log("recv error");
		return;
	}
	if (ret > 0 && onRecv != nullptr)
	{
		onRecv(recvBuf, ret);
	}
}



void SocketClient::sendMessage(const char* data, int count)
{
	if (_socektClient != 0)
	{
		int ret = send(_socektClient, data, count, 0);
		if (ret < 0)
		{
			log("send error!");
		}
	}
}
