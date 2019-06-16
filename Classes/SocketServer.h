#pragma once
#include "SocketBase.h"
class SocketServer : public SocketBase
{
public:
	static SocketServer* create();
	SocketServer();
	~SocketServer();
	bool startServer();
	void sendMessage(const char* data, int count);
	void recvMessage();
	std::function<void(const char* ip)> onStart;
	std::function<void(HSocket socket)> onNewConnection;
	std::function<void(const char* data, int count)> onRecv;
	std::function<void(HSocket socket)> onDisconnect;
private:
	bool initServer();
	void acceptFunc();
	void newClientConnected(HSocket socket);
	
public:
	HSocket _socketServer;
	HSocket _clientSockets;
};