#pragma once
#include "cocos2d.h"
#include <list>
#include <thread>
USING_NS_CC;

#include <WinSock2.h>
#pragma comment(lib, "WS2_32.lib")
#define HSocket SOCKET
class SocketBase : public Ref
{
public:
	SocketBase();
	~SocketBase();
protected:
	void closeConnect(HSocket socket);
	bool error(HSocket socket);
protected:
	std::mutex _mutex;
private:
	bool _bInitSuccess;
};
