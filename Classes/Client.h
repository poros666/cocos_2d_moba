
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
	//������ƣ���������
	Client();
	~Client();
	Client& operator=(const Client&) = delete;
	static Client* instance;
	//client�е�����
	io_service io;
	ip::tcp::endpoint ep; //���ӵ�ַ
	ip::tcp::endpoint message_ep; //�������ӵ�ַ
	std::shared_ptr<ip::tcp::socket> sock;  //�׽���ָ��
	std::shared_ptr<ip::tcp::socket> message_sock;//�����׽���ָ��
public:
	bool isConnected; //�Ƿ����ӳɹ��ı��
	static Client* getInstance(); //��ȡ����
	bool connectWithServer(); //��������
	bool checkConnect();   //ȷ������ Note:��һ�ν�����Ϣ�������ü���:���룬S1��һ�ε���
						  //����whileѭ����ֻ�жԷ�����ʱ�Ž����������ؽ��
	void sendOwnHero(int hero_role); //���ͼ���Ӣ������ Note:��һ�η�����Ϣ�������ü��𣺱��룬S2��һ�ε���
	command receiveHero();   //���նԷ�Ӣ������ Note:�ڶ��ν�����Ϣ���� ���ü��𣺱��룬S3,һ�ε���
						 //����while trueѭ��
	void sendAttack();  //���͹����ź� ���ã����̺�������ã�ע��һ�´�����
	void sendClickPos(float x, float y); //���������λ�� ���ã������������ã�ע��һ�´�����
	std::vector<command> getCommands(); //���նԷ�ָ� ���ã�UPDATE��
	void sendMessage(std::string& text);//����������Ϣ
	std::string getMessage();       //����������Ϣ
	void clear();          //�رտͻ��� ���ã�һ�ֽ����Ժ��ĳ���ͻ�����ʱ�˳�
	void destory();       //����ͻ��� ���ü��𣺱��룡����Ϸ�����˳�ʱ���ã��ͷ��ڴ�
};




#endif