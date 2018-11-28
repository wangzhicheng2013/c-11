/*
 * main.cpp
 *
 *  Created on: 2018-11-28
 *      Author: root
 */
#include "EsFileWatchNotify.h"
#include <memory>
int main()
{
	FileWatchNotifyConfig config;
	config.watch_dir = "./";
	config.watch_file = "11.txt";
	config.watch_event = MODIFIED;
	unique_ptr<FileWatchNotify>ptr(new EsFileWatchNotify(config));
	ptr->Init();

	return 0;
}
