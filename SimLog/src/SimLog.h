/*
 * SimLog.h
 *
 *  Created on: 2019-3-1
 *      Author: root
 */

#ifndef SIMLOG_H_
#define SIMLOG_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include "blockingconcurrentqueue.h"
using namespace std;
using namespace moodycamel;
class SimLog {
public:
	static SimLog & GetInstance()
	{
		return simlog;
	}
public:
	bool Init(const string &);
	void Log(const string &);
private:
	SimLog();
	virtual ~SimLog();
private:
	void WriteFile();
	bool AddNewLogFile();
	inline void GetNewLogPath()
	{
		log_files_count = (log_files_count + 1) % MAX_LOG_FILES_COUNT;
		if (0 != log_files_count)
		{
			snprintf(log_file_path, sizeof(log_file_path), "%s.%d", logpath.c_str(), log_files_count);
		}
		else
		{
			snprintf(log_file_path, sizeof(log_file_path), "%s", logpath.c_str());
		}
	}
private:
	thread WriteFileThread;
	BlockingConcurrentQueue<string>queueForLine;
private:
	const int BATCHLINES = 100;
	const int SINGLE_FILESIZE = 1024; // 1k
	const int MAX_LOG_FILES_COUNT = 3;
private:
	int log_files_count;
	char log_file_path[128];
private:
	string logpath;
	ofstream ofs;
private:
	static SimLog simlog;


};

#endif /* SIMLOG_H_ */
