/*
 * EsFileWatchNotify.h
 *
 *  Created on: 2018-11-28
 *      Author: root
 */

#ifndef ESFILEWATCHNOTIFY_H_
#define ESFILEWATCHNOTIFY_H_

#include "FileWatchNotify.h"

class EsFileWatchNotify: public FileWatchNotify {
public:
	EsFileWatchNotify(const FileWatchNotifyConfig &);
	virtual ~EsFileWatchNotify();
public:
	virtual bool Init() override;
	virtual void DoNotify() override;
private:
	const FileWatchNotifyConfig &config;
};

#endif /* ESFILEWATCHNOTIFY_H_ */
