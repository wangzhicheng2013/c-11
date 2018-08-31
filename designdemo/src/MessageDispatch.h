/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-29
Description:message handler class to dispatch message
ChangeLog:
			1. create this file
**************************************************/

#ifndef MESSAGEDISPATCH_H_
#define MESSAGEDISPATCH_H_
#include <unordered_map>
#include "InputMsgHandler.h"
#include "OutputMsgHandler.h"
using namespace std;
enum MSGTYPE
{
	INPUTMSG,
	OUTPUTMSG,
	OTHERMSG
};
class MessageDispatch
{
public:
	/*
	 * @purpose:register message and its handler
	 * */
	void RegisterMsg(MSGTYPE message, MessageHandler *handler);
	/*
	 *  @purpose:dispatch message with handler
	 * */
	void DispatchMsg(MSGTYPE message);
private:
		unordered_map<unsigned char, MessageHandler *>msg_mapper;
};

#endif /* MESSAGEDISPATCH_H_ */
