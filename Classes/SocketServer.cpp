#include "SocketServer.h"

SocketServer* SocketServer::create()
{
	auto server = new SocketServer;
	return server;
}

 

SocketServer::SocketServer() :
	_socketServer(0),
	onRecv(nullptr),
	onStart(nullptr),
	onNewConnection(nullptr)
{
}

 

SocketServer::~SocketServer()
{
	if (_socketServer)
	{
		this->closeConnect(_socketServer);
	}
};

 

bool SocketServer::startServer()
{
	if (!initServer())
	{
		return false;
	} 
	return true;
}

 

bool SocketServer::initServer()
{
	if (_socketServer != 0)
	{
		this->closeConnect(_socketServer);
	}
	_socketServer = socket(AF_INET, SOCK_STREAM, 0);
	if (error(_socketServer))
	{
		log("socket error!");
		_socketServer = 0;
		return false;
	}
	do 
	{
		struct sockaddr_in sockAddr;
		memset(&sockAddr, 0, sizeof(sockAddr));
		sockAddr.sin_family = AF_INET;
		sockAddr.sin_port = htons(8000);
		sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
		int ret = 0;
		ret = bind(_socketServer, (const sockaddr*)&sockAddr, sizeof(sockAddr));
		if (ret < 0)
		{
			log("bind error!");
			break;
		}
		ret = listen(_socketServer, 5);
		if (ret < 0)
		{
			log("listen error!");
			break;
		}
		// start 
		char hostName[256];
		gethostname(hostName, sizeof(hostName));
		struct hostent* hostInfo = gethostbyname(hostName);
		char* ip = inet_ntoa(*(struct in_addr *)*hostInfo->h_addr_list);
		this->acceptFunc();
		if (onStart != nullptr)
		{
			log("start server!");
			onStart(ip);
		}
		return true;
	} while (false);
	this->closeConnect(_socketServer);
	_socketServer = 0;
	return false;
}

 
 

void SocketServer::acceptFunc()
{
	int len = sizeof(sockaddr);
	struct sockaddr_in sockAddr;
	HSocket clientSock = accept(_socketServer, (sockaddr*)&sockAddr, &len);
	if (error(clientSock))
	{
		log("accept error!");
		return;
	}
	this->newClientConnected(clientSock);
}

 

void SocketServer::newClientConnected(HSocket socket)
{
	log("new connect!");
	_clientSockets = socket;
	send(_clientSockets, "Connect", sizeof("Connect"), 0);
	if (onNewConnection != nullptr)
	{
		onNewConnection(socket);
	}
}

 

void SocketServer::recvMessage()
{
	char buff[1024];
	int ret = 0;
	ret = recv(_clientSockets, buff, sizeof(buff), 0);
	if (ret < 0)
	{
		log("recv(%d) error!", _clientSockets);
		_mutex.lock();
		this->closeConnect(_clientSockets);
		if (onDisconnect != nullptr)
		{
			onDisconnect(_clientSockets);
		}
		_mutex.unlock();
		return;
	}
	else
	{
		buff[ret] = 0;
		log("recv msg : %s", buff); 
		if (ret > 0 && onRecv != nullptr)
		{
			onRecv(buff, ret);
		}
	}
}

 

void SocketServer::sendMessage( const char* data, int count)
{
		int ret = send(_clientSockets, data, count, 0);
		if (ret < 0)
		{
			log("send error!");
		}
}

 
