#pragma once

#include "SocketBase.h"

class SocketClient : public SocketBase
{
public:
	SocketClient(void);
	~SocketClient(void);
	bool connectServer(const char* serverIP, unsigned short port);
	void sendMessage(const char* data, int count);
	std::function<void(const char* data, int count)> onRecv;
	std::function<void()> onDisconnect;
	void recvMessage();
private:
	bool initClient();
public:
	HSocket _socketServer;
	HSocket _socektClient;
};
