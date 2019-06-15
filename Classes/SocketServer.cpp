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
	_clientSockets.clear();
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
		this->acceptClient();
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

 

void SocketServer::acceptClient()
{
	std::thread th(&SocketServer::acceptFunc, this);
	th.detach();
}

 

void SocketServer::acceptFunc()
{
	int len = sizeof(sockaddr);
	struct sockaddr_in sockAddr;
	while (true)
	{	
		HSocket clientSock = accept(_socketServer, (sockaddr*)&sockAddr, &len);
		if (error(clientSock))
		{
			log("accept error!");
			break;
		}
		this->newClientConnected(clientSock);
	}
}

 

void SocketServer::newClientConnected(HSocket socket)
{
	log("new connect!");
	_clientSockets.push_back(socket);
	std::thread th(&SocketServer::recvMessage, this, socket);
	th.detach();
	if (onNewConnection != nullptr)
	{
		onNewConnection(socket);
	}
}

 

void SocketServer::recvMessage(HSocket socket)
{
	char buff[1024];
	int ret = 0;
	while (true)
	{
		ret = recv(socket, buff, sizeof(buff), 0);
		if (ret < 0)
		{
			log("recv(%d) error!", socket);
			_mutex.lock();
			this->closeConnect(socket);
			_clientSockets.remove(socket);
			if (onDisconnect != nullptr)
			{
				onDisconnect(socket);
			}
			_mutex.unlock();
			break;
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
}

 

void SocketServer::sendMessage(HSocket socket, const char* data, int count)
{
	for (auto& sock : _clientSockets)
	{
		if (sock == socket)
		{
			int ret = send(socket, data, count, 0);
			if (ret < 0)
			{
				log("send error!");
			}
			break;
		}
	}
}

 

void SocketServer::sendMessage(const char* data, int count)
{
	for (auto& socket : _clientSockets)
	{
		int ret = send(socket, data, count, 0);
		if (ret < 0)
		{
			log("send error!");
		}
	}
}
