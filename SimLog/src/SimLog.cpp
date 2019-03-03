/*
 * SimLog.cpp
 *
 *  Created on: 2019-3-1
 *      Author: root
 */

#include "SimLog.h"
SimLog SimLog::simlog;
SimLog::SimLog() {
	// TODO Auto-generated constructor stub
	logpath = "./tmp.log";
}
bool SimLog::Init(const string &path)
{
	if (!path.empty())
	{
		logpath = path;
	}
	ofs.open(logpath.c_str(), ios::app | ios::out);
	if (!ofs.is_open())
	{
		cerr << logpath << " open failed...!" << endl;
		return false;
	}
	try
	{
		WriteFileThread = thread(bind(&SimLog::WriteFile, this));
	}
	catch(...)
	{
		return false;
	}
	return true;
}
void SimLog::Log(const string &str)
{
	queueForLine.enqueue(str);
}
void SimLog::WriteFile()
{
	string line;
	string tmp;
	int count = 0;
	while (true)
	{
		queueForLine.wait_dequeue(line);
		tmp = line;
		tmp += "\n";
		if (++count >= BATCHLINES)
		{
			count = 0;
			tmp.clear();
			ofs << tmp;
		}
		if (0 == queueForLine.size_approx())
		{
			if (!tmp.empty())
			{
				ofs << tmp;
				tmp.clear();
			}
		}
	}
}
SimLog::~SimLog() {
	// TODO Auto-generated destructor stub
	ofs.close();
	if (WriteFileThread.joinable())
	{
		WriteFileThread.join();
	}
}
