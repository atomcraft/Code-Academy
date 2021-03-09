/*
Задача 16.
Напишете програма, която премахва от файл номер на ред и
премахва този ред от файла. (Hint: Не трийте от оригиналния файл, а
запишете съдържанието на файла без конкретния ред в друг файл).
*/

#include <stdio.h>
#include <string.h>

#define MAX 256

int main(void){
    int lno, ctr = 0;
    char ch;
    FILE *ifp, *ofp;
	char fname[] = "test6.txt";
    char str[MAX], temp[] = "temp.txt";		
    ifp = fopen(fname, "r");
    if(NULL == ifp){
        printf("Failed to open fail.\n");
        return 1;
    }
    ofp = fopen(temp, "wt");  
    if(NULL == ifp){
        printf("Failed to open fail.\n");
        return 1;
    }
    printf(" Input the line you want to remove : ");
    scanf("%d", &lno);
	lno++;
    // copy all contents to the temporary file except the specific line
    while (!feof(ifp)){
        strcpy(str, "\0");
        fgets(str, MAX, ifp);
        if (!feof(ifp)){
            ctr++;
            /* skip the line at given line number */
            if (ctr != lno){
                fprintf(ofp, "%s", str);
            }
        }
    }
        fclose(ifp);
        fclose(ofp);
        remove(fname);  		/* remove the original file */ 
        rename(temp, fname); 	/* rename the temporary file to original name */
/*------ Read the file ----------------*/
    ifp = fopen(fname,"r");
    ch = fgetc(ifp); 
    printf(" Now the content of the file %s is : \n",fname); 
    while(ch != EOF){
        printf("%c",ch);
        ch=fgetc(ifp); 
    }
    fclose(ifp);
/*------- End of reading ---------------*/
    return 0;

} 