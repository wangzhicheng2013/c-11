/*
 * SimLog.h
 *
 *  Created on: 2019-3-1
 *      Author: root
 */

#ifndef SIMLOG_H_
#define SIMLOG_H_
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
private:
	thread WriteFileThread;
	BlockingConcurrentQueue<string>queueForLine;
private:
	const int BATCHLINES = 100;
private:
	string logpath;
	ofstream ofs;
private:
	static SimLog simlog;


};

#endif /* SIMLOG_H_ */
