/*
 * EsFileWatchNotify.cpp
 *
 *  Created on: 2018-11-28
 *      Author: root
 */

#include "EsFileWatchNotify.h"

EsFileWatchNotify::EsFileWatchNotify(const FileWatchNotifyConfig &_config) : FileWatchNotify(_config), config(_config)
{
	// TODO Auto-generated constructor stub

}
bool EsFileWatchNotify::Init()
{
	return FileWatchNotify::Init();
}
void EsFileWatchNotify::DoNotify()
{
	cout << "es secrete file changed" << endl;
}
EsFileWatchNotify::~EsFileWatchNotify()
{
	// TODO Auto-generated destructor stub
}
