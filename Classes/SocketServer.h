#pragma once
#include "SocketBase.h"
class SocketServer : public SocketBase
{
public:
	static SocketServer* create();
	SocketServer();
	~SocketServer();
	bool startServer();
	void sendMessage(HSocket socket, const char* data, int count);
	void sendMessage(const char* data, int count);
	std::function<void(const char* ip)> onStart;
	std::function<void(HSocket socket)> onNewConnection;
	std::function<void(const char* data, int count)> onRecv;
	std::function<void(HSocket socket)> onDisconnect;
private:
	bool initServer();
	void acceptClient();
	void acceptFunc();
	void newClientConnected(HSocket socket);
	void recvMessage(HSocket socket);
private:
	HSocket _socketServer;
	std::list<HSocket> _clientSockets;
};