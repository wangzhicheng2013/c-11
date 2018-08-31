/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-28
Description:message handler class
ChangeLog:
			1. create this file
**************************************************/
#ifndef MESSAGEHANDLER_H_
#define MESSAGEHANDLER_H_

class MessageHandler
{
public:
	virtual bool Handler() = 0;
	virtual ~MessageHandler()
	{
	}

};
#endif /* MESSAGEHANDLER_H_ */
