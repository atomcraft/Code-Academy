/*
4. Допълнително програмата трябва да може:
4.1 да сравнява два файла с информация за файловете 
4.2 и да дава отчет: 
4.2.1 нови файлове, 
4.2.2 стари файлове променени, 
4.2.3 изтрити файлове, 
4.3 като за всеки файл трябва да се дава:
4.3.1 пълен път, 
4.3.2 име, 
4.3.3 разширение 
4.3.4 и размер.
*/
// #define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>       /* flags for read and write   */
#include <sys/types.h>   /* typedefs                   */
#include <sys/stat.h>    /* structure returned by stat */
#include <errno.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )


#ifdef HAVE_ST_BIRTHTIME
#define birthtime(x) x.st_birthtime
#else
#define birthtime(x) x.st_ctime
#endif

#define MAX_PATH 4096

void iNotifyEventWatch(char *name);

void fsize(char *name){
    struct stat stbuf;
    struct stat stbuf1;
    struct stat *pStbuf = NULL;
    pStbuf = (struct stat *)malloc(sizeof(*pStbuf));
    // if (NULL == pStbuf){
    //     fprintf(stderr, "malloc: can't allocate memory for *pStbuf\n");
    //     return;
    // }   

    if (stat(name, &stbuf) == -1 || stat(name, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    // if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR){
    //     dirwalk(name, fsize);
    // }

    // pStbuf = &stbuf;
    // csvParser(pStbuf, name);
    char *symlinkpath = name;
    char actualpath [MAX_PATH+1];
    char *ptr;
    ptr = realpath(name, NULL);
    printf("File full path: %s\n", ptr);
    printf("File name: %s\n", name);
    printf("File size: %ld bytes\n", stbuf.st_size);
    printf("File last modified: %ld\n", stbuf.st_mtime);
    printf("File last accessed: %ld\n", stbuf.st_atime);
    printf("File created: %ld\n", stbuf.st_ctime);
    printf("\n");


    // printf("%5u %6o %3u %8ld %s %s\n", stbuf.st_ino, 
    //          stbuf.st_mode, stbuf.st_nlink, stbuf.st_size, name, ptr);
    // printf("Last modified: %ld\n", stbuf.st_mtime);
    // printf("File birthtime: %ld\n", birthtime(stbuf));
}

int main(int argc, char **argv){
    if (argc == 1){
        printf("Usage: \n");
        printf("-f for file comparisson\n");
        printf("-i for file and directory modification watch."
               " If no directory is provided, the current one is used\n");
    } else{
        if (0 == strcmp(argv[1], "-f")){
            while (--argc > 0){
                fsize(*++argv);
            }
        } else if (0 == strcmp(argv[1], "-i")){
            if (argc == 2){
                iNotifyEventWatch(".");
            } else{
                iNotifyEventWatch(*++argv);
            }           
        }
    }
    
    // if (argc == 1){ /* by default, work with the current directory */
    //     fsize(".");
    // } else{
    //     while (--argc > 0){
    //         fsize(*++argv);
    //     }
    // }
    return 0;
}

void iNotifyEventWatch(char *name){
    int length, i = 0;
    int fd;
    int wd;
    char buffer[EVENT_BUF_LEN];
    /*creating the INOTIFY instance*/
    fd = inotify_init();/*checking for error*/
    if ( fd < 0 ){
        perror( "inotify_init" );
    }
    /*adding the “/tmp” directory into watch list. Here, the suggestion is to validate the existence of the directory before adding into monitoring list.*/
    wd = inotify_add_watch( fd, name, IN_CREATE | IN_DELETE );

    /*read to determine the event change happens on “/tmp” directory. Actually this read blocks until the change event occurs*/ 

    length = read(fd, buffer, EVENT_BUF_LEN); 

    /*checking for error*/
    if ( length < 0 ) {
        perror( "read" );
    }  

    /*actually read return the list of change events happens. Here, read the change event one by one and process it accordingly.*/
    while (i < length){
        struct inotify_event *event = (struct inotify_event *) &buffer[ i ];
        if ( event->len ){
            if (event->mask & IN_CREATE){
                if (event->mask & IN_ISDIR){
                    printf("New directory %s created.\n", event->name);
                } else{
                    printf("New file %s created.\n", event->name);
                }
            } else if (event->mask & IN_DELETE){
                if (event->mask & IN_ISDIR){
                    printf("Directory %s deleted.\n", event->name);
                } else{
                    printf( "File %s deleted.\n", event->name );
                }
            }
        }
        i += EVENT_SIZE + event->len;
    }
    /*removing the “/tmp” directory from the watch list.*/
    inotify_rm_watch(fd, wd);
    /*closing the INOTIFY instance*/
    close(fd);
}