#include "files_check.h"

void fileInfo(char *name){
    char buff[20];
    struct tm * timeinfo;
    struct stat stbuf;
    if (stat(name, &stbuf) == -1){
        fprintf(stderr, "fileInfo: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR){
        fprintf(stderr, "directory: cannot compare directories\n");
        return;
    }
    char *ptr;
    ptr = realpath(name, NULL);
    printf("File full path: %s\n", ptr);
    printf("File name: %s\n", name);
    printf("File size: %ld bytes\n", stbuf.st_size);

    timeinfo = localtime (&stbuf.st_ctime);
    strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
    printf("File created on: %s\n", buff);
    timeinfo = localtime (&stbuf.st_mtime);
    strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
    printf("File last modified on: %s\n", buff);
    timeinfo = localtime (&stbuf.st_atime);
    strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
    printf("File last accessed on: %s\n", buff);
    printf("\n");
    free(ptr);
}


void iNotifyEventWatch(char *path){
    int inotifyFd, wd, j;
    char buf[BUF_LEN] __attribute__ ((aligned(8)));
    ssize_t numRead;
    char *p;
    struct inotify_event *event;

    /* Create inotify instance */
    inotifyFd = inotify_init();   
    if (inotifyFd == -1){
        fprintf(stderr, "inotify_init: failed!");
        exit(-1);
    }

    /* For each command-line argument, add a watch for all events */

    wd = inotify_add_watch(inotifyFd, path, IN_ALL_EVENTS);
        if (wd == -1){
            fprintf(stderr, "inotify_add_watch: failed!");
            exit(-1);
        }

        printf("Watching %s using wd %d\n", path, wd);

    for (;;) { 
        numRead = read(inotifyFd, buf, BUF_LEN);
        if (numRead == 0){
            fprintf(stderr, "read: from inotify fd returned 0!");
            exit(-1);
        }

        if (numRead == -1){
            fprintf(stderr, "read: failed!");
            exit(-1);
        }

        /*FIXME: should use %zd here, and remove (long) cast */
        printf("Read %zd bytes from inotify fd\n", numRead);

        /* Process all of the events in buffer returned by read() */
        for (p = buf; p < buf + numRead; ) {
            event = (struct inotify_event *) p;
            displayInotifyEvent(event);

            p += sizeof(struct inotify_event) + event->len;
        }
    }

    exit(EXIT_SUCCESS);
}

/* Display information from inotify_event structure */
static void displayInotifyEvent(struct inotify_event *i){
    printf("    wd =%2d; ", i->wd);
    if (i->cookie > 0)
        printf("cookie =%4d; ", i->cookie);

    printf("mask = ");
    if (i->mask & IN_ACCESS)        printf("IN_ACCESS ");
    if (i->mask & IN_ATTRIB)        printf("IN_ATTRIB ");
    if (i->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE ");
    if (i->mask & IN_CLOSE_WRITE)   printf("IN_CLOSE_WRITE ");
    if (i->mask & IN_CREATE)        printf("IN_CREATE ");
    if (i->mask & IN_DELETE)        printf("IN_DELETE ");
    if (i->mask & IN_DELETE_SELF)   printf("IN_DELETE_SELF ");
    if (i->mask & IN_IGNORED)       printf("IN_IGNORED ");
    if (i->mask & IN_ISDIR)         printf("IN_ISDIR ");
    if (i->mask & IN_MODIFY)        printf("IN_MODIFY ");
    if (i->mask & IN_MOVE_SELF)     printf("IN_MOVE_SELF ");
    if (i->mask & IN_MOVED_FROM)    printf("IN_MOVED_FROM ");
    if (i->mask & IN_MOVED_TO)      printf("IN_MOVED_TO ");
    if (i->mask & IN_OPEN)          printf("IN_OPEN ");
    if (i->mask & IN_Q_OVERFLOW)    printf("IN_Q_OVERFLOW ");
    if (i->mask & IN_UNMOUNT)       printf("IN_UNMOUNT ");
    printf("\n");

    if (i->len > 0)
        printf("        name = %s\n", i->name);
}