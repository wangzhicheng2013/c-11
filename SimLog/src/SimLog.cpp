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
	logpath = path;
	ofs.open(logpath.c_str(), ios::app | ios::out);
	if (!ofs.is_open())
	{
		cerr << logpath << " open failed...!" << endl;
		return false;
	}
	return true;
}
void SimLog::Log(const string &)
{

}
SimLog::~SimLog() {
	// TODO Auto-generated destructor stub
}
