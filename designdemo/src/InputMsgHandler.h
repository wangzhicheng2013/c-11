/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-28
Description:message handler class to handle input message
ChangeLog:
			1. create this file
**************************************************/

#ifndef INPUTMSGHANDLER_H_
#define INPUTMSGHANDLER_H_
#include "MessageHandler.h"
#include <iostream>
using namespace std;
class InputMsgHandler : public MessageHandler
{
public:
	InputMsgHandler();
	InputMsgHandler(const InputMsgHandler &) = delete;
	InputMsgHandler & operator = (const InputMsgHandler &) = delete;
	virtual bool Handler() override;
	virtual ~InputMsgHandler();

};

#endif /* INPUTMSGHANDLER_H_ */
