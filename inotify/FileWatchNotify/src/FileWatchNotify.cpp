/*
 * FileWatchNotify.cpp
 *
 *  Created on: 2018-11-28
 *      Author: root
 */

#include "FileWatchNotify.h"

FileWatchNotify::FileWatchNotify(const FileWatchNotifyConfig &_config) : config(_config)
{
	// TODO Auto-generated constructor stub
	inotify_fd = -1;
	watch_fd = -1;
	ev_base = nullptr;
}
bool FileWatchNotify::Init()
{
	if (!InitInNotify())
	{
		return false;
	}
	if (!InitLibEvent())
	{
		return false;
	}
	return true;
}
bool FileWatchNotify::InitInNotify()
{
	inotify_fd = inotify_init();
	if (inotify_fd < 0)
	{
		cerr << "inotify_init() failed...!" << endl;
		return false;
	}
	watch_fd = inotify_add_watch(inotify_fd, config.watch_dir.c_str(), config.watch_event);
	if (watch_fd < 0)
	{
		cerr << "inotify_add_watch failed...!" << endl;
		return false;
	}
	return true;
}
bool FileWatchNotify::InitLibEvent()
{
	 ev_base = event_base_new();
	 if (nullptr == ev_base)
	 {
		 cerr << "event_base_new() failed...!" << endl;
		 return false;
	 }
	 struct event *event = event_new(ev_base,
			 inotify_fd,
			 EV_READ | EV_PERSIST,
			 NotifyCallBackFn,
			 this);
	 if (nullptr == event)
	 {
		 cerr << "event_new() failed...!" << endl;
		 return false;
	 }
	 event_add(event, NULL);
	 event_base_dispatch(ev_base);
}
void FileWatchNotify::NotifyCallBackFn(int fd, short events, void *arg)
{
	char buffer[BUF_LEN] = "";
	int length = read(fd, buffer, BUF_LEN);
	if (length < 0)
	{
        cerr << "read none" << endl;
	}
	int i = 0;
	struct inotify_event *event = nullptr;
	FileWatchNotify *self = reinterpret_cast<FileWatchNotify *>(arg);
	if (nullptr == self)
	{
		cerr << "self is none" << endl;
		return;
	}
	while (i < length)
	{
		event = (struct inotify_event *)&buffer[i];
		if (event->len <= 0)
		{
			cerr << "event->len <= 0" << endl;
			return;
		}
		if (event->mask & self->config.watch_event)
		{
			if (!(event->mask & IN_ISDIR))
			{
				if (self->config.watch_file == event->name)
				{
					self->DoNotify();
				}
			}
		}
		i += EVENT_SIZE + event->len;
	}
}
void FileWatchNotify::RemoveInotify()
{
	if (inotify_rm_watch(inotify_fd, watch_fd) < 0)
	{
		cerr << "inotify_rm_watch() failed...!" << endl;
	}
	else
	{
		watch_fd = -1;
	}
	if (inotify_fd >= 0)
	{
		close(inotify_fd);
		inotify_fd = -1;
	}
}
void FileWatchNotify::DestoryLibEvent()
{
	if (nullptr != ev_base)
	{
		event_base_loopexit(ev_base, NULL);
		event_base_free(ev_base);
		ev_base = nullptr;
	}
}
FileWatchNotify::~FileWatchNotify()
{
	// TODO Auto-generated destructor stub
	RemoveInotify();
	DestoryLibEvent();
}