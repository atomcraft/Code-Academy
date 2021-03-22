#include "files_check.h"

/* Lists program usage */
int help(){
    printf("Usage: \n");
    printf("\tfiles_check.out [-c ] <path/directory> or <file>\n");
    printf("\t-c: creates CSV file list with file name, extension, size, MD5 checksum. iNode\n\n");
    printf("\tfiles_check.out [-fc ] <file>\n");
    printf("\t-fc: checks if the file/s is included in the CSV file, if not it adds it. It shows last modification time, last access time, full path, name, extension, size\n\n");
    printf("\tfiles_check.out [-e ] optional: <path/directory> or <file>\n");
    printf("\t-e: enters events watch mode, show modifications, access as it happens. Press Ctrl+C to terminate\n\n");
    printf("\tfiles_check.out [-f ] <file1> <file2>\n");
    printf("\t-f: shows/compares 2 files, their last modification/creation/access time, full path, name, extension, size\n\n");
    return 1;
}

/* fsize: print inode #, (mode, links,) size of file "name" */
void fsize(char *name){
    struct stat stbuf;
    static int flag = 0;

    if (stat(name, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR){
        dirwalk(name, fsize);
    }

    fileCheckInfoCsvParse(name, "c");

    if (flag == 0){
        printf("iNode");
        printf("\tSize");
        printf("\tName");
        printf("\n");
        flag = 1; 
    }

    printf("%lu\t%ld\t%s\n", stbuf.st_ino, stbuf.st_size, name);
}

/* walks the directory and sub-directories */
void dirwalk(char *dir, void (*fcn)(char *)){ 
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

/* creates/modifies the CSV file list, compares and prints file info */
void fileCheckInfoCsvParse(char *name, char *argv){
    int initFlag = 0; /* 0 for "-c"; 1 for "-f", 2 for "-fc"; */
    int fileEnteredInCSV = 0;
    char buff[CHAR_BUF];
    struct tm * timeinfo;
    struct stat stbuf;
    static int flag = 0;
    unsigned int chkSum = 0;
    /* checks if file/directory exists */
    if(access(name, F_OK) != 0){
        fprintf(stderr, "file/directory: %s doesn't exist\n", name);
        return;
    }

    if (stat(name, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }


    if ((0 == strcmp(argv, "-f"))){
        initFlag = 1;
    }

    if ((0 == strcmp(argv, "-fc"))){
        initFlag = 2;
    }

    chkSum = checksum(name);  

    struct stat *csvStbuf = NULL;
    csvStbuf = (struct stat *)malloc(sizeof(*csvStbuf));
    if (NULL == csvStbuf){
        fprintf(stderr, "malloc: can't allocate memory for *csvStbuf\n");
        return;
    }

    FILE *fp;
    fp = fopen(CSV_FILE_NAME, "a+");
    if (NULL == fp){
        fprintf(stderr, "Failed to open file %s.\n");
        return;
    }

    if ((initFlag == 2)){
        /* checks, by comparing inode, if the file is already in the CSV list */
        char *search = itoa(stbuf.st_ino, 10);
        printf("INODE: %s\n", search);
        char line[MAX_PATH];
        while (fgets(line, sizeof(line), fp)){
            if (strstr(line, search)){
                printf("File found in CSV: %s", line);
                fileEnteredInCSV = 1;
            }
        }
    }

    char *ptr;
    ptr = realpath(name, NULL);
    char *bname;
    char *path2 = strdup(name);
    /* strips the path */
    bname = basename(path2);
    char *fileNameExt = getFileExt(bname);
    stripExt(bname);
    
    if((initFlag == 0) && (flag == 0)){
        /* if 1st write to CSV, fprint the HEADER */
        fprintf(fp, FORMAT_CVS_HEADER);
        flag++;
    }

    if (initFlag == 0){
        fseek(fp, 0, SEEK_SET);
        fprintf(fp, FORMAT_CVS_BODY, bname, fileNameExt, stbuf.st_size, chkSum, stbuf.st_ino);
        free(path2);
        free(ptr);
        free(csvStbuf);
        fclose(fp);
        return;
    }    

    if ((fileEnteredInCSV == 0) && (initFlag == 2)){
        printf("The file is not in the CSV file. Entering...\n");
        fseek(fp, 0, SEEK_SET);
        fprintf(fp, FORMAT_CVS_BODY, bname, fileNameExt, stbuf.st_size, chkSum, stbuf.st_ino);
    }

    /* printing file info */
    printf("File full path: %s\n", ptr);
    printf("File name: %s\n", bname);
    printf("File extension: %s\n", fileNameExt);
    printf("File size: %ld bytes\n", stbuf.st_size);
    /* time conversion */
    timeinfo = localtime (&stbuf.st_ctime);
    strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
    printf("File last status change on: %s\n", buff);
    timeinfo = localtime (&stbuf.st_mtime);
    strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
    printf("File last modified on: %s\n", buff);
    timeinfo = localtime (&stbuf.st_atime);
    strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
    printf("File last accessed on: %s\n", buff);
    printf("Checksum: %02x\n", chkSum);
    printf("\n");
    free(path2);
    free(ptr);
    free(csvStbuf);
    fclose(fp);
}

/* returns the file extension */
char *getFileExt(const char *filename){
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

/* removes the file extension */
void stripExt(char *fname){
    char *end = fname + strlen(fname);
    while (end > fname && *end != '.') {
        --end;
    }
    if (end > fname) {
        *end = '\0';
    }
}

/* integer to char converter */
char* itoa(int val, int base){
	static char buf[CHAR_BUF] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base){
        buf[i] = "0123456789abcdef"[val % base];
    }
	return &buf[i+1];
}
