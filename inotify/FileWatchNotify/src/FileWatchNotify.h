/*
 * FileWatchNotify.h
 *
 *  Created on: 2018-11-28
 *      Author: root
 */

#ifndef FILEWATCHNOTIFY_H_
#define FILEWATCHNOTIFY_H_
#include "FileWatchNotifyConfig.h"
#include <unistd.h>
#include <stdlib.h>
#include <event.h>
#include <event2/event.h>
#include <iostream>
class FileWatchNotify {
public:
	FileWatchNotify(const FileWatchNotifyConfig &);
	virtual ~FileWatchNotify();
public:
	virtual bool Init();
	virtual void DoNotify() = 0;
private:
	bool InitInNotify();
	bool InitLibEvent();
	void RemoveInotify();
	void DestoryLibEvent();
private:
	static void NotifyCallBackFn(int, short, void *);
    static void NotifyCallBackFn_LogicJudge(FileWatchNotify *self, struct inotify_event *event);
private:
	int inotify_fd;
	int watch_fd;
private:
	struct event_base *ev_base;
private:
	const FileWatchNotifyConfig &config;
private:
	static const int EVENT_SIZE = sizeof(struct inotify_event);
	static const int BUF_LEN = 1024 * (EVENT_SIZE + 16);
};

#endif /* FILEWATCHNOTIFY_H_ */
