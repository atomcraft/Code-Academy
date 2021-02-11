/*
Задача 3. Използвайте Задача 1. за да напишете програма, която
проверява дали съобщението не е палиндром. Палиндром е съобщение, в
което буквите от ляво на дясно са същите като от дясно на ляво.
I did, did I?
*/

#include <stdio.h>
#include <string.h>
#define SIZE 1000
 
int main()
{
    char s[SIZE];  
    int i,n,c=0;
 
    printf("Enter the string : ");
    scanf("%s", &s);
    getchar();
    n=strlen(s);
    for(i=0;i<n/2;i++)  
    {
    	if(s[i]==s[n-i-1])
    	c++;
 	}
 	if(c==i)
 	    printf("string is palindrome");
    else
        printf("string is not palindrome");
 
 	 
     
    return 0;
}