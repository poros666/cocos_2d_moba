
#ifndef __CLIENT_GAME_H__
#define __CLIENT_GAME_H__

#include <boost/asio.hpp>
#include <vector>
#include <string>
#include<thread>
#include"command.h"
using namespace boost::asio;
class Client
{
private:
	//单例设计，构造隐藏
	Client();
	~Client();
	Client& operator=(const Client&) = delete;
	static Client* instance;
	//client中的数据
	io_service io;
	ip::tcp::endpoint ep; //连接地址
	ip::tcp::endpoint message_ep; //聊天连接地址
	std::shared_ptr<ip::tcp::socket> sock;  //套接字指针
	std::shared_ptr<ip::tcp::socket> message_sock;//聊天套接字指针
public:
	bool isConnected; //是否连接成功的标记
	static Client* getInstance(); //获取单例
	bool connectWithServer(); //建立连接
	bool checkConnect();   //确认连接 Note:第一次接收信息！！调用级别:必须，S1，一次调用
						  //内有while循环，只有对方连接时才结束函数返回结果
	void sendOwnHero(int hero_role); //发送己方英雄类型 Note:第一次发送信息！！调用级别：必须，S2，一次调用
	command receiveHero();   //接收对方英雄类型 Note:第二次接收信息！！ 调用级别：必须，S3,一次调用
						 //内有while true循环
	void sendAttack();  //发送攻击信号 调用：键盘函数里调用（注意一下次数）
	void sendClickPos(float x, float y); //发送鼠标点击位置 调用：点击函数里调用（注意一下次数）
	std::vector<command> getCommands(); //接收对方指令集 调用：UPDATE里
	void sendMessage(std::string& text);//发送聊天信息
	std::string getMessage();       //接收聊天信息
	void clear();          //关闭客户端 调用：一局结束以后或某个客户端临时退出
	void destory();       //清理客户端 调用级别：必须！！游戏彻底退出时调用，释放内存
};




#endif