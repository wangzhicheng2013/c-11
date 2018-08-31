/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-29
Description:message handler class to handle output message
ChangeLog:
			1. create this file
**************************************************/

#ifndef OUTPUTMSGHANDLER_H_
#define OUTPUTMSGHANDLER_H_
#include "MessageHandler.h"
#include <iostream>
using namespace std;
class OutputMsgHandler : public MessageHandler
{
public:
	OutputMsgHandler();
	OutputMsgHandler(const OutputMsgHandler &) = delete;
	OutputMsgHandler & operator = (const OutputMsgHandler &) = delete;
	virtual bool Handler() override;
	virtual ~OutputMsgHandler();

};

#endif /* INPUTMSGHANDLER_H_ */
