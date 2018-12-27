/*
 * FileWatchNotifyConfig.cpp
 *
 *  Created on: 2018-11-28
 *      Author: root
 */

#include "FileWatchNotifyConfig.h"

FileWatchNotifyConfig::FileWatchNotifyConfig()
{
	// TODO Auto-generated constructor stub
	watch_event = MODIFIED | CREATE | DELETE | ACCESS | MOVED_FROM | MOVED_TO;
}

FileWatchNotifyConfig::~FileWatchNotifyConfig()
{
	// TODO Auto-generated destructor stub
}
