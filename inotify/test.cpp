#include <sys/inotify.h>
ii12






#include <event.h>
#include <event2/event.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <event.h>
#include <event2/event.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
static const int mask = IN_ACCESS | IN_MODIFY;
  
void watch_notify_events(int fd, short events, void *arg)
{
    printf("laile\n");
    char buf[512];
    int rc;
    struct inotify_event *inotify_ev = NULL;
    rc = read(fd, buf, sizeof(buf));
    if (rc < 0)
    {
        puts("LL\n");
        return;
    }
    cout << rc << endl;
    inotify_ev = (struct inotify_event *)buf;
    if (inotify_ev == NULL)
    {
        return;
    }
    if (inotify_ev->mask & mask)
    {
        printf("file modifiy\n");
    }
}
int main(int argc, char **argv)
{
    int inotify_fd;
    int wd;
    int rc;
    int mask = IN_ACCESS | IN_MODIFY;
    struct event_base *ev_base;
    struct event *event;
    inotify_fd = inotify_init();
    if (inotify_fd < 0) 
    {
        printf("init inotify error\n");
        return 0;
    }
    wd = inotify_add_watch(inotify_fd, argv[1], mask);
    printf("%s\n", argv[1]);
    ev_base = event_base_new();
    event = event_new(ev_base, inotify_fd, EV_READ | EV_PERSIST, watch_notify_events, NULL);
    event_add(event, NULL);
    event_base_dispatch(ev_base);
    rc = inotify_rm_watch(inotify_fd, wd);
    if (rc < 0) 
    {
        printf("remove file error\n");
        return 0;
    }
    close(inotify_fd);
    return 0;
}
