
#pragma once
#ifndef __COMMAND_GAME_H__
#define __COMMAND_GAME_H__

enum CommandType { connection = 0, heroInform, attackInform, clickInform, exitConnect };


class command
{
public:
	bool use_flag;        //����Ƿ�Ϊ��Ч��Ϣ
	int command_type;    //�����Ϣ����
	bool connected;      //������Ϣ
	int hero_type;       //Ӣ��������Ϣ
	bool hero_attack;    //Ӣ�۹�����Ϣ
	float click_x;        //�����λ��
	float click_y;
	int player_type;      //���ֿͻ���
	command() :use_flag(false), command_type(-1), connected(false), hero_type(-1), hero_attack(false), click_x(0.0), click_y(0.0), player_type(0) {}
};

#endif