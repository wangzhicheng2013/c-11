/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-29
Description:message handler class to dispatch message
ChangeLog:
			1. create this file
**************************************************/
#include "MessageDispatch.h"
/*
 * @purpose:register message and its handler
 * */
void MessageDispatch::RegisterMsg(MSGTYPE message, MessageHandler *handler)
{
	msg_mapper.insert(make_pair(message, handler));
}
/*
 *  @purpose:dispatch message with handler
 * */
void MessageDispatch::DispatchMsg(MSGTYPE message)
{
	auto it = msg_mapper.find(message);
	if (it == end(msg_mapper))
	{
		return;
	}
	it->second->Handler();
}
