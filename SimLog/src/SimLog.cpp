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
	log_files_count = 0;
	memset(log_file_path, 0, sizeof(log_file_path));
}
bool SimLog::Init(const string &path)
{
	if (!path.empty())
	{
		logpath = path;
	}
	ofs.open(logpath.c_str(), ios::out | ios::app);
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
bool SimLog::AddNewLogFile()
{
	ofs.close();
	GetNewLogPath();
	remove(log_file_path);
	ofs.open(log_file_path, ios::out | ios::app);
	if (!ofs.is_open())
	{
		ofs.close();
		cerr << log_file_path << " open failed...!" << endl;
		return false;
	}
	//ofs.seekp(ios::beg);
	return true;
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
		if (ofs.tellp() >= SINGLE_FILESIZE && !tmp.empty())
		{
			if (false == AddNewLogFile())
			{
				break;
			}
			ofs << tmp;
			tmp.clear();
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
