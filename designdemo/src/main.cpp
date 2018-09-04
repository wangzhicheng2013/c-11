/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-04
Description:program main entry
ChangeLog:
			1. create this file
**************************************************/

#include "MessageDispatch.h"
#include "ThreadPool.h"
#include "PrintTask.h"
#include "StringBeads.h"
int TestThreadPool()
{
	InputMsgHandler inputMsgHandler;
	OutputMsgHandler outputMsgHandler;
	MessageDispatch messageDispatch;
	messageDispatch.RegisterMsg(INPUTMSG, &inputMsgHandler);
	messageDispatch.RegisterMsg(OUTPUTMSG, &outputMsgHandler);
	messageDispatch.DispatchMsg(INPUTMSG);
	messageDispatch.DispatchMsg(OUTPUTMSG);
	ThreadPool threadpool;
	if (!threadpool.Init(2))
	{
		cerr << "thread pool init failed..." << endl;
		return -1;
	}
	for (int i = 0;i < 2;i++)
	{
		PrintTask *task = new PrintTask;
		threadpool.AddTask(task);
	}
	return 0;
}
void TestStringBeads()
{
	StringBeads stringBeads(2);
	vector<pair<int, Beads> >vec = {
			make_pair(1, (Beads){1}),
			make_pair(2, (Beads){1, 3, 4}),
			make_pair(3, (Beads){1, 3, 5})
	};
	stringBeads.Init(vec);
	cout << stringBeads.GetCountOfInValidColors() << endl;
}
int main()
{
	TestStringBeads();

	return 0;
}
