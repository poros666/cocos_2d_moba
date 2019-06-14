
#pragma once
#ifndef __COMMAND_GAME_H__
#define __COMMAND_GAME_H__

enum CommandType { connection = 0, heroInform, attackInform, clickInform, exitConnect };


class command
{
public:
	bool use_flag;        //标记是否为有效信息
	int command_type;    //标记信息种类
	bool connected;      //连接信息
	int hero_type;       //英雄种类信息
	bool hero_attack;    //英雄攻击信息
	float click_x;        //鼠标点击位置
	float click_y;
	int player_type;      //区分客户端
	command() :use_flag(false), command_type(-1), connected(false), hero_type(-1), hero_attack(false), click_x(0.0), click_y(0.0), player_type(0) {}
};

#endif