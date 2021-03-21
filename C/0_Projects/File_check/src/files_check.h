
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>       /* flags for read and write   */
#include <sys/types.h>   /* typedefs                   */
#include <sys/stat.h>    /* structure returned by stat */
#include <dirent.h>
#include <libgen.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/inotify.h>
#include <openssl/md5.h>

#define MAX_PATH 4096
#define NAME_MAX 255
#define MIN_REQUIRED_COMMAND_LINE_ARGS 2
#define CSV_FILE_NAME "files_check_log.csv"
/* iNotify Events buffers */
#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

/* CSV file formatting */
static const char *FORMAT_CVS_HEADER = "Name, Extension, Size, Checksum, Inode\n";
static const char *FORMAT_CVS_BODY = "%s, %s, %lld, %02x, %u\n"; 

/* creates the CSV file list */
void csvParser(struct stat *pStbuf, char *name);
/* checks if file is already in the CSV list, if not adds it, if yes shows info */
void csvFileModificationCheck(char *name);
/* returns the file extension */
char *getFileExt(const char *filename);
/* removes the file extension */
void stripExt(char *fname);
/* integer to char converter */
char* itoa(int val, int base);
/* directory walker, alks the directory and sub-directories */
void dirwalk(char *, void (*fcn)(char *));
/* creates the MD5 checksum */
char *md5Checksum(char *name);
/* fsize: print inode #, mode, links, size of file "name" */
void fsize(char *name);
/*creates the iNotify Event Watch */
void iNotifyEventWatch(char *name);
/* displays iNotify Events */
static void displayInotifyEvent(struct inotify_event *i);
/* compares files */
void fileInfo(char *name);
/* Lists program usage */
int help();