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
using namespace std;
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
	string logpath;
	ofstream ofs;
private:
	static SimLog simlog;


};

#endif /* SIMLOG_H_ */
