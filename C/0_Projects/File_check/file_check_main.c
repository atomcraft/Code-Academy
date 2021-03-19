/*
(11) Задача за проверка на файлове

1. Напишете програма, която по зададен път да проверява всички файлове във всички поддиректории под зададената. - DONE 
2. За всеки файл се записва: - STATUS: Printing info to CSV file DONE. Check CSV file format!
2.1 име, 
2.2 разширение, 
2.3 големина в байтове и 
2.4 контролна сума на съдържанието му. - MD5 Checksum - to integrate 
3. Цялата информация се записва в CSV файл. 
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>       /* flags for read and write   */
#include <sys/types.h>   /* typedefs                   */
#include <sys/stat.h>    /* structure returned by stat */
#include <dirent.h>
#include <libgen.h>

#define MAX_PATH 1024

static const char *FORMAT_CVS_HEADER = "Name, Extension, Size, NLink, Mode, Ino\n";
static const char *FORMAT_CVS_BODY = "%s, %s, %8ld, %3u, %6o, %5u\n";

void csvParser(struct stat *pStbuf, char *name);
char *getFileExt(const char *filename);
void stripExt(char *fname);

// extern int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

/* fsize: print inode #, mode, links, size of file "name" */
void fsize(char *name){
    struct stat stbuf;
    struct stat *pStbuf = NULL;
    pStbuf = (struct stat *)malloc(sizeof(*pStbuf));
    if (NULL == pStbuf){
        fprintf(stderr, "malloc: can't allocate memory for *pStbuf\n");
        return;
    }   

    if (stat(name, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR){
        dirwalk(name, fsize);
    }

    pStbuf = &stbuf;
    csvParser(pStbuf, name);

    printf("%5u %6o %3u %8ld %s\n", stbuf.st_ino, 
             stbuf.st_mode, stbuf.st_nlink, stbuf.st_size, name);
    printf("Last modified: %ld\n", stbuf.st_mtime);
    printf("File burthtime: %ld\n", stbuf)
}

int main(int argc, char **argv){
    if (argc == 1){ /* by default, work with the current directory */
        fsize(".");
    } else{
        while (--argc > 0){
            fsize(*++argv);
        }
    }
    return 0;    
}

void dirwalk(char *dir, void (*fcn)(char *)){ /* walks the directory and sub-directories */
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL){
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL){
        if (strcmp(dp->d_name, ".") == 0
            || strcmp(dp->d_name, "..") == 0){ /* skips current and parent directory */
            continue;
        }
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)){
            fprintf(stderr, "dirwalk: name %s %s too long\n", 
                dir, dp->d_name);
        } else{
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }       
    }
    closedir(dfd);  
}

void csvParser(struct stat *pStbuf, char *name){
    FILE *fp;
    static int counter = 0;
    char filename[255] = "file_check_log.csv";
    fp = fopen(filename, "a");
    if(NULL == fp){
        fprintf(stderr, "Failed to open file %s.\n");
        return;
    }
    if (counter == 0){
        fprintf(fp, FORMAT_CVS_HEADER);
        counter++;
    }
    char *bname;
    char *path2 = strdup(name);
    bname = basename(path2);
    char *fileNameExt = getFileExt(bname);
    stripExt(bname);
    fseek(fp, 0, SEEK_SET);
    fprintf(fp, FORMAT_CVS_BODY, bname, fileNameExt, pStbuf->st_size, pStbuf->st_nlink,
        pStbuf->st_mode, pStbuf->st_ino);
    // fscanf(fp, FORMAT_CVS_BODY, name, pStbuf->st_size, pStbuf->st_nlink,
    //     pStbuf->st_mode, pStbuf->st_ino);
    free(path2);
    fclose(fp);
}

char *getFileExt(const char *filename){
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

void stripExt(char *fname){
    char *end = fname + strlen(fname);

    while (end > fname && *end != '.') {
        --end;
    }

    if (end > fname) {
        *end = '\0';
    }
}
