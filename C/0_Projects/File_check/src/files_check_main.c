/*
(11) Задача за проверка на файлове

1. Напишете програма, която по зададен път да проверява всички файлове във всички поддиректории под зададената.  
2. За всеки файл се записва:
2.1 име, 
2.2 разширение, 
2.3 големина в байтове и 
2.4 контролна сума на съдържанието му.  
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

#include "files_check.h"

/* gcc src/files_check_func.c src/event_watch_file_state_comp.c src/files_check_main.c src/checksum.c -o files_check.out */

int main(int argc, char **argv){
    if (argc < MIN_REQUIRED_COMMAND_LINE_ARGS){
        return help();
    }
    /* iterate over all arguments */
    for (int i = 1; i < (argc - 1); i++){
        if ((0 == strcmp(argv[1], "-c"))){
            fsize(argv[++i]);
            continue;
        } else if ((0 == strcmp(argv[1], "-fc"))){
            if(access(CSV_FILE_NAME, F_OK) == 0){
                while (--argc > 1){
                    fileCheckInfoCsvParse(argv[++i], argv[1]);
                    continue;
                }
            } else{
                while (--argc > 1){
                    fileCheckInfoCsvParse(argv[++i], argv[1]);
                    continue;
                }
            }
        } else if ((0 == strcmp(argv[1], "-e"))){
            iNotifyEventWatch(argv[++i]);
            continue;
        } else if ((0 == strcmp(argv[1], "-f"))){
            while (--argc > 1){
                fileCheckInfoCsvParse(argv[++i], argv[1]);
                continue;   
            }            
        } else{
            return help();
        }      
    }
    return 0;
}
