// void fileInfo(char *name, char *argv){
//     if ((0 == strcmp(argv[1], "-f"))){
//         /* code */
//     }
    
//     char buff[CHAR_BUF];
//     struct tm * timeinfo;
//     struct stat stbuf;
//     if (stat(name, &stbuf) == -1){
//         fprintf(stderr, "fileInfo: can't access %s\n", name);
//         return;
//     }
//     if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR){
//         fprintf(stderr, "directory: cannot compare directories\n");
//         return;
//     }
//     char *ptr;
//     ptr = realpath(name, NULL);
//     printf("File full path: %s\n", ptr);
//     printf("File name: %s\n", name);
//     printf("File size: %ld bytes\n", stbuf.st_size);

//     timeinfo = localtime (&stbuf.st_ctime);
//     strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
//     printf("File created on: %s\n", buff);
//     timeinfo = localtime (&stbuf.st_mtime);
//     strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
//     printf("File last modified on: %s\n", buff);
//     timeinfo = localtime (&stbuf.st_atime);
//     strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
//     printf("File last accessed on: %s\n", buff);
//     printf("\n");
//     free(ptr);
// }