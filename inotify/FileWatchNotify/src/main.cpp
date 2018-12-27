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
	unique_ptr<FileWatchNotify>ptr(new EsFileWatchNotify(config));
	ptr->Init();

	return 0;
}
