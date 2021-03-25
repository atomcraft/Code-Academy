
#ifndef FILES_CHECK_H_
   #define FILES_CHECK_H_
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

   #define MAX_PATH 4096
   #define NAME_MAX 255
   #define CHAR_BUF 32
   #define MIN_REQUIRED_COMMAND_LINE_ARGS 3
   #define CSV_FILE_NAME "files_check_log.csv"
   /* iNotify Events buffers */
   #define EVENT_SIZE  ( sizeof (struct inotify_event) )
   #define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
   #define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

   /* CSV file formatting */
   static const char *FORMAT_CVS_HEADER = "Name, Extension, Size, Checksum, Inode\n";
   static const char *FORMAT_CVS_BODY = "%s, %s, %lld, %02x, %u\n"; 

   /* Lists program usage */
   int help();
   /* fsize: print inode #, (mode, links,) size of file "name" */
   void fsize(char *name);
   /* directory walker, alks the directory and sub-directories */
   void dirwalk(char *, void (*fcn)(char *));
   /* creates/modifies the CSV file list, compares and prints file info */
   void fileCheckInfoCsvParse(char *name, char *argv);
   /* returns the file extension */
   char *getFileExt(const char *filename);
   /* removes the file extension */
   void stripExt(char *filename);
   /* integer to char converter */
   char* itoa(int val, int base);   
   /* creates the checksum */
   unsigned int checksum (char *name); 
   /*creates the iNotify Event Watch */
   void iNotifyEventWatch(char *name);
   /* displays iNotify Events */
   static void displayInotifyEvent(struct inotify_event *i);

#endif /* FILES_CHECK_H_ */
