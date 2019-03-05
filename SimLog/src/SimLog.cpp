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
	ofs.open(logpath.c_str(), ios::app | ios::out | ios::binary);
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
		tmp += line;
		tmp += "\n";
		if (++count >= BATCHLINES)
		{
			count = 0;
			ofs << tmp;
			tmp.clear();
		}
		if (ofs.tellp() >= SINGLE_FILESIZE)
		{
			ofs.close();
			ofs.open("./22.txt", ios::app | ios::out | ios::binary);
			if (!ofs.is_open())
			{
				cerr << "open failed...!" << endl;
				break;
			}
		}
	}
}
SimLog::~SimLog() {
	// TODO Auto-generated destructor stub
	if (WriteFileThread.joinable())
	{
		WriteFileThread.join();
	}
}
