/*
 * FileWatchNotifyConfig.h
 *
 *  Created on: 2018-11-28
 *      Author: root
 */

#ifndef FILEWATCHNOTIFYCONFIG_H_
#define FILEWATCHNOTIFYCONFIG_H_
#include <sys/inotify.h>
#include <string>
using namespace std;
typedef enum WatchEvent
{
	CREATE = IN_CREATE,
	DELETE = IN_DELETE,
	MODIFIED = IN_MODIFY,
	ACCESS = IN_ACCESS,
    MOVED_FROM = IN_MOVED_FROM,
    MOVED_TO = IN_MOVED_TO
}WatchEvent;
class FileWatchNotifyConfig {
public:
	FileWatchNotifyConfig();
	virtual ~FileWatchNotifyConfig();
public:
	string watch_dir;
	string watch_file;
	int watch_event;

};

#endif /* FILWWATCHNOTIFY_H_ */
